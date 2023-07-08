#pragma once

#include "renderer_export.h"

#include "basic_impl_template.h"

namespace EB
{
    /**
     * @brief   this class define uniform buffer.
     */
    class EB_RENDERER_EXPORT UniformBuffer
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(UniformBuffer);
    public:
        /**
         * @brief  create a uniform buffer with given size and binding target.
         * @param[in]   size     given size.
         * @param[in]   binding  binding target.
         * @return   shared pointer of created uniform buffer.
         */
        static Shared<UniformBuffer> create(unsigned int size, unsigned int binding);

    public:
        /**
         * @brief  constructor for uniform buffer.
         * @param[in]   size     given size.
         * @param[in]   binding  binding target.
         */
        UniformBuffer(unsigned int size, unsigned int binding);

        /**
         * @brief  destructor for uniform buffer.
         */
        ~UniformBuffer();

    public:
        /**
         * @brief   set uniform buffer data.
         * @param[in]   data      buffer data.
         * @param[in]   size      buffer size.
         * @param[in]   offset    offset to buffer data.
         */
        void setData(const void* data, unsigned int size, unsigned int offset);
    };
}