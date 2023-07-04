#pragma once

#include "gui_button.h"

#include "basic_vector.h"

namespace EB
{
    /**
     * @brief  this class defines colored button.
     */
    class EB_GUI_EXPORT ColoredButton : public Button
    {
    public:
        /**
         * @brief  this struct defines button color on different conditions.
         */
        struct ButtonColor
        {
            Vec4f Normal;           /** < button color normal > */
            Vec4f Hovered;          /** < button color hovered > */
            Vec4f Clicked;          /** < button color clicked > */

            /**
             * @brief  constructor for ButtonColor.
             */
            ButtonColor();

            /**
             * @brief  constructor for ButtonColor.
             * @param[in] normal    button color normal
             * @param[in] hoverd    button color hovered
             * @param[in] clicked   button color clicked
             */
            ButtonColor(const Vec4f& normal, const Vec4f& hovered, const Vec4f& clicked);
        };

    public:
        /**
         * @brief    constructor for colored button widget.
         * @param[in]   name    name of widget.
         * @param[in]   color   color of widget.
         * @param[in]   slot    main function on colored button triggered.
         */
        ColoredButton(const std::string& name, const ButtonColor& color, const WidgetSlot& slot = nullptr);

        /**
         * @brief    constructor for colored button widget.
         * @param[in]   name    name of widget.
         * @param[in]   size    size of widget.
         * @param[in]   color   color of widget.
         * @param[in]   slot    main function on colored button triggered.
         */
        ColoredButton(const std::string& name, const Vec2f& size, const ButtonColor& color, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   push custom style for widget.
         */
        void pushStyle() override;

        /**
         * @brief   pop custom style for widget.
         */
        void popStyle() override;

    protected:
        /** < button color > */
        ButtonColor m_Color;
    };
}