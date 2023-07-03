#pragma once

#include "topological_edge_impl.h"

namespace EB
{
    class GeCurve3d;

    class BrepEdgeImpl : public TopoEdgeImpl
    {
    public:
        using TopoEdgeImpl::TopoEdgeImpl;

    public:
        double tolerance() const;
        void setTolerance(double tol);

    protected:
        double m_Tolerance = 0.0;
    };
}