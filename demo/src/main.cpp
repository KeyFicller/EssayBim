#include "renderer_help.h"

#include "renderer_material_library.h"

#include <iostream>
#include <windows.h>

int main()
{
    EB::Shared<EB::Material> mat = EB::createShared<EB::Material>();
    EB::YamlServer::instance().startYamlOut();
    mat->yamlOut("material");
    EB::YamlServer::instance().endYamlOut("test.yaml");
    EB::TestRenderer::showDemoRender();


    return 0;
}