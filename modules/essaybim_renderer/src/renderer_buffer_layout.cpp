#include "renderer_buffer_layout.h"

#include "renderer_utils.h"
#include "renderer_buffer_layout_impl.h"

namespace EB
{
    EB_IMPL_DEFAULT_COPY_IMPLEMENT(BufferLayout);

    BufferLayoutElement::BufferLayoutElement(const std::string& name, eShaderDataType type, bool normalized /*= false*/)
        : Name(name), Type(type), Normalized(normalized)
    {
        Size = Utils_Renderer::shaderTypeSize(Type);
        Component = Utils_Renderer::shaderTypeComponent(Type);
    }

    BufferLayout::BufferLayout()
    {
        EB_IMPL = createScoped<BufferLayoutImpl>();
    }

    BufferLayout::BufferLayout(const std::initializer_list<BufferLayoutElement>& elements)
    {
        EB_IMPL = createScoped<BufferLayoutImpl>(elements);
    }

    BufferLayout::~BufferLayout()
    {

    }

    const std::vector<EB::BufferLayoutElement>& BufferLayout::elements() const
    {
        return EB_IMPL->elements();
    }

    unsigned int BufferLayout::stride() const
    {
        return EB_IMPL->stride();
    }

}