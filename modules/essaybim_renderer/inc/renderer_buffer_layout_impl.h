#pragma once

#include "renderer_buffer_layout.h"

namespace EB
{
    class BufferLayoutImpl
    {
    public:
        BufferLayoutImpl();
        BufferLayoutImpl(const std::initializer_list<BufferLayoutElement>& elements);
        ~BufferLayoutImpl();

    public:
        const std::vector<BufferLayoutElement>& elements() const;
        unsigned int stride() const;

    private:
        void _updateOffsetAndStride();

    private:
        std::vector<BufferLayoutElement> m_Elements;   /** < layout components > */
        unsigned int m_Stride = 0;                     /** < layout total stride length > */
    };
}