#include "topological_brep_vertex_impl.h"

namespace EB
{

    double BrepVertexImpl::tolerance() const
    {
        return m_Tolerance;
    }

    void BrepVertexImpl::setTolerance(double tol)
    {
        m_Tolerance = tol;
    }

}