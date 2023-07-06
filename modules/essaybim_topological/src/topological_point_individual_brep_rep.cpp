#include "topological_point_individual_brep_rep.h"

#include "topological_point_individual_brep_rep_impl.h"

namespace EB
{

    BrepPointIndividual::BrepPointIndividual()
        : BrepPointRep(*new BrepPointIndividualImpl(this))
    {

    }

    BrepPointIndividual::~BrepPointIndividual()
    {

    }

}