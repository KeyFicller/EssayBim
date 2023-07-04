#pragma once

#include "geometry_export.h"
#include "basic_yaml_base.h"

#include "geometry_point_2d.h"

namespace EB
{
    /**
     * @brief  this class defines geometry 2d vector.
     */
    class EB_GEOMETRY_EXPORT GeVector2d : public YamlBase
    {
    public:
        /** < x axis in 2d > */
        static const GeVector2d kXAxis;

        /** < y axis in 2d > */
        static const GeVector2d kYAxis;

    public:
        /**
         * @brief  constructor for GeVector2d.
         */
        GeVector2d();

        /**
         * @brief  constructor for GeVector2d.
         * @param[in]    x    x component of vector.
         * @param[in]    y    y component of vector.
         */
        GeVector2d(float x, float y);

    protected:
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
         * @brief  get reference of x component.
         * @return    reference of x component.
         */
        float& x();

        /**
         * @brief  get reference of y component.
         * @return    reference of y component.
         */
        float& y();

        /**
         * @brief  get x component.
         * @return   x component.
         */
        float x() const;

        /**
         * @brief  get y component.
         * @return   y component.
         */
        float y() const;

        /**
         * @brief  get vector length.
         * @return   length of vector.
         */
        float length() const;

        /**
         * @brief  normalize this vector.
         * @return   reference to this vector.
         */
        GeVector2d& normalize();

        /**
         * @brief  get normalized vector of this vector.
         * @return   normalized vector.
         */
        GeVector2d normalized() const;

        /**
         * @brief  normalize this vector.
         * @param[in]   factor   scale factor.
         * @return   reference to this vector.
         */
        GeVector2d& scale(float factor = 1.0f);

        /**
         * @brief  get scaled vector of this vector.
         * @param[in]   factor   scale factor.
         * @return   scaled vector.
         */
        GeVector2d scaled(float factor = 1.0f) const;

        /**
         * @brief  rotate this vector.
         * @param[in]   rad      rotate radians.
         * @return   reference to this vector.
         */
        GeVector2d& rotate(float rad);

        /**
         * @brief  get rotated vector of this vector.
         * @param[in]   rad      rotate radians.
         * @return   rotated vector.
         */
        GeVector2d rotated(float rad) const;

        /**
         * @brief  get dot product by other vector.
         * @param[in]   other    another vector.
         * @return    dot product.
         */
        float dot(const GeVector2d& other) const;

        /**
         * @brief  get cross product by other vector.
         * @param[in]   other    another vector.
         * @return    cross product.
         */
        float cross(const GeVector2d& other) const;

        /**
         * @brief  get angle contour clock wise from another vector.
         * @param[in]   other    another vector.
         * @return   angle, from 0 - 2pi.
         */
        float angleTo(const GeVector2d& other = kXAxis) const;

        /**
         * @brief  judge if this vector is parallel to another.
         * @param[in]   other    another vector.
         * @return   whether this vector is parallel to another.
         */
        bool isParallelTo(const GeVector2d& other) const;

        /**
         * @brief  judge if this vector is perpendicular to another.
         * @param[in]   other    another vector.
         * @return   whether this vector is perpendicular to another.
         */
        bool isPerpendicularTo(const GeVector2d& other) const;

        /**
         * @brief   convert to GePoint2d.
         * @return    point coordinate converted.
         */
        GePoint2d asGePoint2d() const;

    protected:
        /** < x component of point > */
        float m_X = 0.0;

        /** < y component of point > */
        float m_Y = 0.0;
    };
}