#pragma once

#include "geometry_point_2d.h"
#include "geometry_vector_2d.h"
#include "geometry_matrix_2d.h"

namespace EB
{
    // geometry 2d arithmetic
    EB_STATIC_EXPORT GeVector2d operator - (const GeVector2d& vec);
    EB_STATIC_EXPORT GeVector2d operator - (const GePoint2d& ptEnd, const GePoint2d& ptStart);
    EB_STATIC_EXPORT GePoint2d operator + (const GePoint2d& pt, const GeVector2d& vec);
    EB_STATIC_EXPORT GePoint2d operator - (const GePoint2d& pt, const GeVector2d& vec);
    EB_STATIC_EXPORT GePoint2d operator + (const GeVector2d& vec, const GePoint2d& pt);
    EB_STATIC_EXPORT GeVector2d operator + (const GeVector2d& vec1, const GeVector2d& vec2);
    EB_STATIC_EXPORT GeVector2d operator - (const GeVector2d& vec1, const GeVector2d& vec2);
    EB_STATIC_EXPORT GeVector2d operator * (const GeVector2d& vec, float scale);
    EB_STATIC_EXPORT GeVector2d operator / (const GeVector2d& vec, float scale);
    EB_STATIC_EXPORT GeVector2d operator * (float scale, const GeVector2d& vec);
    EB_STATIC_EXPORT GeVector2d operator * (const GeMatrix2d& mat, const GeVector2d& vec);
    EB_STATIC_EXPORT GeMatrix2d operator * (const GeMatrix2d& mat1, const GeMatrix2d& mat2);
}