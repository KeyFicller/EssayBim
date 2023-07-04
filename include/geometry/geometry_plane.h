#pragma once

#include "geometry_surface.h"

#include "geometry_point_3d.h"
#include "geometry_vector_3d.h"

namespace EB
{
    class GeMatrix3d;

    class EB_GEOMETRY_EXPORT GePlane : public GeSurface
    {
    public:
        static const GePlane kXY;
        static const GePlane kYZ;
        static const GePlane kXZ;

    public:
        GePlane();
        GePlane(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis);

    public:
        eGeometryType geometryType() const override;
        Geometry* copy() const override;

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
        void set(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis);
        GePoint3d origin() const;
        GeVector3d xAxis() const;
        GeVector3d yAxis() const;
        GeVector3d normal() const;
        GeMatrix3d planeToWorldMatrix() const;

    protected:
        GePoint3d m_Origin = GePoint3d::kOrigin;
        GeVector3d m_XAxis = GeVector3d::kXAxis;
        GeVector3d m_YAxis = GeVector3d::kYAxis;
    };
}