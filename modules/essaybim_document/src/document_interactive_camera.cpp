#include "document_interactive_camera.h"

#include "document_interactive_camera_impl.h"

#include "basic_time_step.h"

namespace EB
{

    InteractiveCamera::InteractiveCamera(Window* pWindow, float VFov, float aspectRatio, float nearClip, float farClip)
        : Camera(*new InteractiveCameraImpl(this, pWindow, VFov, aspectRatio, nearClip, farClip))
    {

    }

    InteractiveCamera::~InteractiveCamera()
    {

    }

    void InteractiveCamera::onEvent(Event& e)
    {
        EB_IMPL(InteractiveCamera)->onEvent(e);
    }

    void InteractiveCamera::onUpdate(TimeStep ts)
    {
        EB_IMPL(InteractiveCamera)->onUpdate(ts);
    }

    float InteractiveCamera::distance() const
    {
        return EB_IMPL(InteractiveCamera)->distance();
    }

    void InteractiveCamera::setDistance(float distance)
    {
        EB_IMPL(InteractiveCamera)->setDistance(distance);
    }

    void InteractiveCamera::setViewportSize(float width, float height)
    {
        EB_IMPL(InteractiveCamera)->setViewportSize(width, height);
    }

    const Mat4 InteractiveCamera::viewMatrix() const
    {
        return EB_IMPL(InteractiveCamera)->viewMatrix();
    }

    const Mat4 InteractiveCamera::viewProjectionMatrix() const
    {
        return EB_IMPL(InteractiveCamera)->viewProjectionMatrix();
    }

    const Vec3f InteractiveCamera::upDirection() const
    {
        return EB_IMPL(InteractiveCamera)->upDirection();
    }

    const Vec3f InteractiveCamera::rightDirection() const
    {
        return EB_IMPL(InteractiveCamera)->rightDirection();
    }

    const Vec3f InteractiveCamera::forwardDirection() const
    {
        return EB_IMPL(InteractiveCamera)->forwardDirection();
    }

    const Vec3f InteractiveCamera::cameraPosition() const
    {
        return EB_IMPL(InteractiveCamera)->cameraPosition();
    }

}