#include "geometry_mesh_impl.h"


#include "geometry_libigl_disable_warning.h"
#include <Eigen/Core>
#include <igl/readOBJ.h>

namespace EB
{

    GeMeshImpl::GeMeshImpl(GeMesh* pFacade)
        : m_pFacade(pFacade)
    {

    }

    void GeMeshImpl::importFromObj(const std::string& filePath)
    {
        m_MeshData.clear();
        Eigen::MatrixXd V;
        Eigen::MatrixXi F;

        igl::readOBJ(filePath, V, F);
        for (unsigned int i = 0; i < V.rows(); i++) {
            m_MeshData.Vertices.emplace_back(Vec3f(V(i, 0), V(i, 1), V(i, 2)));
        }
        for (unsigned int i = 0; i < F.rows(); i++) {
            m_MeshData.Indices.emplace_back(Vec3i(F(i, 0), F(i, 1), F(i, 2)));
        }
    }

    const GeMeshData& GeMeshImpl::data() const
    {
        return m_MeshData;
    }

}