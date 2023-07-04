#include "topological_shape_impl.h"

#include "topological_base.h"

namespace EB
{

    void TopoShapeImpl::setBit(int bit, bool isOn)
    {
        if (isOn) {
            m_BitFlags ^= bit;
        }
        else {
            m_BitFlags &= (~bit);
        }
    }

    bool TopoShapeImpl::hasBit(int bit)
    {
        return (m_BitFlags & bit) == bit;
    }

    Geometry* TopoShapeImpl::geometry() const
    {
        return m_pGeometry;
    }

    void TopoShapeImpl::setGeometry(Geometry* pGeom)
    {
        m_pGeometry = pGeom;
    }

}