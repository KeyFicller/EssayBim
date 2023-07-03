#pragma once

#include "topological_base.h"

namespace EB
{
    class TopologicalImpl
    {
    public:
        TopologicalImpl(Topological* pFacade);
        ~TopologicalImpl() = default;

    protected:
        Topological* m_pFacade = nullptr;
    };
}