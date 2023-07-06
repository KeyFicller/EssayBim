#pragma once

#include "geometry_matrix_3d.h"

#include <glm/glm.hpp>

namespace EB
{
    class GeMatrix3dImpl
    {
    public:
        GeMatrix3dImpl(GeMatrix3d* pFacade);
        ~GeMatrix3dImpl() = default;

    public:
        GeMatrix3d& setAsTranslation(const GeVector3d& translate);
        GeMatrix3d& setAsRotation(float radians, const GeVector3d& rotateAxis);
        GeMatrix3d& setAsScale(const GeVector3d& scale);
        GeMatrix3d& setAsScaleBy(const GeVector3d& scale, const GePoint3d& ptBase);
        GeMatrix3d& setAsPlaneMatrix(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis);

    public:
        GeVector3d mult(const GeVector3d& vec) const;
        GePoint3d mult(const GePoint3d& pt) const;
        GeMatrix3d mult(const GeMatrix3d& other) const;
        GeMatrix3d inverse() const;

    protected:
        GeMatrix3d* m_pFacade = nullptr;
        glm::mat4 m_Data = glm::mat4(1.0f);
    };
}