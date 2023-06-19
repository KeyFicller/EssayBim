#pragma once

#include "gui_enum_widget.h"

namespace EB
{
    /**
     * @brief  this class defines list box.
     */
    class EB_EXPORT ListBox : public EnumWidget
    {
    public:
        /**
         * @brief  constructor for list box.
         * @param[in]   name     name of list box.
         * @param[in]   index    select index of list box.
         * @param[in]   items    enum items.
         * @param[in]   slot     main function on list box triggered.
         */
        ListBox(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot = nullptr);

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
    };
}