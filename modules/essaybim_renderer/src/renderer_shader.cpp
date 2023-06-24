#include "renderer_shader.h"

#include "renderer_shader_impl.h"

namespace EB
{

    Shared<Shader> Shader::create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        return createShared<Shader>(name, vertexSrc, fragmentSrc);
    }

    Shared<Shader> Shader::create(const std::string& name, const std::string& filePath)
    {
        return createShared<Shader>(name, filePath);
    }

    Shared<Shader> Shader::create(const std::string& filePath)
    {
        return createShared<Shader>(filePath);
    }

    Shader::Shader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        EB_IMPL() = createScoped<ShaderImpl>(name, vertexSrc, fragmentSrc);
    }

    Shader::Shader(const std::string& name, const std::string& filePath)
    {
        EB_IMPL() = createScoped<ShaderImpl>(name, filePath);
    }

    Shader::Shader(const std::string& filePath)
    {
        EB_IMPL() = createScoped<ShaderImpl>(filePath);
    }

    Shader::~Shader()
    {
        EB_IMPL().reset();
    }

    void Shader::bind() const
    {
        EB_IMPL()->bind();
    }

    void Shader::unbind() const
    {
        EB_IMPL()->unbind();
    }

    std::string Shader::name() const
    {
        return EB_IMPL()->name();
    }

    void Shader::setInt(const std::string& key, int value)
    {
        EB_IMPL()->setInt(key, value);
    }

    void Shader::setIntArray(const std::string& key, unsigned int count, int* pValues)
    {
        EB_IMPL()->setIntArray(key, count, pValues);
    }

    void Shader::setFloat(const std::string& key, float value)
    {
        EB_IMPL()->setFloat(key, value);
    }

    void Shader::setFloat2(const std::string& key, const Vec2f& value)
    {
        EB_IMPL()->setFloat2(key, value);
    }

    void Shader::setFloat3(const std::string& key, const Vec3f& value)
    {
        EB_IMPL()->setFloat3(key, value);
    }

    void Shader::setFloat4(const std::string& key, const Vec4f& value)
    {
        EB_IMPL()->setFloat4(key, value);
    }

    void Shader::setMat3(const std::string& key, const Mat3& value)
    {
        EB_IMPL()->setMat3(key, value);
    }

    void Shader::setMat4(const std::string& key, const Mat4& value)
    {
        EB_IMPL()->setMat4(key, value);
    }

}