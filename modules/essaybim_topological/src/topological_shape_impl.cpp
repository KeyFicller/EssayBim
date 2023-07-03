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

}