#pragma once

#include "geometry_base_2d.h"

namespace EB
{
    class GeMatrix2d;
    class GePoint3d;
    class GePlane;

    /**
     * @brief  this class defines geometry 2d point.
     */
    class EB_GEOMETRY_EXPORT GePoint2d : public Geometry2d
    {
    public:
        /** < origin point in 2d > */
        static const GePoint2d kOrigin;
    public:
        /**
         * @brief  constructor for GePoint2d.
         */
        GePoint2d();

        /**
         * @brief  constructor for GePoint2d.
         * @param[in]    x    x coordinate.
         * @param[in]    y    y coordinate.
         */
        GePoint2d(float x, float y);

        /**
         * @brief  constructor for GePoint2d.
         * @param[in]   vec    2 component vector.
         */
        GePoint2d(const Vec2f& vec);
        
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
         * @brief  get reference of x coordinate.
         * @return    reference of x coordinate.
         */
        float& x();

        /**
         * @brief  get reference of y coordinate.
         * @return    reference of y coordinate.
         */
        float& y();

        /**
         * @brief  get x coordinate.
         * @return   x coordinate.
         */
        float x() const;

        /**
         * @brief  get y coordinate.
         * @return   y coordinate.
         */
        float y() const;

        /**
         * @brief  get distance to another point.
         * @param[in]   ptOther   point coordinate of another point.
         * @return   distance.
         */
        float distanceTo(const GePoint2d& ptOther) const;

        /**
         * @biref  apply transform matrix on 2d geometry.
         * @param[in]   mat   transform matrix.
         */
        void transformBy(const GeMatrix2d& mat) override;

        /**
         * @brief  get 3d coordinate.
         * @param[in]   plane  2d point plane
         */
        GePoint3d to3D(GePlane plane) const;

        /**
         * @brief   implicit cast to vector float 2.
         */
        operator Vec2f() const;

    protected:
        /** < x coordinate of point > */
        float m_X = 0.0;

        /** < y coordinate of point > */
        float m_Y = 0.0;
    };
}