#include "basic_filer.h"
#include "basic_log.h"
#include "basic_assert.h"

#include "basic_yaml_base.h"

#include <iostream>
#include <windows.h>

int main()
{

    EB::YamlServer::instance().startYamlOut();
    EB::YamlServer::instance().yamlOut("boolean", false);
    EB::YamlServer::instance().endYamlOut("test.yaml");

    EB::YamlServer::instance().startYamlIn("test.yaml");
    bool res = true;
    EB_YAML_IN("boolean", res);
    EB::YamlServer::instance().endYamlIn();

    EB_CORE_ASSERT(!res);

    return 0;
}