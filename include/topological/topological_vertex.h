#pragma once

#include "topological_shape.h"

namespace EB
{
    class TopoVertexImpl;

    class EB_EXPORT TopoVertex : public TopoShape
    {
    public:
        TopoVertex();
        TopoVertex(TopoVertexImpl& impl);
        ~TopoVertex() override = default;

    public:
        eTopoShapeType shapeType() const override;
    };
}