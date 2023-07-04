#include "geometry_matrix_3d_impl.h"

#include <glm/gtc/matrix_transform.hpp>

namespace EB
{

    GeMatrix3dImpl::GeMatrix3dImpl(GeMatrix3d* pFacade)
        : m_pFacade(pFacade)
    {

    }

    GeMatrix3d& GeMatrix3dImpl::setAsTranslation(const GeVector3d& translate)
    {
        m_Data = glm::translate(glm::mat4(1.0f), glm::vec3(translate.x(), translate.y(), translate.z()));
        return *m_pFacade;
    }

    GeMatrix3d& GeMatrix3dImpl::setAsRotation(float radians, const GeVector3d& rotateAxis)
    {
        m_Data = glm::rotate(glm::mat4(1.0f), radians, glm::vec3(rotateAxis.x(), rotateAxis.y(), rotateAxis.z()));
        return *m_pFacade;
    }

    GeMatrix3d& GeMatrix3dImpl::setAsScale(const GeVector3d& scale)
    {
        m_Data = glm::scale(glm::mat4(1.0f), glm::vec3(scale.x(), scale.y(), scale.z()));
        return *m_pFacade;
    }

    GeMatrix3d& GeMatrix3dImpl::setAsScaleBy(const GeVector3d& scale, const GePoint3d& ptBase)
    {
        m_Data[0] = glm::vec4(scale.x(), 0.0f, 0.0f, ptBase.x() * (1 - scale.x()));
        m_Data[1] = glm::vec4(0.0f, scale.y(), 0.0f, ptBase.y() * (1 - scale.y()));
        m_Data[2] = glm::vec4(0.0f, 0.0f, scale.z(), ptBase.z() * (1 - scale.z()));
        m_Data[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        return *m_pFacade;
    }

    GeMatrix3d& GeMatrix3dImpl::setAsPlaneMatrix(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis)
    {
        EB_CORE_ASSERT(xAxis.isPerpendicularTo(yAxis));
        GeVector3d zAxis = xAxis.cross(yAxis);
        m_Data[0] = glm::vec4(xAxis.x(), yAxis.x(), zAxis.x(), origin.x());
        m_Data[1] = glm::vec4(xAxis.y(), yAxis.y(), zAxis.y(), origin.y());
        m_Data[2] = glm::vec4(xAxis.z(), yAxis.z(), zAxis.z(), origin.z());
        m_Data[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        m_Data = glm::inverse(m_Data);
        return *m_pFacade;
    }

    GeVector3d GeMatrix3dImpl::mult(const GeVector3d& vec) const
    {
        glm::vec4 tmp = m_Data * glm::vec4(vec.x(), vec.y(), vec.z(), 1.0f);
        return GeVector3d(tmp.x, tmp.y, tmp.z);
    }

    GeMatrix3d GeMatrix3dImpl::mult(const GeMatrix3d& other) const
    {
        GeMatrix3d mat;
        mat.m_pImpl->m_Data = m_Data * other.m_pImpl->m_Data;
        return mat;
    }

    GeMatrix3d GeMatrix3dImpl::inverse() const
    {
        GeMatrix3d mat;
        mat.m_pImpl->m_Data = glm::inverse(m_Data);
        return mat;
    }

}