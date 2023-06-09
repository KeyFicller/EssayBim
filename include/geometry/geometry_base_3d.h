#pragma once

#include "geometry_base.h"

namespace EB
{
    /**
     * @brief  this class defines base class for geometry 3d.
     */
    class EB_GEOMETRY_EXPORT Geometry3d : public Geometry
    {
    public:
        using Geometry::Geometry;

    public:
        /**
         * @brief   is geometry 2d.
         * @return    whether is geometry 2d.
         */
        bool is2D() const final { return false; }
    };
}