#pragma once

#include "geometry_point_2d.h"
#include "geometry_vector_2d.h"
#include "geometry_matrix_2d.h"
#include "geometry_point_3d.h"
#include "geometry_vector_3d.h"
#include "geometry_matrix_3d.h"

namespace EB
{
    // geometry 2d arithmetic
    EB_GEOMETRY_STATIC_EXPORT GeVector2d operator - (const GeVector2d& vec);
    EB_GEOMETRY_STATIC_EXPORT GeVector2d operator - (const GePoint2d& ptEnd, const GePoint2d& ptStart);
    EB_GEOMETRY_STATIC_EXPORT GePoint2d operator + (const GePoint2d& pt, const GeVector2d& vec);
    EB_GEOMETRY_STATIC_EXPORT GePoint2d operator - (const GePoint2d& pt, const GeVector2d& vec);
    EB_GEOMETRY_STATIC_EXPORT GePoint2d operator + (const GeVector2d& vec, const GePoint2d& pt);
    EB_GEOMETRY_STATIC_EXPORT GeVector2d operator + (const GeVector2d& vec1, const GeVector2d& vec2);
    EB_GEOMETRY_STATIC_EXPORT GeVector2d operator - (const GeVector2d& vec1, const GeVector2d& vec2);
    EB_GEOMETRY_STATIC_EXPORT GeVector2d operator * (const GeVector2d& vec, float scale);
    EB_GEOMETRY_STATIC_EXPORT GeVector2d operator / (const GeVector2d& vec, float scale);
    EB_GEOMETRY_STATIC_EXPORT GeVector2d operator * (float scale, const GeVector2d& vec);
    EB_GEOMETRY_STATIC_EXPORT GeVector2d operator * (const GeMatrix2d& mat, const GeVector2d& vec);
    EB_GEOMETRY_STATIC_EXPORT GeMatrix2d operator * (const GeMatrix2d& mat1, const GeMatrix2d& mat2);

    // geometry 3d arithmetic
    EB_GEOMETRY_STATIC_EXPORT GeVector3d operator - (const GeVector3d& vec);
    EB_GEOMETRY_STATIC_EXPORT GeVector3d operator - (const GePoint3d& ptEnd, const GePoint3d& ptStart);
    EB_GEOMETRY_STATIC_EXPORT GePoint3d operator + (const GePoint3d& pt, const GeVector3d& vec);
    EB_GEOMETRY_STATIC_EXPORT GePoint3d operator - (const GePoint3d& pt, const GeVector3d& vec);
    EB_GEOMETRY_STATIC_EXPORT GePoint3d operator + (const GeVector3d& vec, const GePoint3d& pt);
    EB_GEOMETRY_STATIC_EXPORT GeVector3d operator + (const GeVector3d& vec1, const GeVector3d& vec2);
    EB_GEOMETRY_STATIC_EXPORT GeVector3d operator - (const GeVector3d& vec1, const GeVector3d& vec2);
    EB_GEOMETRY_STATIC_EXPORT GeVector3d operator * (const GeVector3d& vec, float scale);
    EB_GEOMETRY_STATIC_EXPORT GeVector3d operator / (const GeVector3d& vec, float scale);
    EB_GEOMETRY_STATIC_EXPORT GeVector3d operator * (float scale, const GeVector3d& vec);
    EB_GEOMETRY_STATIC_EXPORT GeVector3d operator * (const GeMatrix3d& mat, const GeVector3d& vec);
    EB_GEOMETRY_STATIC_EXPORT GeMatrix3d operator * (const GeMatrix3d& mat1, const GeMatrix3d& mat2);

}