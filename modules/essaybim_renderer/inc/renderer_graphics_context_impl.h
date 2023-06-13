#pragma once

#include "renderer_graphics_context.h"

namespace EB
{
    class GraphicsContextImpl
    {
    public:
        GraphicsContextImpl(GLFWwindow* windowHandle);
        ~GraphicsContextImpl();

    public:
        void initialize();
        void swapBuffers();

    protected:
        GLFWwindow* m_pWindowHandle = nullptr;
    };
}