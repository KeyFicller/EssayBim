#pragma once

#include "renderer_vertex_array.h"

namespace EB
{
    class VertexArrayImpl
    {
    public:
        VertexArrayImpl();
        ~VertexArrayImpl();

    public:
        void bind() const;
        void unbind() const;
        void addVertexBuffer(const Shared<VertexBuffer>& vertexBuffer);
        void setIndexBuffer(const Shared<IndexBuffer>& indexBuffer);
        const std::vector<Shared<VertexBuffer>>& vertexBuffers() const;
        const Shared<IndexBuffer>& indexBuffer() const;

    private:
        unsigned int m_RendererId = -1;                    /** < identifier allocated by OpenGL > */
        unsigned int m_VertexBufferIndex = 0;              /** < current vertex buffer index > */
        std::vector<Shared<VertexBuffer>> m_VertexBuffers; /** < vertex buffers > */
        Shared<IndexBuffer> m_IndexBuffer;                 /** < binded index buffer > */
    };
}