#include "essaybim_application.h"

#include "essaybim_application_impl.h"

#include "basic_assert.h"

namespace EB
{
    static Application* s_Instance = nullptr;

    Application::Application(const std::string& name)
    {
        EB_CORE_ASSERT(!s_Instance);
        s_Instance = this;
        EB_IMPL() = createScoped<ApplicationImpl>(name);
    }

    Application::~Application()
    {
        EB_IMPL().reset();
    }

    Application& Application::instance()
    {
        return *s_Instance;
    }

    const std::string& Application::name() const
    {
        return EB_IMPL()->name();
    }

   Shared<Window> Application::window(const std::string& name /*= std::string()*/)
    {
       return EB_IMPL()->window(name);
    }

    void Application::run()
    {
        EB_IMPL()->run();
    }

    void Application::onEvent(Event& e)
    {
        EB_IMPL()->onEvent(e);
    }

    void Application::close()
    {
        EB_IMPL()->close();
    }

}