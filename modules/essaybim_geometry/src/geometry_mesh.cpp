#include "geometry_mesh.h"

#include "geometry_mesh_impl.h"

namespace EB
{
    void GeMeshData::clear()
    {
        Vertices.clear();
        Indices.clear();
    }

    GeMesh::GeMesh()
    {
        EB_IMPL() = createScoped<GeMeshImpl>(this);
    }

    GeMesh::GeMesh(GeMeshImpl& impl)
    {
        EB_IMPL() = std::unique_ptr<GeMeshImpl>(&impl);
    }

    GeMesh::~GeMesh()
    {
        EB_IMPL().reset();
    }

    void GeMesh::importFromObj(const std::string& fileName)
    {
        EB_IMPL()->importFromObj(fileName);
    }

    const EB::GeMeshData& GeMesh::data() const
    {
        return EB_IMPL()->data();
    }

}