#include "basic_filer.h"
#include "basic_log.h"
#include "basic_assert.h"
#include "basic_vector.h"

#include "basic_yaml_base.h"

#include <iostream>
#include <windows.h>

int main()
{
    EB::Vec3 vec3(1.0, 1.0, 2.0);
    EB::YamlServer::instance().startYamlOut();
    EB::YamlServer::instance().yamlOut("boolean", false);
    EB_YAML_OUT("Vec3", vec3);
    EB::YamlServer::instance().endYamlOut("test.yaml");

    EB::YamlServer::instance().startYamlIn("test.yaml");
    bool res = true;
    EB_YAML_IN("boolean", res);
    EB::Vec3 res3;
    EB_YAML_IN("Vec3", res3);
    EB::YamlServer::instance().endYamlIn();

    EB_CORE_ASSERT(!res);

    return 0;
}