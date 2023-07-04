#pragma once

#include "topological_base_impl.h"

#include "topological_shape.h"

#include <vector>

namespace EB
{
    class TopoShapeImpl : public TopologicalImpl
    {
    public:
        using TopologicalImpl::TopologicalImpl;

    public:
        void setBit(int bit, bool isOn);
        bool hasBit(int bit);
        Geometry* geometry() const;
        void setGeometry(Geometry* pGeom);

    protected:
        int m_BitFlags = 0;
        std::vector<TopoShape*> m_Shapes;
        Geometry* m_pGeometry = nullptr;
    };
}