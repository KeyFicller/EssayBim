#include "document_camera.h"

#include "document_camera_impl.h"

namespace EB
{

    Camera::Camera(Window* pWindow, const Mat4& projection /*= Mat4()*/)
    {
        EB_IMPL() = createScoped<CameraImpl>(this, pWindow, projection);
    }

    Camera::Camera(CameraImpl& impl)
    {
        EB_IMPL() = std::unique_ptr<CameraImpl>(&impl);
    }

    Camera::~Camera()
    {
        EB_IMPL().reset();
    }

    const Mat4 Camera::projectionMatrix() const
    {
        return EB_IMPL()->projectionMatrix();
    }

    Window* Camera::window() const
    {
        return EB_IMPL()->window();
    }

    void Camera::subYamlIn(const std::string& key)
    {
        EB_IMPL()->subYamlIn(key);
    }

    void Camera::subYamlOut(const std::string& key)
    {
        EB_IMPL()->subYamlOut(key);
    }

}