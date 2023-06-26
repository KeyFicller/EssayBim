#include "document_interactive_camera_impl.h"

#include "basic_time_step.h"
#include "event_mouse_event.h"
#include "event_event_dispatcher.h"
#include "event_keycode_defines.h"
#include "event_mouse_button_defines.h"
#include "window_window.h"

#include <glm/gtc/matrix_transform.hpp>

namespace EB
{
    EB_YAML_DECLARE_KEYS(VerticalFov, AspectRatio, NearClip, FarClip, Distance, ViewportWidth,
        ViewportHeight, CameraPos, LookAtPos, Pitch, Yaw, Roll);

    InteractiveCameraImpl::InteractiveCameraImpl(Camera* pFacade, Window* pWindow)
        : CameraImpl(pFacade, pWindow, Mat4())
    {

    }

    InteractiveCameraImpl::InteractiveCameraImpl(Camera* pFacade, Window* pWindow, float VFov, float aspectRatio, float nearClip, float farClip)
        : m_VerticalFov(VFov), m_AspectRatio(aspectRatio), m_NearClip(nearClip), m_FarClip(farClip),
          CameraImpl(pFacade, pWindow, Mat4())
    {
        m_ProjectionMatrix = glm::perspective(glm::radians(m_VerticalFov), m_AspectRatio, m_NearClip, m_FarClip);
        updateViewMatrix();
    }

    InteractiveCameraImpl::~InteractiveCameraImpl()
    {

    }

