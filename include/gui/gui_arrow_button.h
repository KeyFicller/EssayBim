#pragma once

#include "gui_button.h"

namespace EB
{
    /**
     * @brief  this class defines arrow button class.
     */
    class EB_GUI_EXPORT ArrowButton : public Button
    {
    public:
        /**
         * @brief  this enum defines arrow button direction.
         */
        enum class eArrowDirection
        {
            kLeft = 0,              /** < arrow aims at left > */
            kRight,                 /** < arrow aims at right > */
            kUp,                    /** < arrow aims at up > */
            kDown                   /** < arrow aims at down > */
        };

    public:
        /**
         * @brief  constructor for arrow button.
         * @param[in]    name        name of button.
         * @param[in]    direction   direction of button.
         */
        ArrowButton(const std::string& name, eArrowDirection direction = eArrowDirection::kRight, const WidgetSlot& slot = nullptr);
    
    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

        /**
         * @brief   push custom style for widget.
         */
        void pushStyle() override;

        /**
         * @brief   pop custom style for widget.
         */
        void popStyle() override;

    protected:
        /** < direction of arrow > */
        eArrowDirection m_Direction;
    };
}