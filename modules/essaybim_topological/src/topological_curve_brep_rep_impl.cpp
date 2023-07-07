#include "topological_curve_brep_rep_impl.h"

namespace EB
{

    BrepCurveRepImpl::BrepCurveRepImpl(BrepCurveRep* pFacade, BrepCurveRep::eRepType type)
        : m_pFacade(pFacade), m_Type(type)
    {

    }

    BrepCurveRepImpl::~BrepCurveRepImpl()
    {

    }

    EB::BrepCurveRep::eRepType BrepCurveRepImpl::repType() const
    {
        return m_Type;
    }

}