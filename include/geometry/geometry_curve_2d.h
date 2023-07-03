#include "geometry_base_2d.h"

namespace EB
{
    class EB_EXPORT GeCurve2d : public Geometry2d
    {
    public:
        using Geometry2d::Geometry2d;

    public:
        virtual float getParamAtPoint(const GePoint2d& pt) = 0;
        virtual GePoint2d getPointAtParam(float param) = 0;
    };
}