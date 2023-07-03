#pragma once

#include "topological_vertex_impl.h"

namespace EB
{
    class BrepVertexImpl : public TopoVertexImpl
    {
    public:
        using TopoVertexImpl::TopoVertexImpl;

    public:
        double tolerance() const;
        void setTolerance(double tol);

    protected:
        double m_Tolerance = 0.0;
    };
}