#include "window_window_impl.h"

#include "basic_assert.h"
#include "event_application_event.h"
#include "event_key_event.h"
#include "event_mouse_button_event.h"
#include "event_mouse_event.h"

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

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

    GLFWwindow* WindowImpl::native() const
    {
        return m_pWindow;
    }

    HWND WindowImpl::hwnd() const
    {
        return glfwGetWin32Window(m_pWindow);
    }

    bool WindowImpl::isKeyPressed(int keyCode)
    {
        auto state = glfwGetKey(native(), keyCode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowImpl::isMouseButtonPressed(int mouseButton)
    {
        auto state = glfwGetMouseButton(native(), mouseButton);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowImpl::cursorPos()
    {
        double x, y;
        glfwGetCursorPos(native(), &x, &y);
        return { (float)x, (float)y };
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

        m_GraphicsContext = createScoped<GraphicsContext>(m_pWindow);
        m_GraphicsContext->initialize();

        // set window pointer
        glfwSetWindowUserPointer(m_pWindow, &m_Data);

        // 1. window resize call back
        glfwSetWindowSizeCallback(m_pWindow, [](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;
            WindowResizedEvent event(width, height);
            data.EventCallback(event);
        });

        // 2. window close call back
        glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* window) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowClosedEvent event;
            data.EventCallback(event);
        });

        // 3. key call back
        glfwSetKeyCallback(m_pWindow, [](GLFWwindow* window, int key, int scanmode, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    static int cachedKey = -1;
                    static int repeatCount = 1;
                    if (key != cachedKey) {
                        repeatCount = 1;
                        cachedKey = key;
                    }
                    else {
                        repeatCount++;
                    }
                    KeyPressedEvent event(key, repeatCount);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        // 4. type call back
        glfwSetCharCallback(m_pWindow, [](GLFWwindow* window, unsigned int keyCode) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            KeyTypedEvent event(keyCode);
            data.EventCallback(event);
        });

        // 5. scroll call back
        glfwSetScrollCallback(m_pWindow, [](GLFWwindow* window, double xOffset, double yOffset) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });

        // 6. cursor pos call back
        glfwSetCursorPosCallback(m_pWindow, [](GLFWwindow* window, double xPosition, double yPosition) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent event((float)xPosition, (float)yPosition);
            data.EventCallback(event);
        });

        // 7. mouse button call back
        glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow* window, int button, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    static int cachedButton = -1;
                    static int repeatCount = 1;
                    if (button != cachedButton) {
                        repeatCount = 1;
                        cachedButton = button;
                    }
                    else {
                        repeatCount++;
                    }
                    MouseButtonPressedEvent event(button, repeatCount);
                    data.EventCallback(event);
                    break;
                }
            }
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