#pragma once

#include "window_layer.h"

#include "basic_vector.h"

#include <vector>

namespace EB
{
    class VertexArray;
    class VertexBuffer;
    class IndexBuffer;
    class Shader;
    class Texture2D;
    class InteractiveCamera;
    class UniformBuffer;
    class FrameBuffer;
    class GeMesh;

    class TestLayer : public Layer
    {
    public:
        TestLayer(const std::string& name);
        ~TestLayer() override = default;
    public:
        void onAttach() override;
        void onDetach() override;
        void onUpdate(const TimeStep& ts) override;
        void onGuiRender() override;
        void onEvent(Event& e) override;

    protected:
        Shared<Texture2D> texture;
        Shared<InteractiveCamera> camera;
        Shared<FrameBuffer> frameBuffer;
        bool viewHovered = false;
        Shared<GeMesh> mesh;
        std::vector<Vec3f> bound;
    };
}