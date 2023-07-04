#pragma once

#include "geometry_export.h"

namespace EB
{
    class GePoint2d;
    class GeCurve2d;

    class EB_GEOMETRY_EXPORT GeUtils
    {
    public:
        static bool underTolerance(float value, float tolerance = 1e-6);
        static bool inRange(float value, float bound1, float bound2);
    };
}