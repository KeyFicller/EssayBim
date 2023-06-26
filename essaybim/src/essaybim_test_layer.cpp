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
    }

    void TestLayer::onDetach()
    {
        vao.reset();
        vbo.reset();
        ibo.reset();
        shader.reset();
        texture.reset();
        camera.reset();
    }

    void TestLayer::onUpdate(const TimeStep& ts)
    {
        camera->onUpdate(ts);
        cameraData.ViewProjectionMatrix = camera->viewProjectionMatrix();
        cameraBuffer->setData(&cameraData, sizeof(CameraData), 0);
        RendererEntry::instance().clear();
        shader->bind();
        RendererEntry::instance().mesh(vao);
    }

    void TestLayer::onGuiRender()
    {

    }

    void TestLayer::onEvent(Event& e)
    {
        camera->onEvent(e);
    }

}