    void InteractiveCameraImpl::onEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<MouseScrolledEvent>(std::bind(&InteractiveCameraImpl::onMouseScrolled, this, std::placeholders::_1));
    }

    void InteractiveCameraImpl::onUpdate(TimeStep ts)
    {
        if (window()->isKeyPressed(KEY_LEFT_CONTROL)) {
            auto [x, y] = window()->cursorPos();
            glm::vec2 cursor = glm::vec2(x, y);
            glm::vec2 delta = (cursor - m_MousePositionBefore) * 0.003f;
            m_MousePositionBefore = cursor;

            if (window()->isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                onMousePaned(delta);
            }
            else if (window()->isMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
                onMouseRotated(delta);
            }
            else if (window()->isMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) {
                onMouseZoomed(delta.y);
            }
        }
        updateViewMatrix();
    }

    float InteractiveCameraImpl::distance() const
    {
        return m_Distance;
    }

    void InteractiveCameraImpl::setDistance(float distance)
    {
        m_Distance = distance;
    }

    void InteractiveCameraImpl::setViewportSize(float width, float height)
    {
        m_ViewportWidth = width;
        m_ViewportHeight = height;
        updateProjectionMatrix();
    }

    const Mat4 InteractiveCameraImpl::viewMatrix() const
    {
        return m_ViewMatrix;
    }

    const Mat4 InteractiveCameraImpl::viewProjectionMatrix() const
    {
        return m_ProjectionMatrix * m_ViewMatrix;
    }

    const Vec3f InteractiveCameraImpl::upDirection() const
    {
        return glm::rotate(orientation(), glm::vec3(0.0f, 1.0f, 0.0f));
    }

    const Vec3f InteractiveCameraImpl::rightDirection() const
    {
        return glm::rotate(orientation(), glm::vec3(1.0f, 0.0f, 0.0f));
    }

    const Vec3f InteractiveCameraImpl::forwardDirection() const
    {
        return glm::rotate(orientation(), glm::vec3(0.0f, 0.0f, -1.0f));
    }

    const Vec3f InteractiveCameraImpl::cameraPosition() const
    {
        return m_CameraPosition;
    }

    void InteractiveCameraImpl::subYamlIn(const std::string& key)
    {
        CameraImpl::subYamlIn(key);
        EB_YAML_IN(s_Key.VerticalFov, m_VerticalFov);
        EB_YAML_IN(s_Key.AspectRatio, m_AspectRatio);
        EB_YAML_IN(s_Key.NearClip, m_NearClip);
        EB_YAML_IN(s_Key.FarClip, m_FarClip);
        EB_YAML_IN(s_Key.Distance, m_Distance);
        EB_YAML_IN(s_Key.ViewportWidth, m_ViewportWidth);
        EB_YAML_IN(s_Key.ViewportHeight, m_ViewportHeight);
        EB_YAML_IN(s_Key.CameraPos, (Vec3f&)m_CameraPosition);
        EB_YAML_IN(s_Key.LookAtPos, (Vec3f&)m_LookAtPosition);
        EB_YAML_IN(s_Key.Pitch, m_Pitch);
        EB_YAML_IN(s_Key.Yaw, m_Yaw);
        EB_YAML_IN(s_Key.Roll, m_Roll);
        updateViewMatrix();
        updateProjectionMatrix();
    }

    void InteractiveCameraImpl::subYamlOut(const std::string& key)
    {
        CameraImpl::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        EB_YAML_OUT(s_Key.VerticalFov, m_VerticalFov);
        EB_YAML_OUT(s_Key.AspectRatio, m_AspectRatio);
        EB_YAML_OUT(s_Key.NearClip, m_NearClip);
        EB_YAML_OUT(s_Key.FarClip, m_FarClip);
        EB_YAML_OUT(s_Key.Distance, m_Distance);
        EB_YAML_OUT(s_Key.ViewportWidth, m_ViewportWidth);
        EB_YAML_OUT(s_Key.ViewportHeight, m_ViewportHeight);
        EB_YAML_OUT(s_Key.CameraPos, (Vec3f&)m_CameraPosition);
        EB_YAML_OUT(s_Key.LookAtPos, (Vec3f&)m_LookAtPosition);
        EB_YAML_OUT(s_Key.Pitch, m_Pitch);
        EB_YAML_OUT(s_Key.Yaw, m_Yaw);
        EB_YAML_OUT(s_Key.Roll, m_Roll);
    }

    void InteractiveCameraImpl::updateProjectionMatrix()
    {
        m_AspectRatio = m_ViewportWidth / m_ViewportHeight;
        m_ProjectionMatrix = glm::perspective(glm::radians(m_VerticalFov), m_AspectRatio, m_NearClip, m_FarClip);
    }

    void InteractiveCameraImpl::updateViewMatrix()
    {
        updateCameraPosition();
        m_ViewMatrix = glm::translate(glm::mat4(1.0f), m_CameraPosition) * glm::toMat4(orientation());
        m_ViewMatrix = glm::inverse(m_ViewMatrix);
    }

    void InteractiveCameraImpl::updateCameraPosition()
    {
        m_CameraPosition = m_LookAtPosition - glm::vec3(forwardDirection()) * m_Distance;
    }

    bool InteractiveCameraImpl::onMouseScrolled(MouseScrolledEvent& e)
    {
        float delta = e.y() * 0.1f;
        onMouseZoomed(delta);
        updateViewMatrix();
        return false;
    }

    void InteractiveCameraImpl::onMousePaned(const glm::vec2& delta)
    {
        auto [xSpd, ySpd] = panSpeed();
        m_LookAtPosition += -glm::vec3(rightDirection()) * delta.x * xSpd * distance();
        m_LookAtPosition += glm::vec3(upDirection()) * delta.y * ySpd * distance();
    }

    void InteractiveCameraImpl::onMouseRotated(const glm::vec2& delta)
    {
        float yawSign = upDirection().y() < 0.0f ? -1.0f : 1.0f;
        m_Yaw += yawSign * delta.x * rotationSpeed();
        m_Pitch += delta.y * rotationSpeed();
    }

    void InteractiveCameraImpl::onMouseZoomed(float delta)
    {
        m_Distance -= delta * zoomSpeed();
        if (m_Distance < 1.0f) {
            m_LookAtPosition += glm::vec3(forwardDirection());
            m_Distance = 1.0f;
        }
    }

    const std::pair<float, float> InteractiveCameraImpl::panSpeed() const
    {
        float x = std::min(m_ViewportWidth / 1000.f, 2.4f);
        float xFactor = 0.0366f * (x * x) - 0.1788f * x + 0.3021f;

        float y = std::min(m_ViewportHeight / 1000.f, 2.4f);
        float yFactor = 0.0366f * (y * y) - 0.1788f * y + 0.3021f;

        return { xFactor, yFactor };
    }

    float InteractiveCameraImpl::rotationSpeed() const
    {
        return 0.8f;
    }

    float InteractiveCameraImpl::zoomSpeed() const
    {
        float dis = m_Distance * 0.2f;
        dis = std::max(dis, 0.0f);
        float speed = dis * dis;
        speed = std::min(speed, 100.f);
        return speed;
    }

    const glm::quat InteractiveCameraImpl::orientation() const
    {
        return glm::quat(glm::vec3(-m_Pitch, -m_Yaw, -m_Roll));
    }

}