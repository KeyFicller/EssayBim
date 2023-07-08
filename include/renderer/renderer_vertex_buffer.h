#pragma once

#include "renderer_export.h"

#include "basic_impl_template.h"

namespace EB
{
    class BufferLayout;

    /**
     * @brief   this class is used to define vertex buffer.
     */
    class EB_RENDERER_EXPORT VertexBuffer final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(VertexBuffer)
    public:
        /**
         * @brief   create a vertex buffer with data array and size.
         * @param[in]    pVertices      data array.
         * @param[in]    size           data size of char.
         * @return    shared pointer of created vertex buffer.
         */
        static Shared<VertexBuffer> create(float* pVertices, unsigned int size);

        /**
         * @brief   create a vertex buffer with reserved size.
         * @param[in]    size           data size of char.
         * @return    shared pointer of created vertex buffer.
         */
        static Shared<VertexBuffer> create(unsigned int size);

        /**
         * @brief   destructor for vertex buffer.
         */
        ~VertexBuffer();

    public:
        /**
         * @brief   constructor for vertex buffer.
         * @param[in]   pVertices     pointer to vertices data.
         * @param[in]   size          vertices data size of char.
         */
        VertexBuffer(float* pVertices, unsigned int size);

        /**
         * @brief   constructor for vertex buffer.
         * @param[in]   size          vertices data size of char.
         */
        VertexBuffer(unsigned int size);

    public:
        /**
         * @brief    bind this vertex buffer for renderer.
         */
        void bind() const;

        /**
         * @brief   unbind this vertex buffer and set to null for renderer.
         */
        void unbind() const;

        /**
         * @brief   fill this vertex buffer with given data.
         * @param[in]    pData      pointer to given data.
         * @param[in]    size       given data size of char.
         */
        void setData(const void* pData, unsigned int size);

        /**
         * @brief   specify vertex buffer layout.
         * @param[in]    layout     layout specifies buffer structural.
         */
        void setLayout(const BufferLayout& layout);

        /**
         * @brief   get buffer layout.
         * @return   layout specifies buffer structural.
         */
        const BufferLayout& layout() const;
    };
}