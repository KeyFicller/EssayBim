#include "geometry_mesh_impl.h"


#include "geometry_libigl_disable_warning.h"
#include <igl/readOBJ.h>

namespace EB
{

    GeMeshImpl::GeMeshImpl(GeMesh* pFacade)
        : m_pFacade(pFacade)
    {

    }

    void GeMeshImpl::importFromObj(const std::string& filePath)
    {
        m_MeshData = GeMeshData();

        igl::readOBJ(filePath, V, F);
        for (unsigned int i = 0; i < V.rows(); i++) {
            m_MeshData.Vertices.emplace_back(Vec3f(V(i, 0), V(i, 1), V(i, 2)));
        }
        for (unsigned int i = 0; i < F.rows(); i++) {
            m_MeshData.Indices.emplace_back(Vec3i(F(i, 0), F(i, 1), F(i, 2)));
        }

        std::vector<Eigen::Vector3d> cor = { V.colwise().minCoeff(),V.colwise().maxCoeff() };
        m_BoundingBox.clear();
        for (unsigned int i = 0; i < 8; i++) {
            m_BoundingBox.emplace_back(Vec3f(
                cor[(i % 4 == 1) || (i % 4 == 2)].x(),
                cor[(i % 4 >= 2)].y(),
                cor[(i / 4)].z()
            ));
        }
    }

    const GeMeshData& GeMeshImpl::data() const
    {
        return m_MeshData;
    }

    const std::vector<Vec3f>& GeMeshImpl::boundingBox() const
    {
        return m_BoundingBox;
    }

}