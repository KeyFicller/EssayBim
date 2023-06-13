#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <vector>

namespace EB
{
    class VertexBuffer;
    class IndexBuffer;

    /**
     * @brief   this class is used to define vertex array.
     */
    class EB_EXPORT VertexArray
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(VertexArray)
    public:
        /**
         * @brief   create a vertex array.
         * @return   shared pointer of create vertex array.
         */
        static Shared<VertexArray> create();

    public:
        /**
         * @brief    constructor of vertex array.
         */
        VertexArray();

        /**
         * @brief    destructor of vertex array.
         */
        ~VertexArray();

    public:
        /**
         * @brief    bind this vertex array to OpenGL for renderer.
         */
        void bind() const;

        /**
         * @brief    unbind this vertex array to OpenGL.
         */
        void unbind() const;

        /**
         * @brief    add a vertex buffer to this vertex array.
         */
        void addVertexBuffer(const Shared<VertexBuffer>& vertexBuffer);

        /**
         * @brief    set index buffer for this vertex array.
         */
        void setIndexBuffer(const Shared<IndexBuffer>& indexBuffer);

        /**
         * @brief    get all vertex buffers.
         * @return    vertex buffer pointers in vector.
         */
        const std::vector<Shared<VertexBuffer>>& vertexBuffers() const;

        /**
         * @brief    get index buffer.
         * @return    index buffer pointer.
         */
        const Shared<IndexBuffer>& indexBuffer() const;
    };
}