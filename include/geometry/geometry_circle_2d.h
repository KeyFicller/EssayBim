#pragma once

#include "geometry_curve_2d.h"

namespace EB
{
    class EB_GEOMETRY_EXPORT GeCricle2d : public GeCurve2d
    {
    public:
        GeCricle2d();
        GeCricle2d(const GePoint2d& ptCenter, float radius);

    public:
        eGeometryType geometryType() const override;
        Geometry* copy() const override;
        float paramAtPoint(const GePoint2d& pt) const override;
        GePoint2d pointAtParam(float param) const override;
        std::pair<float, float> paramRange() const override;
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
        GePoint2d center() const;
        float radius() const;
        void setCenter(const GePoint2d& ptCenter);
        void setRadius(float fRadius);

    protected:
        GePoint2d m_PtCenter;
        float m_Radius = 1.0f;
    };
}