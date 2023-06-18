#include "essaybim_application.h"

#include "event_application_event.h"
#include "window_layer_stack.h"

namespace EB
{
    class ApplicationImpl
    {
    public:
        ApplicationImpl(const std::string& name);
        virtual ~ApplicationImpl();

    public:
        const std::string& name() const;
        Shared<Window> window(const std::string& name = std::string());
        void run();
        void onEvent(Event& e);
        void close();

    private:
        bool onWindowClosed(WindowClosedEvent& e);
        bool onWindowResized(WindowResizedEvent& e);

    protected:
        std::string m_AppName;
        bool m_Running = true;
        bool m_Minimized = false;
        Scoped<LayerStack> m_LayerStack;
    };
}