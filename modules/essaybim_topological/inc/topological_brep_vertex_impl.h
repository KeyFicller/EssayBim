#pragma once

#include "topological_vertex_impl.h"

#include "topological_brep_vertex.h"

namespace EB
{
    class BrepVertexImpl : public TopoVertexImpl
    {
    public:
        using TopoVertexImpl::TopoVertexImpl;

    public:
        double tolerance() const;
        void setTolerance(double tol);
        GePoint3d coordinate() const;
        void setCoordinate(const GePoint3d& coord);

    protected:
        double m_Tolerance = 0.0;
        GePoint3d m_Coordinate;
    };
}