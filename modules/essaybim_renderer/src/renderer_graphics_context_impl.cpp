#include "renderer_graphics_context_impl.h"

#include "basic_assert.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace EB
{

    GraphicsContextImpl::GraphicsContextImpl(GLFWwindow* windowHandle)
        : m_pWindowHandle(windowHandle)
    {

    }

    GraphicsContextImpl::~GraphicsContextImpl()
    {

    }

    void GraphicsContextImpl::initialize()
    {
        glfwMakeContextCurrent(m_pWindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        EB_CORE_ASSERT(status, "failed to initialize Glad.");

        EB_CORE_INFO("OpenGL Renderer: %s %s %s", (char*)glGetString(GL_VENDOR), (char*)glGetString(GL_RENDERER), (char*)glGetString(GL_VERSION));

        EB_CORE_INFO("OpenGL Vendor: %s", (char*)glGetString(GL_VENDOR));
        EB_CORE_INFO("OpenGL Renderer: %s", (char*)glGetString(GL_RENDERER));
        EB_CORE_INFO("OpenGL Version: %s", (char*)glGetString(GL_VERSION));
    }

    void GraphicsContextImpl::swapBuffers()
    {
        glfwSwapBuffers(m_pWindowHandle);
    }

}