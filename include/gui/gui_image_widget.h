#pragma once

#include "gui_base_widget.h"

#include "basic_vector.h"

namespace EB
{
    /**
     * @brief  this class defines image widget.
     */
    class EB_GUI_EXPORT ImageWidget : public BaseWidget
    {
    public:
        /**
         * @brief  constructor for image widget.
         * @param[in]    textureId    texture identifier allocated by OpenGL.
         * @param[in]    size         size of image widget.
         */
        ImageWidget(unsigned int textureId, const Vec2f& size);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < texture identifier allocated by OpenGL > */
        unsigned int m_TextureId;

        /** < size of image widget > */
        Vec2f m_Size;

        /** < cached tempoaray data > */        // todo: remove this
        Vec2f m_CursorPos;
    };

    /**
     * @brief  this class defines image widget with magnifier.
     */
    class EB_GUI_EXPORT ImageWidgetWithMagnifier : public ImageWidget
    {
    public:
        /**
         * @brief   constructor for image widget with magnifier.
         * @param[in]    size       size of image widget.
         * @param[in]    zoomScale  zoom scale of magnifier.
         */
        ImageWidgetWithMagnifier(unsigned int textureId, const Vec2f& size, float zoomScale = 4.0f);

    protected:
        /**
         * @brief   restore stack data after rendering.
         */
        void postAction() override;

    protected:
        /** < zoom scale of magnifier > */
        float m_ZoomScale;
    };
}