#include "topological_base.h"

#include "topological_base_impl.h"

namespace EB
{

    Topological::Topological()
    {
        EB_IMPL() = createScoped<TopologicalImpl>(this);
    }

    Topological::Topological(TopologicalImpl& impl)
    {
        EB_IMPL() = std::unique_ptr<TopologicalImpl>(&impl);
    }

    Topological::~Topological()
    {
        EB_IMPL().reset();
    }

}