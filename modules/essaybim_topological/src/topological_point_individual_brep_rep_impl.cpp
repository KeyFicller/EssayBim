#include "topological_point_individual_brep_rep_impl.h"

namespace EB
{

    BrepPointIndividualImpl::BrepPointIndividualImpl(BrepPointRep* pFacade)
        : BrepPointRepImpl(pFacade, BrepPointRep::eRepType::kIndivialPoint)
    {

    }

    BrepPointIndividualImpl::~BrepPointIndividualImpl()
    {

    }

}