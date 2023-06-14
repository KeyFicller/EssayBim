#include "renderer_vertex_buffer.h"

#include "renderer_vertex_buffer_impl.h"

namespace EB
{
    Shared<VertexBuffer> VertexBuffer::create(float* pVertices, unsigned int size)
    {
        return createShared<VertexBuffer>(pVertices, size);
    }

    Shared<VertexBuffer> VertexBuffer::create(unsigned int size)
    {
        return createShared<VertexBuffer>(size);
    }

    VertexBuffer::~VertexBuffer()
    {
        EB_IMPL.reset();
    }

    VertexBuffer::VertexBuffer(float* pVertices, unsigned int size)
    {
        EB_IMPL = createScoped<VertexBufferImpl>(pVertices, size);
    }

    VertexBuffer::VertexBuffer(unsigned int size)
    {
        EB_IMPL = createScoped<VertexBufferImpl>(size);
    }

    void VertexBuffer::bind() const
    {
        EB_IMPL->bind();
    }

    void VertexBuffer::unbind() const
    {
        EB_IMPL->unbind();
    }

    void VertexBuffer::setData(const void* pData, unsigned int size)
    {
        EB_IMPL->setData(pData, size);
    }

    void VertexBuffer::setLayout(const BufferLayout& layout)
    {
        EB_IMPL->setLayout(layout);
    }

    const EB::BufferLayout& VertexBuffer::layout() const
    {
        return EB_IMPL->layout();
    }

}