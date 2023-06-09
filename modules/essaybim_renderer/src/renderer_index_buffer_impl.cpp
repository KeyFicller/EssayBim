#include "renderer_index_buffer_impl.h"

#include "renderer_gl_debugger.h"

#include <glad/glad.h>

namespace EB
{

    IndexBufferImpl::IndexBufferImpl(unsigned int* pIndices, unsigned int count)
        : m_Count(count)
    {
        EB_GL_AUTO_TRACE();
        glGenBuffers(1, &m_RendererId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(unsigned int), pIndices, GL_STATIC_DRAW);
    }

    IndexBufferImpl::~IndexBufferImpl()
    {
        EB_GL_AUTO_TRACE();
        glDeleteBuffers(1, &m_RendererId);
    }

    void IndexBufferImpl::bind()
    {
        EB_GL_AUTO_TRACE();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
    }

    void IndexBufferImpl::unbind()
    {
        EB_GL_AUTO_TRACE();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    unsigned int IndexBufferImpl::count() const
    {
        return m_Count;
    }

}