#pragma once

#include "gui_value_input_widget.h"

#include "basic_vector.h"

namespace EB
{
    /**
     * @brief  this class defines color edit widget.
     */
    class EB_EXPORT ColorEdit : public ValueInputWidget
    {
    public:
        /**
         * @brief  constructor for color edit widget.
         * @param[in]    name         name of widget.
         * @param[in]    value         interacting value.
         * @param[in]    slot         main function on widget triggered.
         */
        ColorEdit(const std::string& name, Vec3& value, const WidgetSlot& slot = nullptr);

        /**
         * @brief  constructor for color edit widget.
         * @param[in]    name         name of widget.
         * @param[in]    value         interacting value.
         * @param[in]    slot         main function on widget triggered.
         */
        ColorEdit(const std::string& name, Vec4& value, const WidgetSlot& slot = nullptr);

    public:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;
    };
}