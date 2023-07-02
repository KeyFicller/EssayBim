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
#include "renderer_frame_buffer.h"
#include "renderer_uniform_buffer.h"
#include "essaybim_application.h"
#include "window_window.h"
#include "geometry_mesh.h"
#include "gui_dock_space.h"
#include "gui_panel.h"
#include "gui_image_widget.h"
#include "document_interactive_camera.h"
#include "renderer_batch_render.h"

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
        mesh = createShared<GeMesh>();
        static bool init = false;
        if (!init) {
            mesh->importFromObj(FileServer::instance().resourcesPathRoot() + "\\meshes\\cube.obj");
            init = true;
        }

        const GeMeshData& meshData = mesh->data();
        vaoMesh = VertexArray::create();
        vboMesh = VertexBuffer::create((float*)meshData.Vertices.data(), (unsigned int)(meshData.Vertices.size()) * 3 * sizeof(float));
        BufferLayout layout{
            {"aPos", eShaderDataType::kFloat3, false},
        };
        vboMesh->setLayout(layout);
        vaoMesh->addVertexBuffer(vboMesh);
        iboMesh = IndexBuffer::create((unsigned int*)meshData.Indices.data(), (unsigned int)(meshData.Indices.size()) * 3);
        vaoMesh->setIndexBuffer(iboMesh);

        bound = mesh->boundingBox();
        for (int i = 0; i < 4; i++) {
            boundIs.emplace_back(Vec2i(i, (i + 1) % 4));
            boundIs.emplace_back(Vec2i(i + 4, (i + 1) % 4 + 4));
            boundIs.emplace_back(Vec2i(i, i + 4));
        }
        vaoLine = VertexArray::create();
        vboLine = VertexBuffer::create((float*)bound.data(), (unsigned int)(bound.size()) * 3 * sizeof(float));
        vboLine->setLayout(layout);
        vaoLine->addVertexBuffer(vboLine);
        iboLine = IndexBuffer::create((unsigned int*)boundIs.data(), (unsigned int)(boundIs.size()) * 2);
        vaoLine->setIndexBuffer(iboLine);

        shaderMesh = Shader::create(FileServer::instance().resourcesPathRoot() + "\\shaders\\flat_mvp.glsl");
        shaderMesh->unbind();

        shaderLine = Shader::create(FileServer::instance().resourcesPathRoot() + "\\shaders\\flat_mvp_2.glsl");
        shaderLine->unbind();

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
        vaoMesh.reset();
        vboMesh.reset();
        iboMesh.reset();
        shaderMesh.reset();
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
            auto& bounds = Panel::viewportBounds();
            Vec2f size = Vec2f(bounds[1].x() - bounds[0].x(), bounds[1].y() - bounds[0].y());
            if (size.x() > 0 && size.y() > 0) {
                frameBuffer->onResize((unsigned int)size.x(), (unsigned int)size.y());
            }
            frameBuffer->bind();
            RendererEntry::instance().clear();
            //shaderMesh->bind();
            //RendererEntry::instance().mesh(vaoMesh);
            BatchRender::instance().start(camera->viewProjectionMatrix());
            BatchRender::instance().mesh(mesh->data().Vertices, mesh->data().Indices, mesh->data().Vertices);
            BatchRender::instance().end();
            shaderLine->bind();
            RendererEntry::instance().line(vaoLine);
            frameBuffer->unbind();
            EB_WIDGET_IMMEDIATE(ImageWidget, frameBuffer->colorAttachmentRendererId(), Panel::viewportAvailiable());
            viewHovered = Panel::isHovered();
        };

        EB_WIDGET_IMMEDIATE(Panel, "Render Window", slot);

        DockSpace::end();
    }

    void TestLayer::onEvent(Event& e)
    {
        if (viewHovered) {
            camera->onEvent(e);
        }
    }

}