#include "topological_point_on_curve_brep_rep_impl.h"

namespace EB
{

    BrepPointOnCurveImpl::BrepPointOnCurveImpl(BrepPointRep* pFacade)
        : BrepPointRepImpl(pFacade, BrepPointRep::eRepType::kPointOnCurve), m_pCurve(nullptr), m_Parameter(0.0f)
    {

    }

    BrepPointOnCurveImpl::BrepPointOnCurveImpl(BrepPointRep* pFacade, GeCurve3d* pCurve, float parameter)
        : BrepPointRepImpl(pFacade, BrepPointRep::eRepType::kPointOnCurve), m_pCurve(pCurve), m_Parameter(parameter)
    {

    }

    GeCurve3d* BrepPointOnCurveImpl::curve() const
    {
        return m_pCurve;
    }

    float BrepPointOnCurveImpl::parameter() const
    {
        return m_Parameter;
    }

    void BrepPointOnCurveImpl::setCurve(GeCurve3d* pCurve)
    {
        m_pCurve = pCurve;
    }

    void BrepPointOnCurveImpl::setParameter(float param)
    {
        m_Parameter = param;
    }

}