#include "window_test.h"

#include "renderer_vertex_array.h"
#include "renderer_vertex_buffer.h"
#include "renderer_index_buffer.h"
#include "renderer_shader.h"
#include "renderer_buffer_layout.h"
#include "renderer_graphics_context.h"
#include "renderer_entry.h"
#include "renderer_shader_library.h"
#include "renderer_texture.h"

#include "window_window.h"

#include "basic_file_server.h"

#include "event_event_base.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

    int TestWindow::showDemoWindow()
    {
        WindowProperties properties{ "Hello World", 640, 480 };
        Shared<Window> window = Window::create(properties);

        auto eventCallback = [](Event& event) {
            EB_CORE_INFO((&event)->toString().c_str());
        };
        window->setEventCallback(eventCallback);

        /* - Initialize test data here - */
        auto vao = VertexArray::create();
        auto vbo = VertexBuffer::create(vertices, sizeof(vertices));
        BufferLayout layout{
            {"aPos", eShaderDataType::kFloat3, false},
            {"aTexCoord", eShaderDataType::kFloat2, false}
        };
        vbo->setLayout(layout);
        vao->addVertexBuffer(vbo);
        auto ibo = IndexBuffer::create(indices, 6);
        vao->setIndexBuffer(ibo);
        auto shader = Shader::create(FileServer::instance().resourcesPathRoot() + "\\shaders\\flat_texture.glsl");
        shader->bind();
        shader->setInt("uTexture", 0);
        ShaderLibrary shaderLib;
        shaderLib.add(shader);
        auto texture = Texture2D::create(FileServer::instance().resourcesPathRoot() + "\\textures\\penguin.jpg");
        texture->bind(0);
        shader->unbind();

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window->native()))
        {
            /* Render here */
            RendererEntry::instance().clear();

            shaderLib.shader("flat_texture")->bind();
            RendererEntry::instance().mesh(vao);

            /* Swap front and back buffers */
            /* Poll for and process events */
            window->onUpdate();
        }

        return 0;
    }

}