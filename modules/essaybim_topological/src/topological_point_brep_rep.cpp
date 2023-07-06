#include "topological_point_brep_rep.h"

#include "topological_point_brep_rep_impl.h"

namespace EB
{

    BrepPointRep::BrepPointRep(eRepType type)
    {
        EB_IMPL() = createScoped<BrepPointRepImpl>(this, type);
    }

    BrepPointRep::BrepPointRep(BrepPointRepImpl& impl)
    {
        EB_IMPL() = std::unique_ptr<BrepPointRepImpl>(&impl);
    }

    BrepPointRep::~BrepPointRep()
    {
        EB_IMPL().reset();
    }

    BrepPointRep::eRepType BrepPointRep::repType() const
    {
        return EB_IMPL()->repType();
    }

}