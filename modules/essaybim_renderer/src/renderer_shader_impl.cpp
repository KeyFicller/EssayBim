#include "renderer_shader_impl.h"

#include "renderer_gl_debugger.h"
#include "renderer_utils.h"

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
        std::unordered_map<GLenum, std::string> sources = Utils_Renderer::parseShaderSource(source);
        _compile(sources);

    }

    ShaderImpl::ShaderImpl(const std::string& filePath)
    {
        EB_GL_AUTO_TRACE();
        glDeleteProgram(m_RendererId);
    }

    void ShaderImpl::bind() const
    {
        EB_GL_AUTO_TRACE();
        glUseProgram(m_RendererId);
    }

    void ShaderImpl::unbind() const
    {
        EB_GL_AUTO_TRACE();
        glUseProgram(0);
    }

    std::string ShaderImpl::name() const
    {
        return m_Name;
    }

    void ShaderImpl::setInt(const std::string& key, int value)
    {
        EB_GL_AUTO_TRACE();
        glUniform1i(_location(key), value);
    }

    void ShaderImpl::setIntArray(const std::string& key, unsigned int count, int* pValues)
    {
        EB_GL_AUTO_TRACE();
        glUniform1iv(_location(key), count, pValues);
    }

    void ShaderImpl::setFloat(const std::string& key, float value)
    {
        EB_GL_AUTO_TRACE();
        glUniform1f(_location(key), value);
    }

    void ShaderImpl::setFloat2(const std::string& key, const Vec2& value)
    {
        EB_GL_AUTO_TRACE();
        glUniform2f(_location(key), value.x(), value.y());
    }

    void ShaderImpl::setFloat3(const std::string& key, const Vec3& value)
    {
        EB_GL_AUTO_TRACE();
        glUniform3f(_location(key), value.x(), value.y(), value.z());
    }

    void ShaderImpl::setFloat4(const std::string& key, const Vec4& value)
    {
        EB_GL_AUTO_TRACE();
        glUniform4f(_location(key), value.x(), value.y(), value.z(), value.w());
    }

    void ShaderImpl::setMat3(const std::string& key, const Mat3& value)
    {
        glUniformMatrix3fv(_location(key), 1, GL_FALSE, glm::value_ptr(value.toGlm()));
    }

    void ShaderImpl::setMat4(const std::string& key, const Mat4& value)
    {
        glUniformMatrix4fv(_location(key), 1, GL_FALSE, nullptr);
    }

    void ShaderImpl::_compile(const std::unordered_map<GLenum, std::string>& shaderSources)
    {

    }

    GLint ShaderImpl::_location(const std::string& key)
    {
        return -1;
    }

}