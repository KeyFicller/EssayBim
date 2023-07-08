#pragma once

#include "geometry_export.h"

namespace EB
{
    class GePoint2d;
    class GePoint3d;
    class GeCurve2d;
    class GeLine3d;
    class GePlane;

    /**
     * @brief  this class defines geometry utility.
     */
    class EB_GEOMETRY_EXPORT GeUtils
    {
    public:
        /**
         * @brief  judge error is under tolerance.
         * @param[in]   value       error to judge.
         * @param[in]   tolerance   error tolerance.
         * return   whether error is under tolerance.
         */
        static bool underTolerance(float value, float tolerance = 1e-6);

        /**
         * @brief  judge value is in boundary.
         * @param[in]    value     value to judge.
         * @param[in]    bound1    lower or upper boundary.
         * @param[in]    bound2    lower or upper boundary.
         * @return  whether value is in range.
         */
        static bool inRange(float value, float bound1, float bound2);
    };

    /**
     * @brief   this class is used for Intersection calculation.
     */
    class EB_GEOMETRY_EXPORT GeIntersectUtils
    {
    public:
        /**
         * @brief  calculate intersection of line and plane.
         */
        static GePoint3d intersect(const GeLine3d& line, const GePlane& plane);
    };


    class EB_GEOMETRY_EXPORT GeProjectUtils
    {
    public:
        /**
         * @brief   calculate projection of point to plane.
         */
        static GePoint2d projectTo(const GePoint3d& pt, const GePlane& plane);
    };
    
}