#pragma once

#include "geometry_point_3d.h"

#include "topological_vertex.h"

namespace EB
{
    class EB_TOPOLOGICAL_EXPORT BrepVertex final : public TopoVertex
    {
    public:
        BrepVertex();
        ~BrepVertex() override = default;

    public:
        double tolerance() const;
        void setTolerance(double tol);
        GePoint3d coordinate() const;
        void setCoordinate(const GePoint3d& coord);
    };
}