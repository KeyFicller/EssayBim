#pragma once

#include "topological_point_brep_rep.h"

namespace EB
{
    class EB_TOPOLOGICAL_EXPORT BrepPointIndividual final : public BrepPointRep
    {
    public:
        BrepPointIndividual();
        ~BrepPointIndividual() override;
    };
}