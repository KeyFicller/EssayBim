#include "renderer_uniform_buffer.h"

#include "renderer_uniform_buffer_impl.h"

namespace EB
{

    Shared<UniformBuffer> UniformBuffer::create(unsigned int size, unsigned int binding)
    {
        return createShared<UniformBuffer>(size, binding);
    }

    UniformBuffer::UniformBuffer(unsigned int size, unsigned int binding)
    {
        EB_IMPL = createScoped<UniformBufferImpl>(size, binding);
    }

    UniformBuffer::~UniformBuffer()
    {
        EB_IMPL.reset();
    }

    void UniformBuffer::setData(const void* data, unsigned int size, unsigned int offset)
    {
        EB_IMPL->setData(data, size, offset);
    }

}