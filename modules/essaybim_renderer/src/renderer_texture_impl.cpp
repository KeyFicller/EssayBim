#include "renderer_texture_imp.h"

#include "renderer_gl_debugger.h"

#include "basic_assert.h"
#include "basic_file_server.h"

#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#pragma warning(disable: 26451)
#pragma warning(disable: 6262)
#pragma warning(disable: 26819)
#include <stb_image.h>

namespace EB
{

    Texture2DImpl::Texture2DImpl(const std::string& filePath, const std::string& name)
        : m_FilePath(filePath), m_Name(name.empty() ? FileServer::fileNameOfPath(filePath) : name)
    {
        EB_GL_AUTO_TRACE();
        stbi_set_flip_vertically_on_load(1);
        int channels = 0;
        stbi_uc* data = stbi_load(m_FilePath.c_str(), (int*)&m_Width, (int*)&m_Height, &channels, 0);
        EB_CORE_ASSERT(data, "Failed to load file for texture.");
        if (channels == 4) {
            m_InternalFormat = GL_RGBA8;
            m_DataFormat = GL_RGBA;
        }
        else if (channels == 3) {
            m_InternalFormat = GL_RGB8;
            m_DataFormat = GL_RGB;
        }
        else {
            EB_CORE_ASSERT(false, "File format doesn't support.");
        }

        glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererId);
        glTextureStorage2D(m_RendererId, 1, m_InternalFormat, m_Width, m_Height);

        glTextureParameteri(m_RendererId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_RendererId, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTextureParameteri(m_RendererId, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(m_RendererId, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTextureSubImage2D(m_RendererId, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }

    Texture2DImpl::Texture2DImpl(const std::string& name, unsigned int width, unsigned int height)
        : m_Name(name), m_Width(width), m_Height(height)
    {
        EB_GL_AUTO_TRACE();
        m_InternalFormat = GL_RGBA8;
        m_DataFormat = GL_RGBA;

        glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererId);
        glTextureStorage2D(m_RendererId, 1, m_InternalFormat, m_Width, m_Height);

        glTextureParameteri(m_RendererId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_RendererId, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTextureParameteri(m_RendererId, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(m_RendererId, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    Texture2DImpl::~Texture2DImpl()
    {
        EB_GL_AUTO_TRACE();
        glDeleteTextures(1, &m_RendererId);
    }

    unsigned int Texture2DImpl::width() const
    {
        return m_Width;
    }

    unsigned int Texture2DImpl::height() const
    {
        return m_Height;
    }

    void Texture2DImpl::bind(unsigned int slot /*= 0*/) const
    {
        EB_GL_AUTO_TRACE();
        glBindTextureUnit(slot, m_RendererId);
    }

    void Texture2DImpl::unbind() const
    {
        // TODO:
    }

    void Texture2DImpl::setData(void* data, unsigned int size)
    {
        EB_GL_AUTO_TRACE();
        unsigned int bpp = m_InternalFormat == GL_RGBA8 ? 4 : 3;
        EB_CORE_ASSERT(bpp * m_Width * m_Height == size, "Data size must match.");
        glTextureSubImage2D(m_RendererId, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data);
    }

    unsigned int Texture2DImpl::rendererId() const
    {
        return m_RendererId;
    }

    std::string Texture2DImpl::name() const
    {
        return m_Name;
    }

    std::string Texture2DImpl::filepath() const
    {
        return m_FilePath;
    }

    bool Texture2DImpl::operator==(const Texture2D* other) const
    {
        return rendererId() == other->rendererId();
    }

}