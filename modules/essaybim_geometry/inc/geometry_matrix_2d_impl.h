#pragma once

#include "geometry_matrix_2d.h"

#include <glm/glm.hpp>

namespace EB
{
    class GeMatrix2dImpl
    {
    public:
        GeMatrix2dImpl(GeMatrix2d* pFacade);
        ~GeMatrix2dImpl() = default;

    public:
        GeMatrix2d& setAsTranslation(const GeVector2d& translate);
        GeMatrix2d& setAsRotation(double radians);
        GeMatrix2d& setAsScale(const GeVector2d& scale);
        GeMatrix2d& setAs(const GeVector2d& translate, double radians, const GeVector2d& scale);
        GeMatrix2d& setAsRotateBy(double radians, const GePoint2d& ptBase);
        GeMatrix2d& setAsScaleBy(const GeVector2d& scale, const GePoint2d& ptBase);
        GeMatrix2d& setAsMirrorBy(const GeLine2d& line);

    public:
        GeVector2d mult(const GeVector2d& vec) const;
        GeMatrix2d mult(const GeMatrix2d& other) const;
        GeMatrix2d inverse() const;

    protected:
        GeMatrix2d* m_pFacade = nullptr;
        glm::mat3 m_Data = glm::mat3(1.0f);
    };
}