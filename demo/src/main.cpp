#include "essaybim_application_entry.h"

class DemoApp : public EB::Application
{
public:
    DemoApp(void)
        : EB::Application("DemoApp")
    {
    }

    ~DemoApp()
    {
    }
};

EB::Application* EB::createApplication()
{
    return new DemoApp();
}