#pragma once

#include "geometry_export.h"
#include "basic_impl_template.h"
#include "geometry_vector_2d.h"

namespace EB
{
    class GeMatrix2dImpl;

    class EB_GEOMETRY_EXPORT GeMatrix2d
    {
        EB_IMPL_DECLARATION_ENABLE_COPY(GeMatrix2d)
    public:
        static const GeMatrix2d kIdentity;

    public:
        GeMatrix2d();
        ~GeMatrix2d();

    public:
        GeMatrix2d& setAsTranslation(const GeVector2d& translation);
        GeMatrix2d& setAsRotation(double radians);
        GeMatrix2d& setAsScale(const GeVector2d& scale);
        GeMatrix2d& setAs(const GeVector2d& translate = GeVector2d(0.0f, 0.0f),
            double radians = 0.0f, const GeVector2d& scale = GeVector2d(1.0f, 1.0f));
        GeMatrix2d& setAsRotateBy(double radians, const GePoint2d& ptBase = GePoint2d(0.f, 0.f));
        GeMatrix2d& setAsScaleBy(const GeVector2d& scale, const GePoint2d& ptBase = GePoint2d(0.f, 0.f));

    public:
        GeVector2d mult(const GeVector2d& vec) const;
        GeMatrix2d mult(const GeMatrix2d& other) const;
        GeMatrix2d inverse() const;
    };
}