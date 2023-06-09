#include "renderer_buffer_layout_impl.h"

namespace EB
{

    BufferLayoutImpl::BufferLayoutImpl()
        : m_Elements({}), m_Stride(0)
    {

    }

    BufferLayoutImpl::BufferLayoutImpl(const std::initializer_list<BufferLayoutElement>& elements)
        : m_Elements(elements), m_Stride(0)
    {
        _updateOffsetAndStride();
    }

    BufferLayoutImpl::~BufferLayoutImpl()
    {

    }

    const std::vector<EB::BufferLayoutElement>& BufferLayoutImpl::elements() const
    {
        return m_Elements;
    }

    unsigned int BufferLayoutImpl::stride() const
    {
        return m_Stride;
    }

    void BufferLayoutImpl::_updateOffsetAndStride()
    {
        unsigned int offset = 0;
        for (auto& element : m_Elements) {
            element.Offset = offset;
            offset += element.Size;
        }
        m_Stride = offset;
    }

}