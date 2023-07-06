#include "geometry_base_2d.h"

#include "geometry_matrix_2d.h"
#include "geometry_point_2d.h"
#include "geometry_vector_2d.h"

namespace EB
{
    
    Geometry2d* Geometry2d::transformedBy(const GeMatrix2d& mat) const
    {
        auto tmp = static_cast<Geometry2d*>(copy());
        tmp->transformBy(mat);
        return tmp;
    }

    void Geometry2d::translateBy(const GeVector2d& translation)
    {
        return transformBy(GeMatrix2d().setAsTranslation(translation));
    }

    Geometry2d* Geometry2d::translatedBy(const GeVector2d& translation) const
    {
        return transformedBy(GeMatrix2d().setAsTranslation(translation));
    }

    void Geometry2d::rotateBy(float radians, const GePoint2d& basePoint)
    {
        return transformBy(GeMatrix2d().setAsRotateBy(radians, basePoint));
    }

    Geometry2d* Geometry2d::rotatedBy(float radians, const GePoint2d& basePoint) const
    {
        return transformedBy(GeMatrix2d().setAsRotateBy(radians, basePoint));
    }

    void Geometry2d::scaleBy(float factor, const GePoint2d& basePoint)
    {
        return transformBy(GeMatrix2d().setAsScaleBy(GeVector2d(factor, factor), basePoint));
    }

    Geometry2d* Geometry2d::scaledBy(float factor, const GePoint2d& basePoint) const
    {
        return transformedBy(GeMatrix2d().setAsScaleBy(GeVector2d(factor, factor), basePoint));
    }

    void Geometry2d::mirrorBy(const GeLine2d& line)
    {
        return transformBy(GeMatrix2d().setAsMirrorBy(line));
    }

    Geometry2d* Geometry2d::mirroredBy(const GeLine2d& line) const
    {
        return transformedBy(GeMatrix2d().setAsMirrorBy(line));
    }

}