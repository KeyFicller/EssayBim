#include "topological_brep_edge.h"

#include "topological_brep_edge_impl.h"

namespace EB
{

    BrepEdge::BrepEdge()
        : TopoEdge(* new BrepEdgeImpl(this))
    {

    }

    BrepEdge::~BrepEdge()
    {

    }

    double BrepEdge::tolerance() const
    {
        return EB_IMPL(BrepEdge)->tolerance();
    }

    void BrepEdge::setTolerance(double tol)
    {
        EB_IMPL(BrepEdge)->setTolerance(tol);
    }

}