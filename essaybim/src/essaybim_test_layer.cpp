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

namespace EB
{
    namespace
    {
        float vertices[] = {
            -0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
             0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
             0.5f,  0.5f,  0.0f,  1.0f,  1.0f,
            -0.5f,  0.5f,  0.0f,  0.0f,  1.0f
        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };
    }

    TestLayer::TestLayer(const std::string& name)
        : Layer(name)
    {

    }

    void TestLayer::onAttach()
    {
        vao = VertexArray::create();
        vbo = VertexBuffer::create(vertices, sizeof(vertices));
        BufferLayout layout{
            {"aPos", eShaderDataType::kFloat3, false},
            {"aTexCoord", eShaderDataType::kFloat2, false}
        };
        vbo->setLayout(layout);
        vao->addVertexBuffer(vbo);
        ibo = IndexBuffer::create(indices, 6);
        vao->setIndexBuffer(ibo);
        shader = Shader::create(FileServer::instance().resourcesPathRoot() + "\\shaders\\flat_texture.glsl");
        shader->bind();
        shader->setInt("uTexture", 0);
        texture = Texture2D::create(FileServer::instance().resourcesPathRoot() + "\\textures\\penguin.jpg");
        texture->bind(0);
        shader->unbind();
    }

    void TestLayer::onDetach()
    {
        vao.reset();
        vbo.reset();
        ibo.reset();
        shader.reset();
        texture.reset();
    }

    void TestLayer::onUpdate(const TimeStep& ts)
    {
        RendererEntry::instance().clear();
        shader->bind();
        RendererEntry::instance().mesh(vao);
    }

    void TestLayer::onGuiRender()
    {

    }

    void TestLayer::onEvent(Event& e)
    {

    }

}