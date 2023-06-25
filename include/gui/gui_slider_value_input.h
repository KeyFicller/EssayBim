#pragma once

#include "gui_value_input_widget.h"

#include "basic_vector.h"

namespace EB
{
    class EB_EXPORT SliderValueInputF : public ValueInputWidget
    {
    public:
        /**
         * @brief  constructor for slider value input widget.
         * @param[in]    name         name of widget.
         * @param[in]    value         interacting value.
         * @param[in]    component    value component count.
         * @param[in]    slot         main function on widget triggered.
         */
        SliderValueInputF(const std::string& name, float& value, const ValueInputWidget::ValueBoundary& boundary = ValueInputWidget::ValueBoundary(), const WidgetSlot& slot = nullptr);
        
        /**
         * @brief  constructor for slider value input widget.
         * @param[in]    name         name of widget.
         * @param[in]    value         interacting value.
         * @param[in]    component    value component count.
         * @param[in]    slot         main function on widget triggered.
         */
        SliderValueInputF(const std::string& name, Vec2f& value, const ValueInputWidget::ValueBoundary& boundary = ValueInputWidget::ValueBoundary(), const WidgetSlot& slot = nullptr);
        
        /**
         * @brief  constructor for slider value input widget.
         * @param[in]    name         name of widget.
         * @param[in]    value         interacting value.
         * @param[in]    component    value component count.
         * @param[in]    slot         main function on widget triggered.
         */
        SliderValueInputF(const std::string& name, Vec3f& value, const ValueInputWidget::ValueBoundary& boundary = ValueInputWidget::ValueBoundary(), const WidgetSlot& slot = nullptr);
        
        /**
         * @brief  constructor for slider value input widget.
         * @param[in]    name         name of widget.
         * @param[in]    value         interacting value.
         * @param[in]    component    value component count.
         * @param[in]    slot         main function on widget triggered.
         */
        SliderValueInputF(const std::string& name, Vec4f& value, const ValueInputWidget::ValueBoundary& boundary = ValueInputWidget::ValueBoundary(), const WidgetSlot& slot = nullptr);
    
    public:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;
    };
}