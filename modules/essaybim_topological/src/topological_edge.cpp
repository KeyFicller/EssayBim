#include "topological_edge.h"

#include "topological_edge_impl.h"

namespace EB
{

    TopoEdge::TopoEdge()
        : TopoShape(*new TopoEdgeImpl(this))
    {

    }

    TopoEdge::TopoEdge(TopoEdgeImpl& impl)
        : TopoShape(impl)
    {

    }

    TopoShape::eTopoShapeType TopoEdge::shapeType() const
    {
        return eTopoShapeType::kEdge;
    }

}