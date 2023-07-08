#include "geometry_utils.h"

#include "geometry_arithmetic.h"
#include "geometry_point_2d.h"
#include "geometry_curve_2d.h"
#include "geometry_line_3d.h"
#include "geometry_plane.h"

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

    GePoint3d GeIntersectUtils::intersect(const GeLine3d& line, const GePlane& plane)
    {
        GeVector3d vecLine = line.asGeVector3d();
        GeVector3d vecSO = plane.origin() - line.start();

        float lenPredSO = vecSO.dot(plane.normal());
        float lenPredLine = vecLine.dot(plane.normal());

        return line.start() + vecLine * (lenPredSO / lenPredLine);
    }

    GePoint2d GeProjectUtils::projectTo(const GePoint3d& pt, const GePlane& plane)
    {
        GeVector3d vecPO = plane.origin() - pt;
        return GePoint2d();
    }

}
