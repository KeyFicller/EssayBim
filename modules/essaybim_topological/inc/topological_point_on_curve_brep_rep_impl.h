#pragma once

#include "topological_point_brep_rep_impl.h"

#include "topological_point_on_curve_brep_rep.h"

namespace EB
{
    class BrepPointOnCurveImpl : public BrepPointRepImpl
    {
    public:
        BrepPointOnCurveImpl(BrepPointRep* pFacade);
        BrepPointOnCurveImpl(BrepPointRep* pFacade, GeCurve3d* pCurve, float parameter);

    public:
        GeCurve3d* curve() const;
        float parameter() const;
        void setCurve(GeCurve3d* pCurve);
        void setParameter(float param);

    protected:
        GeCurve3d* m_pCurve = nullptr;
        float m_Parameter = 0.0f;
    };
}