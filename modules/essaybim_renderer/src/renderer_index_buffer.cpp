#include "renderer_index_buffer.h"

#include "renderer_index_buffer_impl.h"

namespace EB
{

    Shared<IndexBuffer> IndexBuffer::create(unsigned int* pIndices, unsigned int count)
    {
        return createShared<IndexBuffer>(pIndices, count);
    }

    IndexBuffer::IndexBuffer(unsigned int* pIndices, unsigned int count)
    {
        EB_IMPL() = createScoped<IndexBufferImpl>(pIndices, count);
    }

    IndexBuffer::~IndexBuffer()
    {

    }

    void IndexBuffer::bind()
    {
        EB_IMPL()->bind();
    }

    void IndexBuffer::unbind()
    {
        EB_IMPL()->unbind();
    }

    unsigned int IndexBuffer::count() const
    {
        return EB_IMPL()->count();
    }

}