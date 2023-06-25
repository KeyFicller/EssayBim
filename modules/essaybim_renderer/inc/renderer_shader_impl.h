#pragma once

#include "renderer_shader.h"

#include <glad/glad.h>

#include <unordered_map>

namespace EB
{
    class ShaderImpl
    {
    public:
        ShaderImpl(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
        ShaderImpl(const std::string& name, const std::string& filePath);
        ShaderImpl(const std::string& filePath);
        ~ShaderImpl();

    public:
        void bind() const;
        void unbind() const;
        std::string name() const;
        void setInt(const std::string& key, int value);
        void setIntArray(const std::string& key, unsigned int count, int* pValues);
        void setFloat(const std::string& key, float value);
        void setFloat2(const std::string& key, const Vec2f& value);
        void setFloat3(const std::string& key, const Vec3f& value);
        void setFloat4(const std::string& key, const Vec4f& value);
        void setMat3(const std::string& key, const Mat3& value);
        void setMat4(const std::string& key, const Mat4& value);

    private:
        void _compile(const std::unordered_map<GLenum, std::string>& shaderSources);
        GLint _location(const std::string& key);

    private:
        unsigned int m_RendererId = -1;
        std::string m_Name;
        std::unordered_map<std::string, GLint> m_LocationCacheMap;
    };
}