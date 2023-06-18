#pragma once

#include "basic_assert.h"
#include "essaybim_application.h"

namespace EB
{
    class Application;
    extern Application* createApplication();
}

extern "C" int main(int argc, char** argv)
{
    EB_CLIENT_INFO("Application Start Running.");
    EB::Application* pApp = EB::createApplication();
    pApp->run();
    delete pApp;
    EB_CLIENT_INFO("Application Stop Running.");
}