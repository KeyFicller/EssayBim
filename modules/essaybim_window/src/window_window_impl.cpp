#include "window_window_impl.h"

#include "basic_assert.h"

#include <GLFW/glfw3.h>

namespace EB
{
    static unsigned int s_GLFWWindowCount = 0;

    static void glfwErrorCallback(int error, const char* desc)
    {
        EB_CORE_ERROR("GLFW error (%d): %s", error, desc);
    }

    WindowImpl::WindowImpl(const WindowProperties& properties)
        : m_Data({properties.Title, properties.Width, properties.Height, true})
    {
        initialize();
    }

    WindowImpl::~WindowImpl()
    {
        shutdown();
    }

    unsigned int WindowImpl::width() const
    {
        return m_Data.Width;
    }

    unsigned int WindowImpl::height() const
    {
        return m_Data.Height;
    }

    bool WindowImpl::isVSync() const
    {
        return m_Data.VSync;
    }

    void WindowImpl::setVSync(bool enable /*= true*/)
    {
        m_Data.VSync = enable;
        if (m_Data.VSync) {
            glfwSwapInterval(1);
        }
        else {
            glfwSwapInterval(0);
        }
    }

    void WindowImpl::setEventCallback(const Window::EventCallbackFn& callback)
    {
        m_Data.EventCallback = callback;
    }

    void WindowImpl::onUpdate()
    {
        m_GraphicsContext->swapBuffers();
        glfwPollEvents();
    }

    void WindowImpl::initialize()
    {
        EB_CORE_INFO("Create window %s (%d, %d)", m_Data.Title.c_str(), m_Data.Width, m_Data.Height);

        // initialize glfw functions
        if (s_GLFWWindowCount == 0) {
            int success = glfwInit();
            EB_CORE_ASSERT(success);
            glfwSetErrorCallback(glfwErrorCallback);
        }

        // create glfw window
        m_pWindow = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
        s_GLFWWindowCount++;

        m_GraphicsContext = GraphicsContext::create(m_pWindow);
        m_GraphicsContext->initialize();

        // set window pointer
        glfwSetWindowUserPointer(m_pWindow, &m_Data);

        // 1. window resize call back
        glfwSetWindowSizeCallback(m_pWindow, [](GLFWwindow* window, int width, int height) {

        });

        // 2. window close call back
        glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* window) {

        });

        // 3. key call back
        glfwSetKeyCallback(m_pWindow, [](GLFWwindow* window, int key, int scanmode, int action, int mods) {
            
        });

        // 4. type call back
        glfwSetCharCallback(m_pWindow, [](GLFWwindow* window, unsigned int keyCode) {

        });

        // 5. scroll call back
        glfwSetScrollCallback(m_pWindow, [](GLFWwindow* window, double xOffset, double yOffset) {

        });

        // 6. cursor pos call back
        glfwSetCursorPosCallback(m_pWindow, [](GLFWwindow* window, double xPosition, double yPosition) {

        });

        // 7. mouse button call back
        glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow* window, int button, int action, int mods) {

        });
    }

    void WindowImpl::shutdown()
    {
        glfwDestroyWindow(m_pWindow);
        if (--s_GLFWWindowCount == 0) {
            glfwTerminate();
        }
    }

}