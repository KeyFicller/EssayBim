#pragma once

#include "geometry_export.h"
#include "geometry_point_2d.h"
#include "geometry_vector_2d.h"

#include "basic_impl_template.h"

namespace EB
{
    class GeMatrix2dImpl;

    /**
     * @brief  this class defines 2d transform matrix.
     */
    class EB_GEOMETRY_EXPORT GeMatrix2d
    {
        EB_IMPL_DECLARATION_ENABLE_COPY(GeMatrix2d)
    public:
        /** < identity matrix for geometry 2d transform > */
        static const GeMatrix2d kIdentity;

    public:
        /**
         * @brief   constructor for GeMatrix2d.
         */
        GeMatrix2d();

        /**
         * @biref   destructor for GeMatrix2d.
         */
        ~GeMatrix2d();

    public:
        /**
         * @brief  set matrix as geometry translate.
         * @param[in]    translation     translate offset.
         * @return   matrix.
         */
        GeMatrix2d& setAsTranslation(const GeVector2d& translation);
        
        /**
         * @brief   set matrix as geometry rotate.
         * @param[in]    radians           rotation radians.
         * @return    matrix.
         */
        GeMatrix2d& setAsRotation(double radians);

        /**
         * @brief   set matrix as geometry scale.
         * @param[in]    scale              scale factor on X and Y.
         * @return     matrix.
         */
        GeMatrix2d& setAsScale(const GeVector2d& scale);

        /**
         * @brief   set matrix as geometry transform.
         * @param[in]    translate    geometry translate.
         * @param[in]    radians      geometry rotate.
         * @param[in]    scale        geometry scale.
         * @return    matrix.
         */
        GeMatrix2d& setAs(const GeVector2d& translate = GeVector2d(0.0f, 0.0f),
            double radians = 0.0f, const GeVector2d& scale = GeVector2d(1.0f, 1.0f));

        /**
         * @brief    set matrix as geometry rotate by base point.
         * @param[in]    radians       radians of rotate.
         * @param[in]    ptBase        point coordinate of rotate base.
         * @return    matrix.
         */
        GeMatrix2d& setAsRotateBy(double radians, const GePoint2d& ptBase = GePoint2d(0.f, 0.f));

        /**
         * @brief     set matrix as geometry scale by base point.
         * @param[in]     scale           scale factor on X and Y.
         * @param[in]     ptBase          point coordinate of scale base.
         * @return     matrix.
         */
        GeMatrix2d& setAsScaleBy(const GeVector2d& scale, const GePoint2d& ptBase = GePoint2d(0.f, 0.f));

    public:
        /**
         * @brief   matrix mult vector.
         * @param[in]    vector to transform.
         * @return    transformed vector.
         */
        GeVector2d mult(const GeVector2d& vec) const;

        /**
         * @brief   matrix mult matrix.
         * @param[in]     other     matrix right mult.
         * @return   mult matrix.
         */
        GeMatrix2d mult(const GeMatrix2d& other) const;

        /**
         * @brief   get inverse of matrix.
         * @return   inverse of matrix.
         */
        GeMatrix2d inverse() const;
    };
}