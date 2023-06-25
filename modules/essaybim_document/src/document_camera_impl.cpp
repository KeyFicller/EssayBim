#include "document_camera_impl.h"

#include "window_window.h"

namespace EB
{

    CameraImpl::CameraImpl(Camera* pFacade, Window* pWindow, const Mat4& projection)
        : m_pFacade(pFacade), m_pWindow(pWindow), m_ProjectionMatrix(projection)
    {

    }

    const Mat4 CameraImpl::projectionMatrix() const
    {
        return m_ProjectionMatrix;
    }

    Window* CameraImpl::window() const
    {
        return m_pWindow;
    }

    void CameraImpl::subYamlIn(const std::string& key)
    {

    }

    void CameraImpl::subYamlOut(const std::string& key)
    {

    }

}