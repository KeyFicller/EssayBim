#include "renderer_help.h"

#include "renderer_vertex_array.h"
#include "renderer_vertex_buffer.h"
#include "renderer_index_buffer.h"
#include "renderer_shader.h"
#include "renderer_buffer_layout.h"
#include "renderer_graphics_context.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace EB
{
    namespace
    {
        float vertices[] = {
            -0.5f, -0.5f,  0.0f,
             0.5f, -0.5f,  0.0f,
             0.0f,  0.5f,  0.0f
        };

        unsigned int indices[] = {
            0, 1, 2
        };

        const char* vertexShaderSource =
            "#version 330 core                                      \n"
            "layout (location = 0) in vec3 aPos;                    \n"
            "void main()                                            \n"
            "{                                                      \n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);   \n"
            "}                                                      \0";

        const char* fragmentShaderSource =
            "#version 330 core                                      \n"
            "out vec4 FragColor;                                    \n"
            "void main()                                            \n"
            "{                                                      \n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);           \n"
            "}                                                      \0";
    }

    int TestRenderer::showDemoRender()
    {
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
            return -1;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        auto gc = GraphicsContext::create(window);
        gc->initialize();

        /* - Initialize test data here - */
        auto vao = VertexArray::create();
        auto vbo = VertexBuffer::create(vertices, sizeof(vertices));
        BufferLayout layout{
            {"position", eShaderDataType::kFloat3, false}
        };
        vbo->setLayout(layout);
        vao->addVertexBuffer(vbo);
        auto ibo = IndexBuffer::create(indices, 3);
        vao->setIndexBuffer(ibo);
        auto shader = Shader::create("demo", vertexShaderSource, fragmentShaderSource);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            shader->bind();
            vao->bind();
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

            /* Swap front and back buffers */
            gc->swapBuffers();

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
        return 0;
    }

}