#include "essaybim_test_layer.h"

#include "basic_file_server.h"
#include "renderer_vertex_array.h"
#include "renderer_vertex_buffer.h"
#include "renderer_index_buffer.h"
#include "renderer_shader.h"
#include "renderer_buffer_layout.h"
#include "renderer_graphics_context.h"
#include "renderer_entry.h"
#include "renderer_shader_library.h"
#include "renderer_texture.h"
#include "geometry_mesh.h"
#include "document_interactive_camera.h"
#include "essaybim_application.h"
#include "window_window.h"
#include "renderer_uniform_buffer.h"
#include "gui_dock_space.h"
#include "renderer_frame_buffer.h"
#include "gui_window_widget.h"
#include "gui_image_widget.h"

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

    TestLayer::TestLayer(const std::string& name)
        : Layer(name)
    {

    }

    void TestLayer::onAttach()
    {
        static GeMesh mesh;
        static bool init = false;
        if (!init) {
            mesh.importFromObj(FileServer::instance().resourcesPathRoot() + "\\meshes\\cube.obj");
            init = true;
        }
        auto bound = mesh.boundingBox();

        const GeMeshData& meshData = mesh.data();
        vao = VertexArray::create();
        vbo = VertexBuffer::create((float*)meshData.Vertices.data(), (unsigned int)(meshData.Vertices.size()) * 3 * sizeof(float));
        BufferLayout layout{
            {"aPos", eShaderDataType::kFloat3, false},
        };
        vbo->setLayout(layout);
        vao->addVertexBuffer(vbo);
        ibo = IndexBuffer::create((unsigned int*)meshData.Indices.data(), (unsigned int)(meshData.Indices.size()) * 3);
        vao->setIndexBuffer(ibo);
        shader = Shader::create(FileServer::instance().resourcesPathRoot() + "\\shaders\\flat_mvp.glsl");
        shader->unbind();

        camera = createShared<InteractiveCamera>(Window::instance("DemoApp").get(), 45.f, 1.5f, 0.1f, 1000.f);
        cameraBuffer = UniformBuffer::create(sizeof(CameraData), 0);

        FrameBufferSpecification spec;
        spec.Width = 1500;
        spec.Height = 1000;
        spec.Attachments = {
            eFrameBufferTextureFormat::kRGBA8,
            eFrameBufferTextureFormat::kDepth
        };
        frameBuffer = FrameBuffer::create(spec);
    }

    void TestLayer::onDetach()
    {
        vao.reset();
        vbo.reset();
        ibo.reset();
        shader.reset();
        texture.reset();
        camera.reset();
        cameraBuffer.reset();
        frameBuffer.reset();
    }

    void TestLayer::onUpdate(const TimeStep& ts)
    {
        if (viewHovered) {
            camera->onUpdate(ts);
        }
        cameraData.ViewProjectionMatrix = camera->viewProjectionMatrix();
        cameraBuffer->setData(&cameraData, sizeof(CameraData), 0);
    }

    void TestLayer::onGuiRender()
    {
        static bool dockEnabled = true;
        DockSpace::begin("Main Doc Space", dockEnabled, true);

        auto slot = [&]() {
            auto& bounds = WindowWidget::viewportBounds();
            Vec2f size = Vec2f(bounds[1].x() - bounds[0].x(), bounds[1].y() - bounds[0].y());
            if (size.x() > 0 && size.y() > 0) {
                frameBuffer->onResize((unsigned int)size.x(), (unsigned int)size.y());
            }
            frameBuffer->bind();
            RendererEntry::instance().clear();
            shader->bind();
            RendererEntry::instance().mesh(vao);
            frameBuffer->unbind();
            EB_WIDGET_IMMEDIATE(ImageWidget, frameBuffer->colorAttachmentRendererId(), WindowWidget::viewportAvailiable());
            viewHovered = WindowWidget::isHovered();
        };

        EB_WIDGET_IMMEDIATE(WindowWidget, "Render Window", slot);

        DockSpace::end();
    }

    void TestLayer::onEvent(Event& e)
    {
        if (viewHovered) {
            camera->onEvent(e);
        }
    }

}