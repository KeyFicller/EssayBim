#include "renderer_shader_impl.h"

#include "renderer_gl_debugger.h"

#include "basic_file_server.h"

namespace EB
{

    ShaderImpl::ShaderImpl(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
        : m_Name(name)
    {
        std::unordered_map<GLenum, std::string> sources;
        sources[GL_VERTEX_SHADER] = vertexSrc;
        sources[GL_FRAGMENT_SHADER] = fragmentSrc;
        _compile(sources);
    }

    ShaderImpl::ShaderImpl(const std::string& name, const std::string& filePath)
        : m_Name(name)
    {
        std::string source = FileServer::instance().readFromFilePath(filePath);
        std::unordered_map<GLenum, std::string> sources = 

    }

    ShaderImpl::ShaderImpl(const std::string& filePath)
    {

    }

    void ShaderImpl::bind() const
    {

    }

    void ShaderImpl::unbind() const
    {

    }

    std::string ShaderImpl::name() const
    {

    }

    void ShaderImpl::setInt(const std::string& key, int value)
    {

    }

    void ShaderImpl::setIntArray(const std::string& key, unsigned int count, int* pValues)
    {

    }

    void ShaderImpl::setFloat(const std::string& key, float value)
    {

    }

    void ShaderImpl::setFloat2(const std::string& key, const Vec2& value)
    {

    }

    void ShaderImpl::setFloat3(const std::string& key, const Vec3& value)
    {

    }

    void ShaderImpl::setFloat4(const std::string& key, const Vec4& value)
    {

    }

    void ShaderImpl::setMat3(const std::string& key, const Mat3& value)
    {

    }

    void ShaderImpl::setMat4(const std::string& key, const Mat4& value)
    {

    }

    void ShaderImpl::_compile(const std::unordered_map<GLenum, std::string>& shaderSources)
    {

    }

    GLint ShaderImpl::_location(const std::string& key)
    {

    }

}