#include "essaybim_test_layer.h"

#include "essaybim_application.h"
#include "essaybim_module_init.h"

#include "command_undo_manager.h"
#include "basic_file_server.h"
#include "database_geometry_object.h"
#include "database_geometry_database.h"
#include "database_object.h"
#include "document_interactive_camera.h"
#include "event_event_dispatcher.h"
#include "event_key_event.h"
#include "event_keycode_defines.h"
#include "geometry_arithmetic.h"
#include "geometry_circle_2d.h"
#include "geometry_circle_3d.h"
#include "geometry_line_2d.h"
#include "geometry_line_3d.h"
#include "geometry_plane.h"
#include "geometry_mesh.h"
#include "geometry_utils.h"
#include "geometry_matrix_2d.h"
#include "gui_dock_space.h"
#include "gui_drag_value_input.h"
#include "gui_list_box.h"
#include "gui_image_widget.h"
#include "gui_panel.h"
#include "gui_text.h"
#include "gui_button.h"
#include "gui_menu_bar.h"
#include "renderer_vertex_array.h"
#include "renderer_vertex_buffer.h"
#include "renderer_index_buffer.h"
#include "renderer_shader.h"
#include "renderer_buffer_layout.h"
#include "renderer_graphics_context.h"
#include "renderer_entry.h"
#include "renderer_shader_library.h"
#include "renderer_texture.h"
#include "renderer_frame_buffer.h"
#include "renderer_uniform_buffer.h"
#include "renderer_batch_render.h"
#include "window_window.h"
#include "command_scheduler.h"


namespace EB
{
    namespace
    {
        struct CameraData
        {
            Mat4 ViewProjectionMatrix;
        };
        CameraData cameraData;
    }

    TestLayer::TestLayer()
        : Layer()
    {
        
    }

    void TestLayer::onAttach()
    {
        camera = createShared<InteractiveCamera>(Window::instance("DemoApp").get(), 45.f, 1.5f, 0.1f, 1000.f);

        FrameBufferSpecification spec;
        spec.Width = 1500;
        spec.Height = 1000;
        spec.Attachments = {
            eFrameBufferTextureFormat::kRGBA8,
            eFrameBufferTextureFormat::kRedInteger,
            eFrameBufferTextureFormat::kDepth
        };
        frameBuffer = FrameBuffer::create(spec);

        DbGeometry* pDbObj = new DbGeometry();
        pDbObj->setGeometry(new GePlane());
        Handle hdl;
        TestLayer::currentDb().add(pDbObj, hdl);

        BatchRender::initialize();
    }

    void TestLayer::onDetach()
    {
        texture.reset();
        camera.reset();
        frameBuffer.reset();

        BatchRender::terminate();
    }

    void TestLayer::onUpdate(const TimeStep& ts)
    {
        if (!m_EmbedCommand && CommandScheduler::instance().hasCommandToExecute())
        {
            m_EmbedCommand = CommandScheduler::instance().popCommand();
            if (!m_EmbedCommand->isRunnable()) {
                EB_SAFE_DELETE(m_EmbedCommand);
            }
            else {
                m_EmbedCommand->beginInvoke();
            }
        }
        if (m_EmbedCommand && m_EmbedCommand->editor().status() != EditorBase::EditorStatus::kInterating)
        {
            m_EmbedCommand->endInvoke();
            EB_SAFE_DELETE(m_EmbedCommand);
        }

        if (m_EmbedCommand)
        {
            m_EmbedCommand->editor().update();
        }
        if (viewHovered) {
            camera->onUpdate(ts);
        }
    }

