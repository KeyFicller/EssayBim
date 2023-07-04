#include "geometry_base_2d.h"

#include "geometry_point_2d.h"

namespace EB
{
    class EB_GEOMETRY_EXPORT GeCurve2d : public Geometry2d
    {
    public:
        using Geometry2d::Geometry2d;

    public:
        virtual float paramAtPoint(const GePoint2d& pt) const = 0;
        virtual GePoint2d pointAtParam(float param) const = 0;
        virtual std::pair<float, float> paramRange() const = 0;
        virtual bool isPointOnCurve(const GePoint2d& pt) const = 0;
    };
}