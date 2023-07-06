#include "topological_point_on_curve_brep_rep.h"

#include "topological_point_on_curve_brep_rep_impl.h"

namespace EB
{

    BrepPointOnCurve::BrepPointOnCurve()
        : BrepPointRep(*new BrepPointOnCurveImpl(this))
    {

    }

    BrepPointOnCurve::BrepPointOnCurve(GeCurve3d* pCurve, float parameter)
        : BrepPointRep(*new BrepPointOnCurveImpl(this, pCurve, parameter))
    {

    }

    BrepPointOnCurve::~BrepPointOnCurve()
    {

    }

    GeCurve3d* BrepPointOnCurve::curve() const
    {
        return EB_IMPL(BrepPointOnCurve)->curve();
    }

    float BrepPointOnCurve::parameter() const
    {
        return EB_IMPL(BrepPointOnCurve)->parameter();
    }

    void BrepPointOnCurve::setCurve(GeCurve3d* pCurve)
    {
        EB_IMPL(BrepPointOnCurve)->setCurve(pCurve);
    }

    void BrepPointOnCurve::setParameter(float param)
    {
        EB_IMPL(BrepPointOnCurve)->setParameter(param);
    }

}