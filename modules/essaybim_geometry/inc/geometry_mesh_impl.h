#pragma once

#include "geometry_mesh.h"

namespace EB
{
    class GeMeshImpl
    {
    public:
        GeMeshImpl(GeMesh* pFacade);

    public:
        void importFromObj(const std::string& filePath);
        const GeMeshData& data() const;

    protected:
        GeMesh* m_pFacade = nullptr;
        GeMeshData m_MeshData;
    };
}