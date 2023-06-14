#pragma once

#include "renderer_vertex_array.h"

#include "basic_export.h"
#include "basic_impl_template.h"
#include "basic_vector.h"

namespace EB
{
    /**
     * @brief   this class define api interface for renderer.
     */
    class EB_EXPORT RendererEntry final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(RendererEntry);
    public:
        /**
         * @brief  constructor of RendererEntry
         */
        RendererEntry();

        /**
         * @brief  destructor of RendererEntry.
         */
        ~RendererEntry();

    public:
        /**
         * @brief  get global instance of renderer entry.
         * @return  const reference of global renderer entry instance.
         */
        static const RendererEntry& instance();

    public:
        /**
         * @brief  clear renderer buffer bit.
         */
        void clear() const;

        /**
         * @brief  set clear color.
         * @param[in]  color    clear color.
         */
        void setClearColor(const Vec4& color) const;

        /**
         * @brief  set view port.
         * @param[in]  x      view port horizontal position.
         * @param[in]  y      view port vertical position.
         * @param[in]  width  view port width.
         * @param[in]  height view port height.
         */
        void setViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;

        /**
         * @brief  renderer a triangle mesh data.
         * @param[in]  vao    vertex array object.
         * @param[in]  count  indices count to renderer.
         */
        void mesh(const Shared<VertexArray>& vao, unsigned int count = 0) const;
    };
}