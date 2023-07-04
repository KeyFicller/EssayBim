#pragma once

#include "geometry_curve_2d.h"

namespace EB
{
    /**
     * @brief  this class defines geometry circle 2d.
     */
    class EB_GEOMETRY_EXPORT GeCricle2d : public GeCurve2d
    {
    public:
        /**
         * @brief  constructor for GeCircle2d.
         */
        GeCricle2d();

        /**
         * @brief  constructor for GeCircle2d.
         * @param[in]  ptCenter    center point coordinate.
         * @param[in]  radius      radius of circle.
         */
        GeCricle2d(const GePoint2d& ptCenter, float radius);

    public:
        /**
         * @brief   get geometry type.
         * @return    geometry type.
         */
        eGeometryType geometryType() const override;

        /**
         * @brief   copy geometry.
         * @return    raw pointer to new created geometry.
         */
        Geometry* copy() const override;

        /**
         * @brief   get standard parameter at point.
         * @param[in]   pt       point coordinate.
         * @return  standard parameter.
         */
        float paramAtPoint(const GePoint2d& pt) const override;

        /**
         * @brief   get point coordinate at standard parameter.
         * @param[in]   param     standard parameter.
         * @return  point coordinate.
         */
        GePoint2d pointAtParam(float param) const override;

        /**
         * @brief    get standard parameter range of curve.
         * @return    minimum and maximum range of standard parameter.
         */
        std::pair<float, float> paramRange() const override;

        /**
         * @brief    judge if a point is on this curve.
         * @param[in]   pt        point coordinate.
         * @return     whether point is on this curve.
         */
        bool isPointOnCurve(const GePoint2d& pt) const override;

        /**
         * @brief   interface for override import class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlIn(const std::string& key) override;

        /**
         * @brief   interface for override export class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlOut(const std::string& key) override;

    public:
        /**
         * @brief     get center point.
         * @return     point coordinate.
         */
        GePoint2d center() const;

        /**
         * @brief    get radius.
         * @return    radius.
         */
        float radius() const;

        /**
         * @brief   set center point.
         * @param[in]   ptCenter   point coordinate.
         */
        void setCenter(const GePoint2d& ptCenter);
        
        /**
         * @brief   set radius,
         * @param[in]   radius     radius.
         */
        void setRadius(float fRadius);

    protected:
        /** < center point coordinate of circle > */
        GePoint2d m_PtCenter;

        /** < radius of circle > */
        float m_Radius = 1.0f;
    };
}