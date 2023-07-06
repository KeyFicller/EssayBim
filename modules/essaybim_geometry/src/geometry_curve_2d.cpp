#include "geometry_curve_2d.h"

namespace EB
{

    std::vector<GePoint2d> GeCurve2d::sampler(float interval /*= 0.05*/) const
    {
        std::vector<GePoint2d> res;
        auto [min, max] = paramRange();
        while (min < max) {
            res.emplace_back(pointAtParam(min));
            min += interval;
        }
        res.emplace_back(pointAtParam(max));
        return res;
    }

}