#pragma once

#include "renderer_buffer_layout.h"

namespace EB
{
    class VertexBufferImpl
    {
    public:
        VertexBufferImpl(float* pVertices, unsigned int size);
        VertexBufferImpl(unsigned int size);

    public:
        void bind() const;
        void unbind() const;
        void setData(const void* pData, unsigned int size);
        void setLayout(const BufferLayout& layout);
        const BufferLayout& layout() const;

    private:
        unsigned int m_RendererId;      /* < index identifier allocated by open gl > */
        BufferLayout m_Layout;          /* < layout specifies buffer data structural > */
    };
}