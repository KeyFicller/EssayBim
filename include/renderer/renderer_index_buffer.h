#pragma once

#include "renderer_export.h"

#include "basic_impl_template.h"

namespace EB
{
    /**
     * @brief   this class is used to define index buffer data.
     */
    class EB_RENDERER_EXPORT IndexBuffer final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(IndexBuffer)
    public:
        /**
         * @brief   create a index buffer with data array and count.
         * @param[in]    pIndices      data array.
         * @param[in]    count           data count.
         * @return    shared pointer of created index buffer.
         */
        static Shared<IndexBuffer> create(unsigned int* pIndices, unsigned int count);

    public:
        /**
         * @brief   constructor for index buffer.
         * @param[in]    pIndices      indices data array.
         * @param[in]    count         how many indices data array has.
         */
        IndexBuffer(unsigned int* pIndices, unsigned int count);

        /**
         * @brief   destructor for index buffer.
         */
        ~IndexBuffer();

    public:
        /**
         * @brief   bind this index buffer to OpenGL for renderer.
         */
        void bind();

        /**
         * @brief   unbind this index buffer to OpenGL for renderer.
         */
        void unbind();

        /**
         * @brief   get indices count.
         * @return    count of indices.
         */
        unsigned int count() const;
    };
}