#pragma once

#include "document_camera_impl.h"
#include "document_interactive_camera.h"

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

namespace EB
{
    class MouseScrolledEvent;

    class InteractiveCameraImpl : public CameraImpl
    {
    public:
        InteractiveCameraImpl(Camera* pFacade, Window* pWindow);
        InteractiveCameraImpl(Camera* pFacade, Window* pWindow, float VFov, float aspectRatio, float nearClip, float farClip);
        ~InteractiveCameraImpl() override;

    public:
        void onEvent(Event& e);
        void onUpdate(TimeStep ts);
        float distance() const;
        void setDistance(float distance);
        void setViewportSize(float width, float height);
        const Mat4 viewMatrix() const;
        const Mat4 viewProjectionMatrix() const;
        const Vec3f upDirection() const;
        const Vec3f rightDirection() const;
        const Vec3f forwardDirection() const;
        const Vec3f cameraPosition() const;
        GeLine3d ray(const GeMatrix2d& windowMatrix) const;

    protected:
        void subYamlIn(const std::string& key);
        void subYamlOut(const std::string& key);

    private:
        void updateProjectionMatrix();
        void updateViewMatrix();
        void updateCameraPosition();
        bool onMouseScrolled(MouseScrolledEvent& e);
        void onMousePaned(const glm::vec2& delta);
        void onMouseRotated(const glm::vec2& delta);
        void onMouseZoomed(float delta);
        const std::pair<float, float> panSpeed() const;
        float rotationSpeed() const;
        float zoomSpeed() const;
        const glm::quat orientation() const;

    protected:
        float m_VerticalFov = 45.f;
        float m_AspectRatio = 1.5f;
        float m_NearClip = 0.1f;
        float m_FarClip = 1000.0f;
        float m_Distance = 10.f;
        float m_ViewportWidth = 1200.f;
        float m_ViewportHeight = 800.f;
        glm::mat4 m_ViewMatrix = glm::mat4(1.0f);
        glm::vec3 m_CameraPosition = {0.0f, 0.0f, 10.0f};
        glm::vec3 m_LookAtPosition = { 0.0f, 0.0f, 0.0f };
        float m_Pitch = 0.0f;
        float m_Yaw = 0.0f;
        float m_Roll = 0.0f;
        glm::vec2 m_MousePositionBefore = { 0.0f, 0.0f };
    };
}