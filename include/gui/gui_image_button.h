#pragma once

#include "gui_button.h"

namespace EB
{
    /**
     * @brief   this class defines image button.
     */
    class EB_EXPORT ImageButton : public Button
    {
    public:
        /**
         * @brief  constructor for image button.
         * @param[in]    textureId     texture id allocated by OpenGL.
         * @param[in]    size          size of button.
         * @param[in]    slot    main function on image button triggered.
         */
        ImageButton(unsigned int textureId, const Vec2f& size, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < texture id > */
        unsigned int m_TextureId;
    };
}