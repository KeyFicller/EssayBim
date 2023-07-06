#include "topological_point_brep_rep_impl.h"

namespace EB
{

    BrepPointRepImpl::BrepPointRepImpl(BrepPointRep* pFacade, BrepPointRep::eRepType type)
        : m_pFacade(pFacade), m_Type(type)
    {

    }

    BrepPointRepImpl::~BrepPointRepImpl()
    {

    }

    BrepPointRep::eRepType BrepPointRepImpl::repType() const
    {
        return m_Type;
    }

}