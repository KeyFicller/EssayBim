#include "geometry_base_2d.h"

#include "geometry_point_2d.h"

namespace EB
{
    /**
     * @brief  this class defines base class for geometry curve 2d.
     */
    class EB_GEOMETRY_EXPORT GeCurve2d : public Geometry2d
    {
    public:
        using Geometry2d::Geometry2d;

    public:
        /**
         * @brief   get standard parameter at point.
         * @param[in]   pt       point coordinate.
         * @return  standard parameter.
         */
        virtual float paramAtPoint(const GePoint2d& pt) const = 0;

        /**
         * @brief   get point coordinate at standard parameter.
         * @param[in]   param     standard parameter.
         * @return  point coordinate.
         */
        virtual GePoint2d pointAtParam(float param) const = 0;

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
        virtual bool isPointOnCurve(const GePoint2d& pt) const = 0;
    };
}