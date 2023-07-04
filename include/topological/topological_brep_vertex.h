#pragma once

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
    };
}