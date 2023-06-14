#pragma once

#include "renderer_texture.h"

namespace EB
{
    class Texture2DImpl
    {
    public:
        Texture2DImpl(const std::string& filePath, const std::string& name = std::string());
        Texture2DImpl(const std::string& name, unsigned int width, unsigned int height);
        ~Texture2DImpl();

    public:
        unsigned int width() const;
        unsigned int height() const;
        void bind(unsigned int slot = 0) const;
        void unbind() const;
        void setData(void* data, unsigned int size);
        unsigned int rendererId() const;
        bool operator == (const Texture2D* other) const;
        std::string name() const;
        std::string filepath() const;

    protected:
        unsigned int m_RendererId = -1;
        std::string m_FilePath;
        std::string m_Name;
        unsigned int m_Width = 0;
        unsigned int m_Height = 0;
        unsigned int m_InternalFormat = 0;
        unsigned int m_DataFormat = 0;
    };
}