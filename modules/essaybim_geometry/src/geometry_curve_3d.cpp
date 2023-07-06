#include "geometry_curve_3d.h"

#include "geometry_point_3d.h"

namespace EB
{
    
    std::vector<GePoint3d> GeCurve3d::sampler(float interval /*= 0.05*/) const
    {
        std::vector<GePoint3d> res;
        auto [min, max] = paramRange();
        while (min < max) {
            res.emplace_back(pointAtParam(min));
            min += interval;
        }
        res.emplace_back(pointAtParam(max));
        return res;
    }

}