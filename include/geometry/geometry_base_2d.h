#pragma once

#include "geometry_base.h"

namespace EB
{
    class GeMatrix2d;
    class GePoint2d;
    class GeVector2d;
    class GeLine2d;

    /**
     * @brief  this class defines base class for geometry 2d.
     */
    class EB_GEOMETRY_EXPORT Geometry2d : public Geometry
    {
    public:
        using Geometry::Geometry;

    public:
        /**
         * @brief   is geometry 2d.
         * @return    whether is geometry 2d.
         */
        bool is2D() const final { return true; }

    public:
        /**
         * @biref  apply transform matrix on 2d geometry.
         * @param[in]   mat   transform matrix.
         */
        virtual void transformBy(const GeMatrix2d& mat) = 0;

        /**
         * @brief  get transformed 2d geometry.
         * @param[in]   mat   transform matrix.
         * @return   transformed 2d geometry.
         */
        Geometry2d* transformedBy(const GeMatrix2d& mat) const;

        /**
         * @biref  apply translation on 2d geometry.
         * @param[in]   translation   translation.
         */
        void translateBy(const GeVector2d& translation);

        /**
         * @brief  get translated 2d geometry.
         * @param[in]   translation   translation.
         * @return   translated 2d geometry.
         */
        Geometry2d* translatedBy(const GeVector2d& translation) const;

        /**
         * @biref  apply rotation on 2d geometry.
         * @param[in]   radians    rotate radians.
         * @param[in]   basePoint  rotate base point.
         */
        void rotateBy(float radians, const GePoint2d& basePoint);

        /**
         * @brief  get rotated 2d geometry.
         * @param[in]   radians    rotate radians.
         * @param[in]   basePoint  rotate base point.
         * @return   rotated 2d geometry.
         */
        Geometry2d* rotatedBy(float radians, const GePoint2d& basePoint) const;

        /**
         * @biref  apply scale on 2d geometry.
         * @param[in]   factor     scale factor.
         * @param[in]   basePoint  scale base point.
         */
        void scaleBy(float factor, const GePoint2d& basePoint);

        /**
         * @brief  get scaled 2d geometry.
         * @param[in]   factor     scale factor.
         * @param[in]   basePoint  scale base point.
         * @return   scaled 2d geometry.
         */
        Geometry2d* scaledBy(float factor, const GePoint2d& basePoint) const;

        /**
         * @brief   apply mirror on 2d geometry.
         * @param[in]    line      mirror line.
         */
        void mirrorBy(const GeLine2d& line);

        /**
         * @brief   apply mirrored on 2d geometry.
         * @param[in]    line      mirror line.
         * @return   mirrored 2d geometry.
         */
        Geometry2d* mirroredBy(const GeLine2d& line) const;
    };
}