#include "renderer_uniform_buffer_impl.h"

#include "renderer_gl_debugger.h"

#include <glad/glad.h>

namespace EB
{

    UniformBufferImpl::UniformBufferImpl(unsigned int size, unsigned int binding)
    {
        EB_GL_AUTO_TRACE();
        glCreateBuffers(1, &m_RendererId);
        glNamedBufferData(m_RendererId, size, nullptr, GL_DYNAMIC_DRAW);
        glBindBufferBase(GL_UNIFORM_BUFFER, binding, m_RendererId);
    }

    UniformBufferImpl::~UniformBufferImpl()
    {
        EB_GL_AUTO_TRACE();
        glDeleteBuffers(1, &m_RendererId);
    }

    void UniformBufferImpl::setData(const void* data, unsigned int size, unsigned int offset)
    {
        EB_GL_AUTO_TRACE();
        glNamedBufferSubData(m_RendererId, offset, size, data);
    }

}