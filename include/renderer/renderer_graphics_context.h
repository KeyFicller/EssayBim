#pragma once

#include "renderer_export.h"
#include "basic_impl_template.h"

struct GLFWwindow;

namespace EB
{
    /**
     * @brief  this class is used to manage OpenGL graphics context.
     */
    class EB_RENDERER_EXPORT GraphicsContext final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(GraphicsContext)
    public:
        /**
         * @brief   create graphics context with glfw window handle.
         * @param[in]   windowHandle   handle of glfw window.
         * @return  shared pointer to created graphics context.
         */
        static Shared<GraphicsContext> create(GLFWwindow* windowHandle);

    public:
        /**
         * @brief   constructor for graphics context.
         * @param[in]   windowHandle   handle of glfw window.
         */
        GraphicsContext(GLFWwindow* windowHandle);

        /**
         * @brief   destructor for graphics context
         */
        ~GraphicsContext();

    public:
        /**
         * @brief   initialize graphics context.
         */
        void initialize();

        /**
         * @brief   swap cached buffer.
         */
        void swapBuffers();
    };
}