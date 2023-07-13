#pragma once

#include "geometry_curve_3d.h"
#include "geometry_point_3d.h"

namespace EB
{
    class GeVector3d;

    /**
     * @brief   this class defines geometry line segment 3d.
     */
    class EB_GEOMETRY_EXPORT GeLine3d : public GeCurve3d
    {
    public:
        /**
         * @brief   constructor for line segment 3d.
         */
        GeLine3d();

        /**
         * @biref   constructor for line segment 3d.
         * @param[in]    ptStart    start point coordinate.
         * @param[in]    ptEnd      end point coordinate.
         */
        GeLine3d(const GePoint3d& ptStart, const GePoint3d& ptEnd);

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
        float paramAtPoint(const GePoint3d& pt) const override;

        /**
         * @brief   get point coordinate at standard parameter.
         * @param[in]   param     standard parameter.
         * @return  point coordinate.
         */
        GePoint3d pointAtParam(float param) const override;

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
        bool isPointOnCurve(const GePoint3d& pt) const override;

        /**
         * @brief   interface for override import class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlIn(const std::string& key) override;

        /**
         * @brief   interface for override export class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlOut(const std::string& key) const override;

        /**
         * @brief  dump geometry data to filer.
         * @param[in]   pFiler     filer to dump in.
         */
        void dump(Filer* pFiler) const override;

        /**
         * @brief   load geometry data from filer.
         * @param[in]   pFiler     filer to read from.
         */
        void load(Filer* pFiler) override;

    public:
        /**
         * @biref  get start point coordinate.
         * @return   point coordinate.
         */
        GePoint3d start() const;

        /**
         * @brief  get end point coordinate.
         * @return    point coordinate.
         */
        GePoint3d end() const;

        /**
         * @brief   set start point.
         * @param[in]   ptStart    point coordinate.
         */
        void setStart(const GePoint3d& ptStart);

        /**
         * @brief   set end point.
         * @param[in]   ptEnd      point coordinate.
         */
        void setEnd(const GePoint3d& ptEnd);

        /**
         * @brief   convert this line segment to geometry vector 3d.
         * @return    geometry vector 3d.
         */
        GeVector3d asGeVector3d() const;

    protected:
        /** < start point coordinate of line segment > */
        GePoint3d m_PtStart;

        /** < end point coordinate of line segment > */
        GePoint3d m_PtEnd;
    };
}