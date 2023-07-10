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
    class GeLine3d;
    class CommandBase;
    class DbDatabase;
    class KeyPressedEvent;

    class TestLayer : public Layer
    {
    public:
        TestLayer();
        ~TestLayer() override = default;
    public:
        void onAttach() override;
        void onDetach() override;
        void onUpdate(const TimeStep& ts) override;
        void onGuiRender() override;
        void onEvent(Event& e) override;

        bool _onKeyPressedEvent(KeyPressedEvent& event);

        static DbDatabase& currentDb();

    protected:
        Shared<Texture2D> texture;
        Shared<InteractiveCamera> camera;
        Shared<FrameBuffer> frameBuffer;
        bool viewHovered = false;
        CommandBase* m_EmbedCommand = nullptr;
        Vec2f viewPortOffset;
    };
}