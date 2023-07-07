#pragma once

#include "topological_curve_brep_rep.h"

namespace EB
{
    class BrepCurveRepImpl
    {
    public:
        BrepCurveRepImpl(BrepCurveRep* pFacade, BrepCurveRep::eRepType type);
        virtual ~BrepCurveRepImpl();

    public:
        BrepCurveRep::eRepType repType() const;

    protected:
        BrepCurveRep* m_pFacade = nullptr;
        BrepCurveRep::eRepType m_Type = BrepCurveRep::eRepType::kIndividualCurve;
    };
}