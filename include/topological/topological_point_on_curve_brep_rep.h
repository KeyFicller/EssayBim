#pragma once

#include "topological_point_brep_rep.h"

#include "geometry_curve_3d.h"

namespace EB
{
    class EB_TOPOLOGICAL_EXPORT BrepPointOnCurve : public BrepPointRep
    {
    public:
        BrepPointOnCurve();
        BrepPointOnCurve(GeCurve3d* pCurve, float parameter);
        ~BrepPointOnCurve() override;

    public:
        GeCurve3d* curve() const;
        float parameter() const;
        void setCurve(GeCurve3d* pCurve);
        void setParameter(float param);
    };
}