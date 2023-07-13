#include "renderer_material.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(Name, Ambient, Diffuse, Specular, Shininess);

    void Material::subYamlIn(const std::string& key)
    {
        YamlBase::subYamlIn(key);

        EB_YAML_IN_DEFAULT_IMPLMENTS(Name, Ambient, Diffuse, Specular, Shininess);
    }

    void Material::subYamlOut(const std::string& key) const
    {
        YamlBase::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        EB_YAML_OUT_DEFAULT_IMPLMENTS(Name, Ambient, Diffuse, Specular, Shininess);
    }

}