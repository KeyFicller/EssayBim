#pragma once

#include "gui_base_widget.h"

#include "basic_vector.h"

#include <vector>

namespace EB
{
    /**
     * @brief   this class defines panel.
     */
    class EB_GUI_EXPORT Panel : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for panel.
         * @param[in]     name      name of panel.
         * @param[in]     slot      panel render.
         */
        Panel(const std::string& name, const WidgetSlot& slot);

    public:
        /**
         * @brief   internal usage, whether panel is hovered.
         * @return     whether current panel is hovered
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

        /**
         * @brief  internal usage, get panel position.
         * @return     panel position.
         */
        static Vec2f position();

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