#include "topological_curve_brep_rep.h"

#include "topological_curve_brep_rep_impl.h"

namespace EB
{

    BrepCurveRep::BrepCurveRep(eRepType type)
    {
        EB_IMPL() = createScoped<BrepCurveRepImpl>(this, type);
    }

    BrepCurveRep::BrepCurveRep(BrepCurveRepImpl& impl)
    {
        EB_IMPL() = std::unique_ptr<BrepCurveRepImpl>(&impl);
    }

    BrepCurveRep::~BrepCurveRep()
    {

    }

    EB::BrepCurveRep::eRepType BrepCurveRep::repType() const
    {
        return EB_IMPL(BrepCurveRep)->repType();
    }

}