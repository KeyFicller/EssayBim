#include "essaybim_test_layer.h"

#include "essaybim_application.h"
#include "essaybim_create_line_2d_cmd.h"
#include "essaybim_create_circle_2d_cmd.h"
#include "essaybim_undo_cmd.h"
#include "essaybim_redo_cmd.h"

#include "command_undo_manager.h"
#include "basic_file_server.h"
#include "database_geometry_database.h"
#include "database_geometry_undo_controller.h"
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
        // TODO: remove this
        CommandScheduler::instance().registerCommand("Create Line 2D", []() {return new CreateLine2dCmd(); });
        CommandScheduler::instance().registerCommand("Create Circle 2D", []() {return new CreateCircle2dCmd(); });
        CommandScheduler::instance().registerCommand("Undo", []() {return new UndoCmd(); });
        CommandScheduler::instance().registerCommand("Redo", []() {return new RedoCmd(); });

        UndoManager::instance().addController(&DbGeUndoController::instance());
    }

    void TestLayer::onAttach()
    {
        mesh = createShared<GeMesh>();
        static bool init = false;
        if (!init) {
            mesh->importFromObj(FileServer::instance().resourcesPathRoot() + "\\meshes\\cube.obj");
            init = true;
        }

        const GeMeshData& meshData = mesh->data();
        bound = mesh->boundingBox();

        camera = createShared<InteractiveCamera>(Window::instance("DemoApp").get(), 45.f, 1.5f, 0.1f, 1000.f);

        FrameBufferSpecification spec;
        spec.Width = 1500;
        spec.Height = 1000;
        spec.Attachments = {
            eFrameBufferTextureFormat::kRGBA8,
            eFrameBufferTextureFormat::kDepth
        };
        frameBuffer = FrameBuffer::create(spec);

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
        static GePoint2d interactPt = GePoint2d(0.f, 0.f);

        static bool dockEnabled = true;
        DockSpace::begin("Main Doc Space", dockEnabled, true);

        static MenuBar menubar;
        static bool menubarInit = false;
        if (!menubarInit) {
            Shared<MenuBarMenu> menu = createShared<MenuBarMenu>("Undo/Redo");
            menu->addMenuItem(createShared<MenuBarMenuItem>("Undo", "Ctrl + Z", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand("Undo");)));
            menu->addMenuItem(createShared<MenuBarMenuItem>("Undo", "Ctrl + Y", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand("Redo");)));
            menubar.addMenu(menu);
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
            BatchRender::mesh(mesh->data().Vertices, mesh->data().Indices, mesh->data().Vertices);
            for (int i = 0; i < 4; i++) {
                BatchRender::line(bound[i], bound[(i + 1) % 4]);
                BatchRender::line(bound[i + 4], bound[(i + 1) % 4 + 4]);
                BatchRender::line(bound[i], bound[i + 4]);
            }

            GeCircle2d curve = GeCircle2d(GePoint2d(3.0f, 0.0f), 1);
            {
                GeCircle3d* pCurve3d = static_cast<GeCircle3d*>(curve.create3D(GePlane()));
                auto pts = pCurve3d->sampler(0.02f);
                std::vector<Vec3f> vecPts;
                for (unsigned int i = 0; i < pts.size(); i++) {
                    vecPts.emplace_back(pts[i]);
                }
                BatchRender::polyline(vecPts);
                EB_SAFE_DELETE(pCurve3d);
            }
            auto pt = curve.closestPointTo(interactPt);
            BatchRender::line(Vec3f(pt.x(), pt.y(), 0.0f), Vec3f(interactPt.x(), interactPt.y(), 0.0f));
            // curve.translateBy(GeVector2d(1.0f, 0.0f));
            curve.mirrorBy(GeLine2d(GePoint2d(0.0f, 1.0f), GePoint2d(2.0f, 2.0f)));
            {
                GeCircle3d* pCurve3d = static_cast<GeCircle3d*>(curve.create3D(GePlane()));
                auto pts = pCurve3d->sampler(0.02f);
                std::vector<Vec3f> vecPts;
                for (unsigned int i = 0; i < pts.size(); i++) {
                    vecPts.emplace_back(pts[i]);
                }
                BatchRender::polyline(vecPts);
                EB_SAFE_DELETE(pCurve3d);
            }
            
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
            EB_WIDGET_IMMEDIATE(DragValueInputF, "COORD X", interactPt.x());
            EB_WIDGET_IMMEDIATE(DragValueInputF, "COORD Y", interactPt.y());
            EB_WIDGET_IMMEDIATE(Button, "Create Line 2D", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand("Create Line 2D");));
            EB_WIDGET_IMMEDIATE(Button, "Create Circle 2D", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand("Create Circle 2D");));
            EB_WIDGET_IMMEDIATE(Button, "Undo", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand("Undo");));
            EB_WIDGET_IMMEDIATE(Button, "Redo", EB_WIDGET_SLOT(CommandScheduler::instance().enqueueCommand("Redo");));
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
                    CommandScheduler::instance().enqueueCommand("Undo");
                    return true;
                }
                break;
            case KEY_Y:
                if (ctrlPressed) {
                    CommandScheduler::instance().enqueueCommand("Redo");
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