    void TestLayer::onGuiRender()
    {
        static bool dockEnabled = true;
        DockSpace::begin("Main Doc Space", dockEnabled, true);

        static MenuBar menubar;
        static bool menubarInit = false;
        if (!menubarInit) {
            Shared<MenuBarMenu> menuEdit = createShared<MenuBarMenu>("Edit");
            menuEdit->addMenuItem(createShared<MenuBarMenuItem>(EB_CMD_UNDO, "Ctrl + Z", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand(EB_CMD_UNDO);)));
            menuEdit->addMenuItem(createShared<MenuBarMenuItem>(EB_CMD_REDO, "Ctrl + Y", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand(EB_CMD_REDO);)));
            menubar.addMenu(menuEdit);
            Shared<MenuBarMenu> menuCreate = createShared<MenuBarMenu>("Create");
            menuCreate->addMenuItem(createShared<MenuBarMenuItem>(EB_CMD_CREATE_LINE_2D, "", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand(EB_CMD_CREATE_LINE_2D);)));
            menuCreate->addMenuItem(createShared<MenuBarMenuItem>(EB_CMD_CREATE_CIRCLE_2D, "", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand(EB_CMD_CREATE_CIRCLE_2D);)));
            menubar.addMenu(menuCreate);
            menubarInit = true;
        }
        menubar.onGuiRender();

        auto slot = [&]() {
            auto& bounds = Panel::viewportBounds();
            viewPortOffset = Panel::position();
            Vec2f size = Vec2f(bounds[1].x() - bounds[0].x(), bounds[1].y() - bounds[0].y());
            if (size.x() > 0 && size.y() > 0) {
                frameBuffer->onResize((unsigned int)size.x(), (unsigned int)size.y());
                camera->setViewportSize(size.x(), size.y());
            }
            frameBuffer->bind();
            RendererEntry::instance().clear();
            BatchRender::start(camera->viewProjectionMatrix());

            if (m_EmbedCommand)
            {
                m_EmbedCommand->editor().updateDisplay();
            }
            auto persistObjs = TestLayer::currentDb().allObjects();
            for (auto obj : persistObjs) {
                Handle::access<DbObject>(obj)->onRender();
            }

            BatchRender::end();
            frameBuffer->unbind();
            EB_WIDGET_IMMEDIATE(ImageWidget, frameBuffer->colorAttachmentRendererId(), Panel::viewportAvailiable());
            viewHovered = Panel::isHovered();
        };

        auto slot_2 = [&]() {
            auto statistic = BatchRender::statistic();
            EB_WIDGET_IMMEDIATE(Text, "Batch Call:  [%d]", statistic.RenderCall);
            EB_WIDGET_IMMEDIATE(Text, "Vertex Count:  [%d]", statistic.VertexCount);
            EB_WIDGET_IMMEDIATE(Text, "Element Count:  [%d]", statistic.ElementCount);
        };

        auto slot_3 = [&]() {
            auto undoList = UndoManager::instance().commandsInUndoStack();
            undoList.push_back("---end---");
            auto redoList = UndoManager::instance().commandsInRedoStack();
            redoList.push_back("---end---");
            static int undoIndex = 0;
            static int redoIndex = 0;
            EB_WIDGET_IMMEDIATE(ListBox, "Commands In Undo", undoIndex, undoList);
            EB_WIDGET_IMMEDIATE(ListBox, "Commands In Redo", redoIndex, redoList);
        };

        EB_WIDGET_IMMEDIATE(Panel, "Render Window", slot);
        EB_WIDGET_IMMEDIATE(Panel, "Render Statistic", slot_2);
        EB_WIDGET_IMMEDIATE(Panel, "Command Stack", slot_3);

        DockSpace::end();
    }

    void TestLayer::onEvent(Event& e)
    {
        if (viewHovered) {
            camera->onEvent(e);

            if (m_EmbedCommand)
            {
                EditorBase::EventExtension extend = { camera->ray(GeMatrix2d().setAsTranslation(-viewPortOffset)), Handle::kNull };
                m_EmbedCommand->editor().handleInput(e, extend);
            }
        }

        EventDispatcher dispatcher(e);
        dispatcher.dispatch<KeyPressedEvent>(std::bind(&TestLayer::_onKeyPressedEvent, this, std::placeholders::_1));
    }

    bool TestLayer::_onKeyPressedEvent(KeyPressedEvent& event)
    {
        Shared<Window> window = Application::instance().window("DemoApp");
        bool ctrlPressed = window->isKeyPressed(KEY_LEFT_CONTROL) | window->isKeyPressed(KEY_RIGHT_CONTROL);

        if (event.repeats()) {
            return false;
        }

        switch (event.key()) {
            case KEY_Z:
                if (ctrlPressed) {
                    CommandScheduler::instance().enqueueCommand(EB_CMD_UNDO);
                    return true;
                }
                break;
            case KEY_Y:
                if (ctrlPressed) {
                    CommandScheduler::instance().enqueueCommand(EB_CMD_REDO);
                    return true;
                }
                break;
        }

        return false;
    }

    DbDatabase& TestLayer::currentDb()
    {
        static DbGeometryDatabase db;
        return db;
    }

}