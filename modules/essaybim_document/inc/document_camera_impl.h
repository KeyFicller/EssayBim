#pragma once

#include "document_camera.h"

#include <glm/glm.hpp>

namespace EB
{
    class CameraImpl
    {
    public:
        CameraImpl(Camera* pFacade, Window* pWindow, const Mat4& projection);
        virtual ~CameraImpl() = default;

    public:
        const Mat4 projectionMatrix() const;
        Window* window() const;

    public:
        virtual void subYamlIn(const std::string& key);
        virtual void subYamlOut(const std::string& key);

    protected:
        Camera* m_pFacade = nullptr;
        Window* m_pWindow = nullptr;
        glm::mat4 m_ProjectionMatrix;
    };
}