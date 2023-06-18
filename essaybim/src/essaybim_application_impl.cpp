#include "essaybim_application_impl.h"

#include "essaybim_test_layer.h"

#include "basic_assert.h"
#include "event_event_dispatcher.h"
#include "window_window.h"
#include "renderer_entry.h"

#include <functional>

namespace EB
{

#define BIND_EVENT_FN(x) std::bind(&ApplicationImpl::x, this, std::placeholders::_1)

    ApplicationImpl::ApplicationImpl(const std::string& name)
        : m_AppName(name)
    {
        WindowProperties props{ m_AppName, 1200, 800 };
        auto window = Window::create(props);
        window->setEventCallback(BIND_EVENT_FN(onEvent));
        m_LayerStack = createScoped<LayerStack>();
        m_LayerStack->pushLayer(createShared<TestLayer>("main"));
    }

    ApplicationImpl::~ApplicationImpl()
    {
        m_LayerStack.reset();
        Window::destroy(m_AppName);
    }

    const std::string& ApplicationImpl::name() const
    {
        return m_AppName;
    }

    Shared<Window> ApplicationImpl::window(const std::string& name /*= std::string()*/)
    {
        return Window::instance(name.empty() ? m_AppName : name);
    }

    void ApplicationImpl::run()
    {
        while (m_Running) {
            TimeStep ts = TimeStep::deltaTime();
            for (auto& layer : m_LayerStack->layers()) {
                layer->onUpdate(ts);
            }

            window()->onUpdate();
        }
    }

    void ApplicationImpl::onEvent(Event& e)
    {
        EB_CLIENT_INFO("On Event : %s", e.toString().c_str());
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowResizedEvent>(BIND_EVENT_FN(onWindowResized));
        dispatcher.dispatch<WindowClosedEvent>(BIND_EVENT_FN(onWindowClosed));
    }

    void ApplicationImpl::close()
    {
        m_Running = false;
    }

    bool ApplicationImpl::onWindowClosed(WindowClosedEvent& e)
    {
        m_Running = false;
        return false;
    }

    bool ApplicationImpl::onWindowResized(WindowResizedEvent& e)
    {
        if (e.width() == 0 || e.height() == 0) {
            m_Minimized = true;
            return false;
        }
        m_Minimized = true;
        RendererEntry::instance().setViewport(0, 0, e.width(), e.height());
        return false;
    }

}