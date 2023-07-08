#pragma once

#include "geometry_base_3d.h"

namespace EB
{
    class GeMatrix3d;

    /**
     * @brief  this class defines geometry 3d point.
     */
    class EB_GEOMETRY_EXPORT GePoint3d : public Geometry3d
    {
    public:
        /** < origin point in 3d > */
        static const GePoint3d kOrigin;
    public:
        /**
         * @brief  constructor for GePoint3d.
         */
        GePoint3d();

        /**
         * @brief  constructor for GePoint3d.
         * @param[in]    x    x coordinate.
         * @param[in]    y    y coordinate.
         * @param[in]    z    z coordinate.
         */
        GePoint3d(float x, float y, float z);

        /**
         * @brief  constructor for GePoint3d.
         * @param[in]   vec    3 component vector
         */
        GePoint3d(const Vec3f& vec);

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
         * @brief  get reference of z coordinate.
         * @return    reference of z coordinate.
         */
        float& z();

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
         * @brief  get z coordinate.
         * @return   z coordinate.
         */
        float z() const;

        /**
         * @brief  get distance to another point.
         * @param[in]   ptOther   point coordinate of another point.
         * @return   distance.
         */
        float distanceTo(const GePoint3d& ptOther) const;

        /**
         * @brief  transfer this point by matrix.
         * @param[in]   mat        transform matrix.
         * @return   reference to this point.
         */
        GePoint3d& transformBy(const GeMatrix3d& mat);

        /**
         * @brief   get transfered point by matrix.
         * @param[in]   mat        transform matrix.
         * @return    transfered point coordinate.
         */
        GePoint3d transformedBy(const GeMatrix3d& mat) const;

        /**
         * @brief   implicit cast to vector float 3.
         */
        operator Vec3f() const;

        /**
         * @brief   implicit cast to vector float 3.
         */
        operator Vec3f& ();

    protected:
        /** < x coordinate of point > */
        float m_X = 0.0;

        /** < y coordinate of point > */
        float m_Y = 0.0;

        /** < z coordinate of point > */
        float m_Z = 0.0;
    };
}