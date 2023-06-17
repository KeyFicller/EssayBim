#include "renderer_material.h"

namespace EB
{
    EB_DECLARE_YAML_KEYS(Name, Ambient, Diffuse, Specular, Shininess);

    void Material::subYamlIn(const std::string& key)
    {
        YamlBase::subYamlIn(key);

        EB_YAML_IN(s_Key.Name, Name);
        EB_YAML_IN(s_Key.Ambient, Ambient);
        EB_YAML_IN(s_Key.Diffuse, Diffuse);
        EB_YAML_IN(s_Key.Specular, Specular);
        EB_YAML_IN(s_Key.Shininess, Shininess);
    }

    void Material::subYamlOut(const std::string& key)
    {
        YamlBase::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        EB_YAML_OUT(s_Key.Name, Name);
        EB_YAML_OUT(s_Key.Ambient, Ambient);
        EB_YAML_OUT(s_Key.Diffuse, Diffuse);
        EB_YAML_OUT(s_Key.Specular, Specular);
        EB_YAML_OUT(s_Key.Shininess, Shininess);
    }

}