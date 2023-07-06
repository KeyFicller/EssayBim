#pragma once

#include "topological_point_brep_rep.h"

namespace EB
{
    class BrepPointRepImpl
    {
    public:
        BrepPointRepImpl(BrepPointRep* pFacade, BrepPointRep::eRepType type);
        ~BrepPointRepImpl();

    public:
        BrepPointRep::eRepType repType() const;

    protected:
        BrepPointRep* m_pFacade = nullptr;
        BrepPointRep::eRepType m_Type = BrepPointRep::eRepType::kIndivialPoint;
    };
}