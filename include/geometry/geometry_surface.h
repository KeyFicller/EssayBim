#pragma once

#include "geometry_base_3d.h"

namespace EB
{
    class EB_GEOMETRY_EXPORT GeSurface : public Geometry3d
    {
    public:
        using UVParam = std::pair<float, float>;

    public:
        using Geometry3d::Geometry3d;

    public:
        /*virtual UVParam paramAtPoint(const GePoint3d& pt) const = 0;
        virtual GePoint3d& pointAtParam(const UVParam& param) const = 0;
        virtual std::pair<UVParam, UVParam> paramRange() const = 0;
        virtual bool isPointOnSurface(const GePoint3d& pt) const = 0;
        virtual std::vector<std::vector<GePoint3d>> sampler(const UVParam& uvInterval) const = 0;*/
    };
}