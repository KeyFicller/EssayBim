#pragma once

#include "geometry_export.h"
#include "geometry_defines.h"

#include "basic_yaml_base.h"
#include "basic_filer.h"

namespace EB
{
    /**
     * @brief  this class defines geometry base.
     */
    class EB_GEOMETRY_EXPORT Geometry : public YamlBase
    {
    public:
        /**
         * @brief  this enum specifies geometry type of final classes.
         */
        enum class eGeometryType
        {
            kPoint2d,                 /** < 2d point > */
            kLine2d,                  /** < 2d line segment > */
            kCircle2d,                /** < 2d circle > */

            kPoint3d,                 /** < 3d point > */
            kLine3d,                  /** < 3d line segment > */
            kCircle3d,                /** < 3d circle > */
            kPlane                    /** < 3d plane > */
        };

    public:
        /**
         * @brief   get geometry type.
         * @return    geometry type.
         */
        virtual eGeometryType geometryType() const = 0;

        /**
         * @brief   copy geometry.
         * @return    raw pointer to new created geometry.
         */
        virtual Geometry* copy() const = 0;

        /**
         * @brief   is geometry 2d.
         * @return    whether is geometry 2d.
         */
        virtual bool is2D() const = 0;

        /**
         * @brief  dump geometry data to filer.
         * @param[in]   pFiler     filer to dump in.
         */
        virtual void dump(Filer* pFiler) const = 0;

        /**
         * @brief   load geometry data from filer.
         * @param[in]   pFiler     filer to read from.
         */
        virtual void load(Filer* pFiler) = 0;
    };
}