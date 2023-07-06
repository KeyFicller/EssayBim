#pragma once

#include "topological_point_brep_rep_impl.h"
#include "topological_point_individual_brep_rep.h"

namespace EB
{
    class BrepPointIndividualImpl : public BrepPointRepImpl
    {
    public:
        BrepPointIndividualImpl(BrepPointRep* pFacade);
        ~BrepPointIndividualImpl();
    };
}