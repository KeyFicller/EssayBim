#pragma once

#include "topological_export.h"

#include "basic_impl_template.h"

namespace EB
{
    class BrepCurveRepImpl;

    class EB_TOPOLOGICAL_EXPORT BrepCurveRep
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(BrepCurveRep)
    public:
        enum class eRepType
        {
            kIndividualCurve,
            kCurveOnSurface,
            kCurveBetweenSurface
        };

    protected:
        BrepCurveRep(eRepType type);
        BrepCurveRep(BrepCurveRepImpl& impl);
        virtual ~BrepCurveRep();

    public:
        eRepType repType() const;
    };
}