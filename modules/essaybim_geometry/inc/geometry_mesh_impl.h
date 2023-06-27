#pragma once

#include "geometry_mesh.h"

#pragma warning(disable: 4819)
#include <Eigen/Core>

namespace EB
{
    class GeMeshImpl
    {
    public:
        GeMeshImpl(GeMesh* pFacade);

    public:
        void importFromObj(const std::string& filePath);
        const GeMeshData& data() const;
        const std::vector<Vec3f>& boundingBox() const;

    protected:
        GeMesh* m_pFacade = nullptr;
        GeMeshData m_MeshData;
        std::vector<Vec3f> m_BoundingBox;

        // raw data
        Eigen::MatrixXd V;
        Eigen::MatrixXi F;
    };
}