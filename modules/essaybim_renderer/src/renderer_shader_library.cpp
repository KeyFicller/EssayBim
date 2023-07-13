#include "renderer_shader_library.h"

namespace EB
{
    Shared<Shader> ShaderLibrary::shader(const std::string& key)
    {
        return get(key);
    }

    void ShaderLibrary::add(const Shared<Shader>& shader)
    {
        BaseLibrary<Shader>::add(shader->name(), shader);
    }

    void ShaderLibrary::remove(const Shared<Shader>& shader)
    {
        BaseLibrary<Shader>::remove(shader->name());
    }

    void ShaderLibrary::subYamlIn(const std::string& key)
    {

    }

    void ShaderLibrary::subYamlOut(const std::string& key) const
    {

    }

}