#pragma once

#include "geometry_base.h"

namespace EB
{
    class EB_GEOMETRY_EXPORT GeFactory
    {
    public:
        static Geometry* create(Geometry::eGeometryType type);
    };
}