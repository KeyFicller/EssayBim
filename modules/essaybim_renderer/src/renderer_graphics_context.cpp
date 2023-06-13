#include "renderer_graphics_context.h"

#include "renderer_graphics_context_impl.h"

namespace EB
{

    Shared<GraphicsContext> GraphicsContext::create(GLFWwindow* windowHandle)
    {
        return createShared<GraphicsContext>(windowHandle);
    }

    GraphicsContext::GraphicsContext(GLFWwindow* windowHandle)
    {
        EB_IMPL = createScoped<GraphicsContextImpl>(windowHandle);
    }

    GraphicsContext::~GraphicsContext()
    {
        EB_IMPL.release();
    }

    void GraphicsContext::initialize()
    {
        EB_IMPL->initialize();
    }

    void GraphicsContext::swapBuffers()
    {
        EB_IMPL->swapBuffers();
    }

}