#include "geometry_matrix_2d.h"

#include "geometry_matrix_2d_impl.h"

namespace EB
{
    EB_IMPL_DEFAULT_COPY_IMPLEMENT(GeMatrix2d)

    const GeMatrix2d GeMatrix2d::kIdentity = GeMatrix2d();

    GeMatrix2d::GeMatrix2d()
    {
        EB_IMPL() = createScoped<GeMatrix2dImpl>(this);
    }

    GeMatrix2d::~GeMatrix2d()
    {
        EB_IMPL().reset();
    }

    GeMatrix2d& GeMatrix2d::setAsTranslation(const GeVector2d& translation)
    {
        return EB_IMPL()->setAsTranslation(translation);
    }

    GeMatrix2d& GeMatrix2d::setAsRotation(double radians)
    {
        return EB_IMPL()->setAsRotation(radians);
    }

    GeMatrix2d& GeMatrix2d::setAsScale(const GeVector2d& scale)
    {
        return EB_IMPL()->setAsScale(scale);
    }

    GeMatrix2d& GeMatrix2d::setAs(const GeVector2d& translate, double radians, const GeVector2d& scale)
    {
        return EB_IMPL()->setAs(translate, radians, scale);
    }

    GeMatrix2d& GeMatrix2d::setAsRotateBy(double radians, const GePoint2d& ptBase /*= GePoint2d(0.f, 0.f)*/)
    {
        return EB_IMPL()->setAsRotateBy(radians, ptBase);
    }

    GeMatrix2d& GeMatrix2d::setAsScaleBy(const GeVector2d& scale, const GePoint2d& ptBase /*= GePoint2d(0.f, 0.f)*/)
    {
        return EB_IMPL()->setAsScaleBy(scale, ptBase);
    }

    GeMatrix2d GeMatrix2d::mult(const GeMatrix2d& other) const
    {
        return EB_IMPL()->mult(other);
    }

    GeVector2d GeMatrix2d::mult(const GeVector2d& vec) const
    {
        return EB_IMPL()->mult(vec);
    }

    GeMatrix2d GeMatrix2d::inverse() const
    {
        return EB_IMPL()->inverse();
    }

}