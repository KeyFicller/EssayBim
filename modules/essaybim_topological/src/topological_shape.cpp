#include "topological_shape.h"

#include "topological_shape_impl.h"

namespace EB
{

    TopoShape::TopoShape()
        : Topological(*new TopoShapeImpl(this))
    {
        
    }

    TopoShape::TopoShape(TopoShapeImpl& impl)
        : Topological(impl)
    {

    }

    Geometry* TopoShape::geometry() const
    {
        return EB_IMPL(TopoShape)->geometry();
    }

    void TopoShape::setGeometry(Geometry* pGeom)
    {
        EB_IMPL(TopoShape)->setGeometry(pGeom);
    }

    void TopoShape::setBit(int bit, bool isOn /*= true*/)
    {
        return EB_IMPL(TopoShape)->setBit(bit, isOn);
    }

    bool TopoShape::hasBit(int bit)
    {
        return EB_IMPL(TopoShape)->hasBit(bit);
    }

}