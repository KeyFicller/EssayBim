#pragma once

#include "geometry_export.h"
#include "basic_yaml_base.h"

namespace EB
{
    class EB_GEOMETRY_EXPORT Geometry : public YamlBase
    {
    public:
        enum class eGeometryType
        {
            kPoint2d,
            kCurve2d,
            kLine2d,
            kCircle2d,

            kPoint3d,
            kCurve3d,
            kFace3d,
            kPlane
        };

    public:
        virtual eGeometryType geometryType() const = 0;
        virtual Geometry* copy() const = 0;
    };
}