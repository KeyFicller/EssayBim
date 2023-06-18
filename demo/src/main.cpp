
#include "basic_yaml_base.h"
#include "renderer_material_library.h"
#include "window_test.h"

#include <iostream>
#include <windows.h>

int main()
{
    EB::Shared<EB::Material> mat = EB::createShared<EB::Material>();
    EB::YamlServer::instance().startYamlOut();
    mat->yamlOut("material");
    EB::YamlServer::instance().endYamlOut("test.yaml");

    EB::TestWindow::showDemoWindow();

    return 0;
}