#include "geometry_matrix_3d.h"

#include "geometry_matrix_3d_impl.h"

namespace EB
{
    EB_IMPL_DEFAULT_COPY_IMPLEMENT(GeMatrix3d);

    const GeMatrix3d GeMatrix3d::kIdentity = GeMatrix3d();

    GeMatrix3d::GeMatrix3d()
    {
        EB_IMPL() = createScoped<GeMatrix3dImpl>(this);
    }

    GeMatrix3d::~GeMatrix3d()
    {
        EB_IMPL().reset();
    }

    GeMatrix3d& GeMatrix3d::setAsTranslation(const GeVector3d& translate /*= GeVector3d(0.0f, 0.0f, 0.0f)*/)
    {
        return EB_IMPL()->setAsTranslation(translate);
    }

    GeMatrix3d& GeMatrix3d::setAsRotation(float radians, const GeVector3d& rotateAxis /*= GeVector3d::kZAxis*/)
    {
        return EB_IMPL()->setAsRotation(radians, rotateAxis);
    }

    GeMatrix3d& GeMatrix3d::setAsScale(const GeVector3d& scale /*= GeVector3d(1.0f, 1.0f, 1.0f)*/)
    {
        return EB_IMPL()->setAsScale(scale);
    }

    GeMatrix3d& GeMatrix3d::setAsScaleBy(const GeVector3d& scale, const GePoint3d& ptBase /*= GePoint3d::kOrigin*/)
    {
        return EB_IMPL()->setAsScaleBy(scale, ptBase);
    }

    GeMatrix3d& GeMatrix3d::setAsPlaneMatrix(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis)
    {
        return EB_IMPL()->setAsPlaneMatrix(origin, xAxis, yAxis);
    }

    GeVector3d GeMatrix3d::mult(const GeVector3d& vec) const
    {
        return EB_IMPL()->mult(vec);
    }

    GeMatrix3d GeMatrix3d::mult(const GeMatrix3d& other) const
    {
        return EB_IMPL()->mult(other);
    }

    GeMatrix3d GeMatrix3d::inverse() const
    {
        return EB_IMPL()->inverse();
    }

}