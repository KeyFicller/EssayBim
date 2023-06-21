#pragma once

#include "gui_base_widget.h"

namespace EB
{
    class ValueInputWidgetImpl;

    /**
     * @brief  this class defines value input widget base.
     */
    class EB_EXPORT ValueInputWidget : public BaseWidget
    {
    public:
        /**
         * @brief  this struct defines value input boundary.
         */
        struct ValueBoundary
        {
            float LowerBound = 0.0;           /** < value input lower boundary > */
            float UpperBound = 1.0;           /** < value input upper boundary > */
        };

    protected:
        /**
         * @brief  constructor for value input widget.
         * @param[in]    name         name of widget.
         * @param[in]    data         interacting data.
         * @param[in]    component    value component count.
         * @param[in]    slot         main function on widget triggered.
         */
        ValueInputWidget(const std::string& name, void* data, int component, const ValueBoundary& boundary, const WidgetSlot& slot = nullptr);

        /**
         * @brief   constructor for text input widget.
         * @param[in]  impl  implement of derived class.
         */
        ValueInputWidget(ValueInputWidgetImpl& impl);

    public:
        /**
         * @brief   set value boundary to widget.
         * @param[in]   boundary       value boundary for all component.
         */
        void setValueBoundary(const ValueBoundary& boundary);
    };
}