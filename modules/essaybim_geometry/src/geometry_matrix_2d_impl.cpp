#include "geometry_matrix_2d_impl.h"

namespace EB
{

    GeMatrix2dImpl::GeMatrix2dImpl(GeMatrix2d* pFacade)
        : m_pFacade(pFacade)
    {

    }

    GeMatrix2d& GeMatrix2dImpl::setAsTranslation(const GeVector2d& translate)
    {
        m_Data[0] = glm::vec3(1.0f, 0.0f, translate.x());
        m_Data[1] = glm::vec3(0.0f, 1.0f, translate.y());
        m_Data[2] = glm::vec3(0.0f, 0.0f, 1.0f);
        return *m_pFacade;
    }

    GeMatrix2d& GeMatrix2dImpl::setAsRotation(double radians)
    {
        m_Data[0] = glm::vec3(cos(radians), -sin(radians), 0.0f);
        m_Data[1] = glm::vec3(sin(radians), cos(radians), 0.0f);
        m_Data[2] = glm::vec3(0.0f, 0.0f, 1.0f);
        return *m_pFacade;
    }

    GeMatrix2d& GeMatrix2dImpl::setAsScale(const GeVector2d& scale)
    {
        m_Data[0] = glm::vec3(scale.x(), 0.0f, 0.0f);
        m_Data[1] = glm::vec3(0.0f, scale.y(), 0.0f);
        m_Data[2] = glm::vec3(0.0f, 0.0f, 1.0f);
        return *m_pFacade;
    }

    GeMatrix2d& GeMatrix2dImpl::setAs(const GeVector2d& vec, double radians, const GeVector2d& scale)
    {
        m_Data = GeMatrix2d().setAsTranslation(vec).m_pImpl->m_Data *
                 GeMatrix2d().setAsRotation(radians).m_pImpl->m_Data *
                 GeMatrix2d().setAsScale(scale).m_pImpl->m_Data;
        return *m_pFacade;
    }

    GeMatrix2d& GeMatrix2dImpl::setAsRotateBy(double radians, const GePoint2d& ptBase)
    {
        m_Data[0] = glm::vec3(cos(radians), -sin(radians), ptBase.x() * (1 - cos(radians) + ptBase.y() * sin(radians)));
        m_Data[1] = glm::vec3(sin(radians), cos(radians), ptBase.y() * (1 - cos(radians) + ptBase.x() * sin(radians)));
        m_Data[2] = glm::vec3(0.0f, 0.0f, 1.0f);
        return *m_pFacade;
    }

    GeMatrix2d& GeMatrix2dImpl::setAsScaleBy(const GeVector2d& scale, const GePoint2d& ptBase)
    {
        m_Data[0] = glm::vec3(scale.x(), 0.0f, ptBase.x() * (1 - scale.x()));
        m_Data[1] = glm::vec3(0.0f, scale.y(), ptBase.y() * (1 - scale.y()));
        m_Data[2] = glm::vec3(0.0f, 0.0f, 1.0f);
        return *m_pFacade;
    }

    GeMatrix2d GeMatrix2dImpl::mult(const GeMatrix2d& other) const
    {
        GeMatrix2d mat;
        mat.m_pImpl->m_Data = m_Data * other.m_pImpl->m_Data;
        return mat;
    }

    GeVector2d GeMatrix2dImpl::mult(const GeVector2d& vec) const
    {
        glm::vec3 tmp = m_Data * glm::vec3(vec.x(), vec.y(), 1.0f);
        return GeVector2d(tmp.x, tmp.y);
    }

}