#pragma once

#include "geometry_export.h"
#include "basic_impl_template.h"
#include "geometry_vector_3d.h"

namespace EB
{
    class GeMatrix3dImpl;

    class EB_GEOMETRY_EXPORT GeMatrix3d
    {
        EB_IMPL_DECLARATION_ENABLE_COPY(GeMatrix3d)
    public:
        static const GeMatrix3d kIdentity;

    public:
        GeMatrix3d();
        ~GeMatrix3d();

    public:
        GeMatrix3d& setAsTranslation(const GeVector3d& translate = GeVector3d(0.0f, 0.0f, 0.0f));
        GeMatrix3d& setAsRotation(float radians, const GeVector3d& rotateAxis = GeVector3d::kZAxis);
        GeMatrix3d& setAsScale(const GeVector3d& scale = GeVector3d(1.0f, 1.0f, 1.0f));
        GeMatrix3d& setAsScaleBy(const GeVector3d& scale, const GePoint3d& ptBase = GePoint3d::kOrigin);
        GeMatrix3d& setAsPlaneMatrix(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis);

    public:
        GeVector3d mult(const GeVector3d& vec) const;
        GeMatrix3d mult(const GeMatrix3d& other) const;
        GeMatrix3d inverse() const;
    };
}