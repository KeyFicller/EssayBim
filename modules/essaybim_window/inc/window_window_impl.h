#pragma once

#include "window_window.h"
#include "renderer_graphics_context.h"

struct GLFWwindow;

namespace EB
{

    class WindowImpl
    {
    public:
        WindowImpl(const WindowProperties& properties);
        ~WindowImpl();

    public:
        unsigned int width() const;
        unsigned int height() const;
        bool isVSync() const;
        void setVSync(bool enable = true);
        void setEventCallback(const Window::EventCallbackFn& callback);

    public:
        void onUpdate();

    private:
        void initialize();
        void shutdown();

    protected:
        GLFWwindow* m_pWindow = nullptr;
        struct WindowData {
            std::string Title;
            unsigned int Width;
            unsigned int Height;
            bool VSync;
            Window::EventCallbackFn EventCallback;
        } m_Data;
        Shared<GraphicsContext> m_GraphicsContext;
    };
}