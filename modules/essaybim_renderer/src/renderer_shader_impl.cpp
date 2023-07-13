#include "renderer_shader_impl.h"

#include "renderer_gl_debugger.h"
#include "renderer_utils.h"

#include "basic_file_server.h"

#include <iostream>

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
        std::string source = FileServer::readFromFilePath(filePath);
        std::unordered_map<GLenum, std::string> sources = Utils_Renderer::parseShaderSource(source);
        _compile(sources);

    }

    ShaderImpl::ShaderImpl(const std::string& filePath)
        : m_Name(FileServer::fileNameOfPath(filePath))
    {
        std::string source = FileServer::readFromFilePath(filePath);
        std::unordered_map<GLenum, std::string> sources = Utils_Renderer::parseShaderSource(source);
        _compile(sources);
    }

    ShaderImpl::~ShaderImpl()
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

    void ShaderImpl::setFloat2(const std::string& key, const Vec2f& value)
    {
        EB_GL_AUTO_TRACE();
        glUniform2f(_location(key), value.x(), value.y());
    }

    void ShaderImpl::setFloat3(const std::string& key, const Vec3f& value)
    {
        EB_GL_AUTO_TRACE();
        glUniform3f(_location(key), value.x(), value.y(), value.z());
    }

    void ShaderImpl::setFloat4(const std::string& key, const Vec4f& value)
    {
        EB_GL_AUTO_TRACE();
        glUniform4f(_location(key), value.x(), value.y(), value.z(), value.w());
    }

    void ShaderImpl::setMat3(const std::string& key, const Mat3& value)
    {
        EB_GL_AUTO_TRACE();
        glUniformMatrix3fv(_location(key), 1, GL_FALSE, glm::value_ptr((glm::mat3)value));
    }

    void ShaderImpl::setMat4(const std::string& key, const Mat4& value)
    {
        EB_GL_AUTO_TRACE();
        glUniformMatrix4fv(_location(key), 1, GL_FALSE, glm::value_ptr((glm::mat4)value));
    }

    void ShaderImpl::_compile(const std::unordered_map<GLenum, std::string>& shaderSources)
    {
        EB_GL_AUTO_TRACE();
        GLuint program = glCreateProgram();
        std::vector<GLenum> glShaderIds;
        glShaderIds.reserve(shaderSources.size());
        for (auto& shaderSource : shaderSources) {
            GLenum type = shaderSource.first;
            const std::string& source = shaderSource.second;
            GLuint shader = glCreateShader(type);
            const GLchar* sourceCStr = source.c_str();
            glShaderSource(shader, 1, &sourceCStr, 0);
            glCompileShader(shader);
            GLint isCompiled = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

            if (isCompiled == GL_FALSE)
            {
                GLint infoLogLength = 0;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
                std::string infoLog(infoLogLength + 1, '\0');
                glGetShaderInfoLog(shader, infoLogLength, &infoLogLength, &infoLog[0]);
                glDeleteShader(shader);

                // EB_CORE_ERROR("%s", infoLog.c_str());
                std::cout << infoLog << std::endl;   // TODO:  check crash reason fo EB_CORE_ERROR()
                EB_CORE_ASSERT(false, "Shader source compile failed.");
                break;
            }

            glAttachShader(program, shader);
            glShaderIds.push_back(shader);
        }

        glLinkProgram(program);
        GLint isLinked = 0;
        glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint infoLogLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
            std::vector<GLchar> infoLog(infoLogLength);
            glGetProgramInfoLog(program, infoLogLength, &infoLogLength, infoLog.data());
            glDeleteProgram(program);
            for (auto id : glShaderIds) {
                glDeleteShader(id);
            }

            EB_CORE_ERROR("%s", infoLog.data());
            EB_CORE_ASSERT(false, "Shader source link failed.");
            return;
        }

        for (auto id : glShaderIds) {
            glDetachShader(program, id);
            glDeleteShader(id);
        }

        m_RendererId = program;
    }

    GLint ShaderImpl::_location(const std::string& key)
    {
        if (m_LocationCacheMap.find(key) == m_LocationCacheMap.end()) {
            GLint location = glGetUniformLocation(m_RendererId, key.c_str());
            EB_CORE_ASSERT(location != -1, "Key not found.");
            m_LocationCacheMap[key] = location;
        }
        return m_LocationCacheMap[key];
    }

}