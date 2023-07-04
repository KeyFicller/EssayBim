#pragma once

#include "geometry_curve_2d.h"
#include "geometry_point_2d.h"

namespace EB
{
    class GeVector2d;

    /**
     * @brief   this class defines geometry line segment 2d.
     */
    class EB_GEOMETRY_EXPORT GeLine2d : public GeCurve2d
    {
    public:
        /**
         * @brief   constructor for line segment 2d.
         */
        GeLine2d();

        /**
         * @biref   constructor for line segment 2d.
         * @param[in]    ptStart    start point coordinate.
         * @param[in]    ptEnd      end point coordinate.
         */
        GeLine2d(const GePoint2d& ptStart, const GePoint2d& ptEnd);

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
         * @biref  get start point coordinate.
         * @return   point coordinate.
         */
        GePoint2d start() const;

        /**
         * @brief  get end point coordinate.
         * @return    point coordinate.
         */
        GePoint2d end() const;

        /**
         * @brief   set start point.
         * @param[in]   ptStart    point coordinate.
         */
        void setStart(const GePoint2d& ptStart);

        /**
         * @brief   set end point.
         * @param[in]   ptEnd      point coordinate.
         */
        void setEnd(const GePoint2d& ptEnd);

        /**
         * @brief   convert this line segment to geometry vector 2d.
         * @return    geometry vector 2d.
         */
        GeVector2d asGeVector2d() const;

    protected:
        /** < start point coordinate of line segment > */
        GePoint2d m_PtStart;

        /** < end point coordinate of line segment > */
        GePoint2d m_PtEnd;
    };
}