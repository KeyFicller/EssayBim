#include "renderer_texture_library.h"

namespace EB
{

    Shared<Texture2D> Texture2DLibrary::texture(const std::string& key)
    {
        return get(key);
    }

    void Texture2DLibrary::add(const Shared<Texture2D>& texture)
    {
        BaseLibrary<Texture2D>::add(texture->name(), texture);
    }

    void Texture2DLibrary::remove(const Shared<Texture2D>& texture)
    {
        BaseLibrary<Texture2D>::remove(texture->name());
    }

    void Texture2DLibrary::subYamlIn(const std::string& key)
    {

    }

    void Texture2DLibrary::subYamlOut(const std::string& key) const
    {

    }

}