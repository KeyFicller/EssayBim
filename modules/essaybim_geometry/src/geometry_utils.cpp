#include "geometry_utils.h"

#include "geometry_point_2d.h"
#include "geometry_curve_2d.h"

namespace EB
{

    bool GeUtils::underTolerance(float value, float tolerance /*= 1e-6*/)
    {
        return abs(value) < tolerance;
    }

    bool GeUtils::inRange(float value, float bound1, float bound2)
    {
        return (value >= (std::min)(bound1, bound2)) &&
               (value <= (std::max)(bound1, bound2));
    }

}
