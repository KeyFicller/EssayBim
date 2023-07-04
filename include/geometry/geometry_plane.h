#pragma once

#include "geometry_surface.h"

#include "geometry_point_3d.h"
#include "geometry_vector_3d.h"

namespace EB
{
    class GeMatrix3d;

    /**
     * @brief   this class defines geometry plane.
     */
    class EB_GEOMETRY_EXPORT GePlane : public GeSurface
    {
    public:
        /** < gloabl x and y plane > */
        static const GePlane kXY;

        /** < gloabl y and z plane > */
        static const GePlane kYZ;

        /** < gloabl x and z plane > */
        static const GePlane kXZ;

    public:
        /**
         * @brief   constructor for GePlane.
         */
        GePlane();

        /**
         * @brief   constructor for GePlane.
         * @param[in]    origin        origin point coordinate of plane.
         * @param[in]    xAxis         x axis vector of plane.
         * @param[in]    yAxis         y axis vector of plane.
         */
        GePlane(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis);

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
         * @brief   set plane properties.
         * @param[in]    origin        origin point coordinate of plane.
         * @param[in]    xAxis         x axis vector of plane.
         * @param[in]    yAxis         y axis vector of plane.
         */
        void set(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis);

        /**
         * @brief   get origin point coordinate.
         * @return     origin point coordinate.
         */
        GePoint3d origin() const;

        /**
         * @brief   get x axis vector.
         * @return   x axis vector of plane.
         */
        GeVector3d xAxis() const;

        /**
         * @brief   get y axis vector.
         * @return    y axis vector of plane.
         */
        GeVector3d yAxis() const;

        /**
         * @brief   get normal axis of plane.
         * @return   normal vector.
         */
        GeVector3d normal() const;

        /**
         * @brief   get transform matrix from plane coordinate to global coordinate.
         * @return   matrix.
         */
        GeMatrix3d planeToWorldMatrix() const;

    protected:
        /** < origin point coordinate of plane > */
        GePoint3d m_Origin = GePoint3d::kOrigin;

        /** < x axis vector of plane > */
        GeVector3d m_XAxis = GeVector3d::kXAxis;

        /** < y axis vector of plane > */
        GeVector3d m_YAxis = GeVector3d::kYAxis;
    };
}