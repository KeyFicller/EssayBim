#pragma once

#include "geometry_curve_2d.h"
#include "geometry_point_2d.h"

namespace EB
{
    class GeVector2d;

    class EB_GEOMETRY_EXPORT GeLine2d : public GeCurve2d
    {
    public:
        GeLine2d();
        GeLine2d(const GePoint2d& ptStart, const GePoint2d& ptEnd);

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
        GePoint2d start() const;
        GePoint2d end() const;
        void setStart(const GePoint2d& ptStart);
        void setEnd(const GePoint2d& ptEnd);
        GeVector2d asGeVector2d() const;

    protected:
        GePoint2d m_PtStart;
        GePoint2d m_PtEnd;
    };
}