#include "topological_vertex.h"

#include "topological_vertex_impl.h"

namespace EB
{

    TopoVertex::TopoVertex()
        : TopoShape(*new TopoVertexImpl(this))
    {

    }

    TopoVertex::TopoVertex(TopoVertexImpl& impl)
        : TopoShape(impl)
    {

    }

    TopoShape::eTopoShapeType TopoVertex::shapeType() const
    {
        return eTopoShapeType::kVertex;
    }

}