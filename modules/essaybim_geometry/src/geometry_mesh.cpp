#include "geometry_mesh.h"

#include "geometry_mesh_impl.h"

namespace EB
{
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

    const GeMeshData& GeMesh::data() const
    {
        return EB_IMPL()->data();
    }

    const std::vector<Vec3f>& GeMesh::boundingBox() const
    {
        return EB_IMPL()->boundingBox();
    }

}