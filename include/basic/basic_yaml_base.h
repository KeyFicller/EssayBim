#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <string>

namespace EB
{
    /*
     * @brief  this class is used to serialize data into yaml file.
     */
    class EB_EXPORT YamlBase
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(YamlBase)
    public:
        void yamlIn(const std::string& key);
        void yamlOut(const std::string& key);
    };
}