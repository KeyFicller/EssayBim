#include "topological_brep_vertex.h"

#include "topological_brep_vertex_impl.h"

namespace EB
{

    BrepVertex::BrepVertex()
        : TopoVertex(* new BrepVertexImpl(this))
    {

    }

    double BrepVertex::tolerance() const
    {
        return EB_IMPL(BrepVertex)->tolerance();
    }

    void BrepVertex::setTolerance(double tol)
    {
        EB_IMPL(BrepVertex)->setTolerance(tol);
    }

}