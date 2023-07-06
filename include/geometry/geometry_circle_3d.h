#pragma once

#include "geometry_curve_3d.h"
#include "geometry_point_3d.h"
#include "geometry_vector_3d.h"

namespace EB
{
    /**
     * @brief  this class defines geometry circle 3d.
     */
    class EB_GEOMETRY_EXPORT GeCircle3d : public GeCurve3d
    {
    public:
        /**
         * @brief  constructor for GeCircle3d.
         */
        GeCircle3d();

        /**
         * @brief  constructor for GeCircle3d.
         * @param[in]  ptCenter    center point coordinate.
         * @param[in]  radius      radius of circle.
         * @param[in]  normal      normal vector of circle 3d.
         * @param[in]  ref         ref vector of circle at param 0.
         */
        GeCircle3d(const GePoint3d& ptCenter, float radius,
            const GeVector3d& normal, const GeVector3d& ref = GeVector3d::kXAxis);

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
        void subYamlOut(const std::string& key) override;

    public:
        /**
         * @brief     get center point.
         * @return     point coordinate.
         */
        GePoint3d center() const;

        /**
         * @brief    get radius.
         * @return    radius.
         */
        float radius() const;

        /**
         * @brief     get normal vector.
         * @return     normal vector.
         */
        GeVector3d normal() const;

        /**
         * @brief   set center point.
         * @param[in]   ptCenter   point coordinate.
         */
        void setCenter(const GePoint3d& ptCenter);
        
        /**
         * @brief   set radius.
         * @param[in]   radius     radius.
         */
        void setRadius(float fRadius);

        /**
         * @brief   set normal vector.
         * @param[in]   vecNorm     normal vector.
         */
        void setNormal(const GeVector3d& vecNorm);

    protected:
        /** < center point coordinate of circle > */
        GePoint3d m_PtCenter = GePoint3d::kOrigin;

        /** < radius of circle > */
        float m_Radius = 1.0f;

        /** < normal vector of circle > */
        GeVector3d m_Normal = GeVector3d::kZAxis;

        /** < vector of circle at param 0 > */
        GeVector3d m_Ref = GeVector3d::kXAxis;
    };
}