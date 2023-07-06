#pragma once

#include "geometry_base_3d.h"

namespace EB
{
    class GePoint3d;

    /**
     * @brief  this class defines base class for geometry curve 3d.
     */
    class EB_GEOMETRY_EXPORT GeCurve3d : public Geometry3d
    {
    public:
        using Geometry3d::Geometry3d;

    public:
        /**
         * @brief   get standard parameter at point.
         * @param[in]   pt       point coordinate.
         * @return  standard parameter.
         */
        virtual float paramAtPoint(const GePoint3d& pt) const = 0;

        /**
         * @brief   get point coordinate at standard parameter.
         * @param[in]   param     standard parameter.
         * @return  point coordinate.
         */
        virtual GePoint3d pointAtParam(float param) const = 0;

        /**
         * @brief    get standard parameter range of curve.
         * @return    minimum and maximum range of standard parameter.
         */
        virtual std::pair<float, float> paramRange() const = 0;

        /**
         * @brief    judge if a point is on this curve.
         * @param[in]   pt        point coordinate.
         * @return     whether point is on this curve.
         */
        virtual bool isPointOnCurve(const GePoint3d& pt) const = 0;

        /**
         * @brief   sampler along the curve
         * @param[in]   interval     parameter sampler intervals
         * @return    sampled point coordinates.
         */
        std::vector<GePoint3d> sampler(float interval = 0.05) const;
    };

}