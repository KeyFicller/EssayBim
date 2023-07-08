#pragma once

#include "renderer_export.h"

#include "basic_impl_template.h"
#include "basic_matrix.h"

namespace EB
{
    /**
     * @brief   get statistic of last batch render
     */
    struct BatchRenderStatistic
    {
        /** < total call of OpenGL draw elements > */
        unsigned int RenderCall;

        /** < total count of vertex > */
        unsigned int VertexCount;

        /** < total count of element > */
        unsigned int ElementCount;
    };

    /**
     * @brief   this class defines Batch render class.
     */
    class EB_RENDERER_EXPORT BatchRender final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(BatchRender)
    public:
        /**
         * @brief  constructor for batch renderer.
         */
        BatchRender();

        /**
         * @brief  destructor for batch renderer.
         */
        ~BatchRender();

    public:
        /**
         * @brief  initialize batch renderer.
         */
        static void initialize();

        /**
         * @brief  get last batch statistic.
         * @return    last batch statistic.
         */
        static const BatchRenderStatistic& BatchRender::statistic();

        /**
         * @brief   terminate batch renderer.
         */
        static void terminate();

    public:
        /**
         * @brief   start one batch.
         * @param[in]   viewprojectionMatrix    camera info.
         */
        static void start(const Mat4& viewprojectionMatrix);

        /**
         * @brief   end one batch.
         */
        static void end();

    public:
        /**
         * @breif   add a line to batch.
         * @param[in]   start    start point of line.
         * @param[in]   end      end point of line.
         */
        static void line(const Vec3f& start, const Vec3f& end);

        /**
         * @brief  add a polyline to batch.
         * @param[in]   vertices     positions of vertices.
         */
        static void polyline(const std::vector<Vec3f>& vertices);

        /**
         * @brief   add a frame to batch.
         * @param[in]   vertices     positions of vertices.
         * @param[in]   indices      indices of wire frame link.
         */
        static void frame(const std::vector<Vec3f>& vertices, const std::vector<Vec2i>& indices);

        /**
         * @brief   add a mesh to batch.
         * @param[in]   vertices     positions of vertices.
         * @param[in]   indices      indices of triangle mesh.
         * @param[in]   normals      normal vector.
         */
        static void mesh(const std::vector<Vec3f>& vertices, const std::vector<Vec3i>& indices, const std::vector<Vec3f>& normals);
    };
}