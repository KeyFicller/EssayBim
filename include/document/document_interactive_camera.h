#pragma once

#include "document_camera.h"

namespace EB
{
    class Event;
    class TimeStep;

    /**
     * @brief  this class defines interactive camera.
     */
    class EB_EXPORT InteractiveCamera : public Camera
    {
    public:
        /**
         * @brief   constructor for interactive camera.
         * @param[in]   pWindow       window of camera.
         * @param[in]    VFov            vertical fov.
         * @param[in]    aspectRatio     width / height.
         * @param[in]    nearClip        clip plane distance near.
         * @param[in]    farClip         clip plane distance far.
         */
        InteractiveCamera(Window* pWindow, float VFov, float aspectRatio, float nearClip, float farClip);

        /**
         * @brief  destructor for interactive camera.
         */
        ~InteractiveCamera() override;

    public:
        /**
         * @brief   handle interactive camera event.
         * @param[in]    e     event.
         */
        void onEvent(Event& e);

        /**
         * @brief   handle interactive camera update.
         * @param[in]    ts    time step during.
         */
        void onUpdate(TimeStep ts);

        /**
         * @brief   get camera distance from look at position.
         * @return   camera distance from look at position.
         */
        float distance() const;

        /**
         * @brief   set camera distance from look at position.
         * @param[in]   distance    camera distance from look at position.
         */
        void setDistance(float distance);

        /**
         * @brief   set camera aspect ratio by view port size.
         * @param[in]   width     width of view port.
         * @param[in]   height    height of view port.
         */
        void setViewportSize(float width, float height);

        /**
         * @brief   get view matrix.
         * @return   view matrix.
         */
        const Mat4 viewMatrix() const;

        /**
         * @brief   get view projection matrix.
         * @return    view projection matrix.
         */
        const Mat4 viewProjectionMatrix() const;

        /**
         * @brief   get camera up direction.
         * @return    camera up direction.
         */
        const Vec3f upDirection() const;

        /**
         * @brief   get camera right direction.
         * @return    camera right direction.
         */
        const Vec3f rightDirection() const;

        /**
         * @brief   get camera forward direction.
         * @return    camera forward direction.
         */
        const Vec3f forwardDirection() const;

        /**
         * @brief   get camera position.
         * @return    camera position.
         */
        const Vec3f cameraPosition() const;
    };
}