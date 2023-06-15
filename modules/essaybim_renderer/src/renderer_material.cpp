#include "renderer_material.h"

namespace EB
{
#define YAML_KEY_LIST()            \
    EB_DEFINE_YAML_KEY(Name);      \
    EB_DEFINE_YAML_KEY(Ambient);   \
    EB_DEFINE_YAML_KEY(Diffuse);   \
    EB_DEFINE_YAML_KEY(Specular);  \
    EB_DEFINE_YAML_KEY(Shininess);

    EB_DECLARE_YAML_KEYS(YAML_KEY_LIST);


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