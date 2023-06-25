#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"
#include "basic_vector.h"

#include <string>

namespace EB
{
    class GeMeshImpl;

    struct EB_EXPORT GeMeshData
    {
        std::vector<Vec3f> Vertices;
        std::vector<Vec3i> Indices;
        void clear();
    };

    class EB_EXPORT GeMesh
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(GeMesh)
    public:
        GeMesh();
        GeMesh(GeMeshImpl& impl);
        virtual ~GeMesh();

    public:
        void importFromObj(const std::string& fileName);
        const GeMeshData& data() const;
    };
}