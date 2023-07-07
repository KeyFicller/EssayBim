#pragma once

#include "topological_edge.h"

#include "geometry_curve_3d.h"

namespace EB
{
    class EB_TOPOLOGICAL_EXPORT BrepEdge final : public TopoEdge
    {
    public:
        BrepEdge();
        ~BrepEdge() override;

    public:
        double tolerance() const;
        void setTolerance(double tol);

    };
}