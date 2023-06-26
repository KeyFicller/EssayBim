#pragma once

#include "window_layer.h"

namespace EB
{
    class VertexArray;
    class VertexBuffer;
    class IndexBuffer;
    class Shader;
    class Texture2D;
    class InteractiveCamera;
    class UniformBuffer;

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
        Shared<VertexArray> vao;
        Shared<VertexBuffer> vbo;
        Shared<IndexBuffer> ibo;
        Shared<Shader> shader;
        Shared<Texture2D> texture;
        Shared<InteractiveCamera> camera;
        Shared<UniformBuffer> cameraBuffer;
    };
}