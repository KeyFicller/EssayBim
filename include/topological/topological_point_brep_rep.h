#pragma once

#include "topological_export.h"

#include "basic_impl_template.h"

namespace EB
{
    class BrepPointRepImpl;

    class EB_TOPOLOGICAL_EXPORT BrepPointRep
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(BrepPointRep)
    public:
        enum class eRepType
        {
            kIndivialPoint,
            kPointOnCurve,
            kPointOnSurface
        };

    protected:
        BrepPointRep(eRepType type);
        BrepPointRep(BrepPointRepImpl& impl);
        virtual ~BrepPointRep();

    public:
        eRepType repType() const;
    };
}