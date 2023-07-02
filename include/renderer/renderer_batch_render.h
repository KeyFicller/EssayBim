#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include "basic_matrix.h"

namespace EB
{
    class EB_EXPORT BatchRender final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(BatchRender)
    public:
        BatchRender();
        ~BatchRender();

    public:
        static BatchRender& instance();

    public:
        static void start(const Mat4& viewprojectionMatrix);
        static void end();

    public:
        static void line(const Vec3f& start, const Vec3f& end);
        static void mesh(const std::vector<Vec3f>& vertices, const std::vector<Vec3i>& indices, const std::vector<Vec3f>& normals);
    };
}