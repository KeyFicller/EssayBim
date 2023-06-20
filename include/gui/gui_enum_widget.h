#pragma once

#include "gui_base_widget.h"

namespace EB
{
    class EnumWidgetImpl;

    /**
     * @brief  this class define enum widget.
     */
    class EB_EXPORT EnumWidget : public BaseWidget
    {
    protected:
        /**
         * @brief  constructor for enum widget.
         * @param[in]   name     name of enum widget.
         * @param[in]   index    select index of enum widget.
         * @param[in]   items    enum items.
         * @param[in]   slot     main function on enum widget triggered.
         */
        EnumWidget(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot = nullptr);

        /**
         * @brief   constructor for enum widget.
         * @param[in]  impl  implement of derived class.
         */
        EnumWidget(EnumWidgetImpl& impl);
    };
}