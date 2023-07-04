#include "geometry_arithmetic.h"

#include "geometry_matrix_2d_impl.h"
#include "geometry_utils.h"

#include "basic_assert.h"

#include <glm/glm.hpp>

namespace EB
{
    
    GeVector2d operator-(const GeVector2d& vec)
    {
        return GeVector2d(-vec.x(), -vec.y());
    }

    GeVector2d operator-(const GePoint2d& ptEnd, const GePoint2d& ptStart)
    {
        return GeVector2d(ptEnd.x() - ptStart.x(), ptEnd.y() - ptStart.y());
    }

    GePoint2d operator+(const GePoint2d& pt, const GeVector2d& vec)
    {
        return GePoint2d(pt.x() + vec.x(), pt.y() + vec.y());
    }

    GePoint2d operator+(const GeVector2d& vec, const GePoint2d& pt)
    {
        return pt + vec;
    }

    GePoint2d operator-(const GePoint2d& pt, const GeVector2d& vec)
    {
        return pt + (-vec);
    }

    GeVector2d operator+(const GeVector2d& vec1, const GeVector2d& vec2)
    {
        return GeVector2d(vec1.x() + vec2.x(), vec1.y() + vec2.y());
    }

    GePoint3d operator+(const GePoint3d& pt, const GeVector3d& vec)
    {
        return GePoint3d(pt.x() + vec.x(), pt.y() + vec.y(), pt.z() + vec.z());
    }

    GePoint3d operator+(const GeVector3d& vec, const GePoint3d& pt)
    {
        return pt + vec;
    }

    GeVector3d operator+(const GeVector3d& vec1, const GeVector3d& vec2)
    {
        return GeVector3d(vec1.x() + vec2.x(), vec1.y() + vec2.y(), vec1.z() + vec2.z());
    }

    GeVector2d operator-(const GeVector2d& vec1, const GeVector2d& vec2)
    {
        return vec1 + (-vec2);
    }

    GeVector2d operator*(const GeVector2d& vec, float scale)
    {
        return GeVector2d(vec.x() * scale, vec.y() * scale);
    }

    GeVector2d operator*(float scale, const GeVector2d& vec)
    {
        return vec * scale;
    }

    GeVector2d operator*(const GeMatrix2d& mat, const GeVector2d& vec)
    {
        return mat.mult(vec);
    }

    GeMatrix2d operator*(const GeMatrix2d& mat1, const GeMatrix2d& mat2)
    {
        return mat1.mult(mat2);
    }

    GeVector3d operator*(const GeVector3d& vec, float scale)
    {
        return vec.scaled(scale);
    }

    GeVector3d operator*(float scale, const GeVector3d& vec)
    {
        return vec * scale;
    }

    GeVector3d operator*(const GeMatrix3d& mat, const GeVector3d& vec)
    {
        return mat.mult(vec);
    }

    GeMatrix3d operator*(const GeMatrix3d& mat1, const GeMatrix3d& mat2)
    {
        return mat1.mult(mat2);
    }

    GeVector2d operator/(const GeVector2d& vec, float scale)
    {
        EB_CORE_ASSERT(!GeUtils::underTolerance(scale));
        return vec * (1.0f / scale);
    }

    GeVector3d operator/(const GeVector3d& vec, float scale)
    {
        EB_CORE_ASSERT(!GeUtils::underTolerance(scale));
        return vec * (1.0f / scale);
    }

    GeVector3d operator-(const GeVector3d& vec)
    {
        return GeVector3d(-vec.x(), -vec.y(), -vec.z());
    }

    GeVector3d operator-(const GePoint3d& ptEnd, const GePoint3d& ptStart)
    {
        return GeVector3d(ptEnd.x() - ptStart.x(), ptEnd.y() - ptStart.y(), ptEnd.z() - ptStart.z());
    }

    GePoint3d operator-(const GePoint3d& pt, const GeVector3d& vec)
    {
        return pt + (-vec);
    }

    GeVector3d operator-(const GeVector3d& vec1, const GeVector3d& vec2)
    {
        return vec1 + (-vec2);
    }

}
