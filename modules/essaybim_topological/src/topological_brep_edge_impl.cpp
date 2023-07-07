#include "topological_brep_edge_impl.h"

namespace EB
{

    double BrepEdgeImpl::tolerance() const
    {
        return m_Tolerance;
    }

    void BrepEdgeImpl::setTolerance(double tol)
    {
        m_Tolerance = tol;
    }

}