#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"
#include "basic_vector.h"

namespace EB
{
    class TopologicalImpl;

    class EB_EXPORT Topological
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Topological)

    protected:
        Topological();
        Topological(TopologicalImpl& impl);
        virtual ~Topological();
    };
}