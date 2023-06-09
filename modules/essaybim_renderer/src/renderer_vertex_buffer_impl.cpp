#include "renderer_vertex_buffer_impl.h"

#include "renderer_gl_debugger.h"

#include <glad/glad.h>

namespace EB
{

    VertexBufferImpl::VertexBufferImpl(float* pVertices, unsigned int size)
        : m_RendererId(-1)
    {
        EB_GL_AUTO_TRACE();
        glGenBuffers(1, &m_RendererId);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
        glBufferData(GL_ARRAY_BUFFER, size, pVertices, GL_STATIC_DRAW);
    }

    VertexBufferImpl::VertexBufferImpl(unsigned int size)
    {
        EB_GL_AUTO_TRACE();
        glGenBuffers(1, &m_RendererId);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_STATIC_DRAW);
    }

    void VertexBufferImpl::bind() const
    {
        EB_GL_AUTO_TRACE();
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
    }

    void VertexBufferImpl::unbind() const
    {
        EB_GL_AUTO_TRACE();
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBufferImpl::setData(const void* pData, unsigned int size)
    {
        EB_GL_AUTO_TRACE();
        bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, pData);
    }

    void VertexBufferImpl::setLayout(const BufferLayout& layout)
    {
        m_Layout = layout;
    }

    const EB::BufferLayout& VertexBufferImpl::layout() const
    {
        return m_Layout;
    }

}