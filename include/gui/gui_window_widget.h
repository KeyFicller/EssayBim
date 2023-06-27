#pragma once

#include "gui_base_widget.h"

#include "basic_vector.h"

#include <vector>

namespace EB
{
    /**
     * @brief   this class defines window widget.
     */
    class EB_EXPORT WindowWidget : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for window widget.
         * @param[in]     name      name of window widget.
         * @param[in]     slot      window render.
         */
        WindowWidget(const std::string& name, const WidgetSlot& slot);

    public:
        /**
         * @brief   internal usage, whether window widget is hovered.
         * @return     whether current window widget is hovered
         */
        static bool isHovered();

        /**
         * @brief  internal usage, get view port bounds.
         * @return     view port bounds.
         */
        static std::vector<Vec2f> viewportBounds();

        /**
         * @brief  internal usage, get content valid view port size.
         * @return    view port size.
         */
        static Vec2f viewportAvailiable();

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

        /**
         * @brief   restore stack data after rendering.
         */
        virtual void postAction();
    };
}