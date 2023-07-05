#pragma once

#include "geometry_export.h"
#include "geometry_point_3d.h"
#include "geometry_vector_3d.h"

#include "basic_impl_template.h"

namespace EB
{
    class GeMatrix3dImpl;

    /**
     * @brief  this class defines 3d transform matrix.
     */
    class EB_GEOMETRY_EXPORT GeMatrix3d
    {
        EB_IMPL_DECLARATION_ENABLE_COPY(GeMatrix3d)
    public:
        /** < identity matrix for geometry 3d transform > */
        static const GeMatrix3d kIdentity;

    public:
        /**
         * @brief   constructor for GeMatrix2d.
         */
        GeMatrix3d();

        /**
         * @biref   destructor for GeMatrix2d.
         */
        ~GeMatrix3d();

    public:
        /**
         * @brief  set matrix as geometry translate.
         * @param[in]    translation     translate offset.
         * @return   matrix.
         */
        GeMatrix3d& setAsTranslation(const GeVector3d& translate = GeVector3d(0.0f, 0.0f, 0.0f));

        /**
         * @brief    set matrix as geometry rotate by given vector.
         * @param[in]    radians       radians of rotate.
         * @param[in]    rotateAxis    axis vector of rotate base.
         * @return    matrix.
         */
        GeMatrix3d& setAsRotation(float radians, const GeVector3d& rotateAxis = GeVector3d::kZAxis);

        /**
         * @brief   set matrix as geometry scale.
         * @param[in]    scale              scale factor on X, Y and Z.
         * @return     matrix.
         */
        GeMatrix3d& setAsScale(const GeVector3d& scale = GeVector3d(1.0f, 1.0f, 1.0f));

        /**
         * @brief     set matrix as geometry scale by base point.
         * @param[in]     scale           scale factor on X, Y and Z.
         * @param[in]     ptBase          point coordinate of scale base.
         * @return     matrix.
         */
        GeMatrix3d& setAsScaleBy(const GeVector3d& scale, const GePoint3d& ptBase = GePoint3d::kOrigin);

        /**
         * @brief    set matrix as transform matrix from global coordinate to plane coordinate.
         * @param[in]    origin        origin point coordinate of plane.
         * @param[in]    xAxis         x axis vector of plane.
         * @param[in]    yAxis         y axis vector of plane.
         */
        GeMatrix3d& setAsPlaneMatrix(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis);

    public:
        /**
         * @brief   matrix mult vector.
         * @param[in]    vector to transform.
         * @return    transformed vector.
         */
        GeVector3d mult(const GeVector3d& vec) const;

        /**
         * @brief   matrix mult matrix.
         * @param[in]     other     matrix right mult.
         * @return   mult matrix.
         */
        GeMatrix3d mult(const GeMatrix3d& other) const;

        /**
         * @brief   get inverse of matrix.
         * @return   inverse of matrix.
         */
        GeMatrix3d inverse() const;
    };
}