#include "window_window.h"

#include "window_window_impl.h"

#include "basic_library.h"

namespace EB
{
    namespace
    {
        class WindowLibrary : public BaseLibrary<Window> {};
        WindowLibrary _library;
    }
    

    Shared<Window> Window::create(const WindowProperties& properties)
    {
        _library.add(properties.Title, createShared<Window>(properties));
        return _library.get(properties.Title);
    }

    Shared<Window> Window::instance(const std::string& title)
    {
        return _library.get(title);
    }

    void Window::destroy(const std::string& title)
    {
        _library.remove(title);
    }

    Window::Window(const WindowProperties& properties)
    {
        EB_IMPL = createScoped<WindowImpl>(properties);
    }

    Window::~Window()
    {
        EB_IMPL.reset();
    }

    unsigned int Window::width() const
    {
        return EB_IMPL->width();
    }

    unsigned int Window::height() const
    {
        return EB_IMPL->height();
    }

    bool Window::isVSync() const
    {
        return EB_IMPL->isVSync();
    }

    void Window::setVSync(bool enable /*= true*/)
    {
        EB_IMPL->setVSync(enable);
    }

    void Window::setEventCallback(const EventCallbackFn& callback)
    {
        EB_IMPL->setEventCallback(callback);
    }

    void Window::onUpdate()
    {
        EB_IMPL->onUpdate();
    }

}