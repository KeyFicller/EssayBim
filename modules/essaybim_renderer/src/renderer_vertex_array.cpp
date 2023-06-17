#include "renderer_vertex_array.h"

#include "renderer_vertex_array_impl.h"

namespace EB
{

    Shared<VertexArray> VertexArray::create()
    {
        return createShared<VertexArray>();
    }

    VertexArray::VertexArray()
    {
        EB_IMPL() = createScoped<VertexArrayImpl>();
    }

    VertexArray::~VertexArray()
    {
        EB_IMPL().reset();
    }

    void VertexArray::bind() const
    {
        EB_IMPL()->bind();
    }

    void VertexArray::unbind() const
    {
        EB_IMPL()->unbind();
    }

    void VertexArray::addVertexBuffer(const Shared<VertexBuffer>& vertexBuffer)
    {
        EB_IMPL()->addVertexBuffer(vertexBuffer);
    }

    void VertexArray::setIndexBuffer(const Shared<IndexBuffer>& indexBuffer)
    {
        EB_IMPL()->setIndexBuffer(indexBuffer);
    }

    const std::vector<EB::Shared<EB::VertexBuffer>>& VertexArray::vertexBuffers() const
    {
        return EB_IMPL()->vertexBuffers();
    }

    const EB::Shared<EB::IndexBuffer>& VertexArray::indexBuffer() const
    {
        return EB_IMPL()->indexBuffer();
    }

}