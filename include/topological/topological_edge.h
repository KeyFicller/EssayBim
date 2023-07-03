#pragma once

#include "topological_shape.h"

namespace EB
{
    class TopoEdgeImpl;

    class EB_EXPORT TopoEdge : public TopoShape
    {
    public:
        TopoEdge();
        TopoEdge(TopoEdgeImpl& impl);
        ~TopoEdge() override = default;
    };
}