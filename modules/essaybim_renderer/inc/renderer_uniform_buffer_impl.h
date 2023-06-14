#pragma once

#include "renderer_uniform_buffer.h"

namespace EB
{
    class UniformBufferImpl
    {
    public:
        UniformBufferImpl(unsigned int size, unsigned int binding);
        ~UniformBufferImpl();

    public:
        void setData(const void* data, unsigned int size, unsigned int offset);

    protected:
        unsigned int m_RendererId = 0;
    };
}