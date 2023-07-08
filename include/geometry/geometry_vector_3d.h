#pragma once

#include "geometry_export.h"
#include "basic_yaml_base.h"

namespace EB
{
    class GePoint3d;

    /**
     * @brief  this class defines geometry 3d vector.
     */
    class EB_GEOMETRY_EXPORT GeVector3d : public YamlBase
    {
    public:
        /** < x axis in 3d > */
        static const GeVector3d kXAxis;
        
        /** < y axis in 3d > */
        static const GeVector3d kYAxis;
        
        /** < z axis in 3d > */
        static const GeVector3d kZAxis;

    public:
        /**
         * @brief  constructor for GeVector2d.
         */
        GeVector3d();

        /**
         * @brief  constructor for GeVector2d.
         * @param[in]    x    x component of vector.
         * @param[in]    y    y component of vector.
         * @param[in]    z    z component of vector.
         */
        GeVector3d(float x, float y, float z);

        /**
         * @brief  constructor for GeVector2d.
         * @param[in]   vec    3 component vector.
         */
        GeVector3d(const Vec3f& vec);

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
         * @brief  get reference of z component.
         * @return    reference of z component.
         */
        float& z();

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
         * @brief  get z component.
         * @return   z component.
         */
        float z() const;

        /**
         * @brief  get vector length.
         * @return   length of vector.
         */
        float length() const;
        
        /**
         * @brief  normalize this vector.
         * @return   reference to this vector.
         */
        GeVector3d& normalize();

        /**
         * @brief  get normalized vector of this vector.
         * @return   normalized vector.
         */
        GeVector3d normalized() const;

        /**
         * @brief  normalize this vector.
         * @param[in]   factor   scale factor.
         * @return   reference to this vector.
         */
        GeVector3d& scale(float factor = 1.0f);

        /**
         * @brief  get scaled vector of this vector.
         * @param[in]   factor   scale factor.
         * @return   scaled vector.
         */
        GeVector3d scaled(float factor = 1.0f) const;

        /**
         * @brief  get dot product by other vector.
         * @param[in]   other    another vector.
         * @return    dot product.
         */
        float dot(const GeVector3d& other) const;

        /**
         * @brief  get cross product by other vector.
         * @param[in]   other    another vector.
         * @return    cross product.
         */
        GeVector3d cross(const GeVector3d& other) const;

        /**
         * @brief   get angle of two vector.
         * @param[in]   other    another vector.
         * @param[in]   ref      rotate axis 
         * @return    angle of two vector.
         */
        float angleTo(const GeVector3d& other, const GeVector3d& ref) const;

        /**
         * @brief  judge if this vector is parallel to another.
         * @param[in]   other    another vector.
         * @return   whether this vector is parallel to another.
         */
        bool isParallelTo(const GeVector3d& other) const;

        /**
         * @brief  judge if this vector is perpendicular to another.
         * @param[in]   other    another vector.
         * @return   whether this vector is perpendicular to another.
         */
        bool isPerpendicularTo(const GeVector3d& other) const;

        /**
         * @brief   convert to GePoint3d.
         * @return    point coordinate converted.
         */
        GePoint3d asGePoint3d() const;

    protected:
        /** < x component of point > */
        float m_X = 0.0;

        /** < y component of point > */
        float m_Y = 0.0;

        /** < z component of point > */
        float m_Z = 0.0;
    };
}