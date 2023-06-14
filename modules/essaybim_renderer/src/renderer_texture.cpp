#include "renderer_texture.h"

#include "renderer_texture_imp.h"

namespace EB
{

    Shared<Texture2D> Texture2D::create(const std::string& filePath, const std::string& name /*= std::string()*/)
    {
        return createShared<Texture2D>(filePath, name);
    }

    Shared<Texture2D> Texture2D::create(const std::string& name, unsigned int width, unsigned int height)
    {
        return createShared<Texture2D>(name, width, height);
    }

    Texture2D::Texture2D(const std::string& filePath, const std::string& name /*= std::string()*/)
    {
        EB_IMPL = createScoped<Texture2DImpl>(filePath, name);
    }

    Texture2D::Texture2D(const std::string& name, unsigned int width, unsigned int height)
    {
        EB_IMPL = createScoped<Texture2DImpl>(name, width, height);
    }

    Texture2D::~Texture2D()
    {
        EB_IMPL.reset();
    }

    unsigned int Texture2D::width() const
    {
        return EB_IMPL->width();
    }

    unsigned int Texture2D::height() const
    {
        return EB_IMPL->height();
    }

    void Texture2D::bind(unsigned int slot /*= 0*/) const
    {
        EB_IMPL->bind(slot);
    }

    void Texture2D::unbind() const
    {
        EB_IMPL->unbind();
    }

    void Texture2D::setData(void* data, unsigned int size)
    {
        EB_IMPL->setData(data, size);
    }

    unsigned int Texture2D::rendererId() const
    {
        return EB_IMPL->rendererId();
    }

    std::string Texture2D::name() const
    {
        return EB_IMPL->name();
    }

    std::string Texture2D::filepath() const
    {
        return EB_IMPL->filepath();
    }

    bool Texture2D::operator==(const Texture2D* other) const
    {
        return EB_IMPL->operator==(other);
    }

}