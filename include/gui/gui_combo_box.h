#pragma once

#include "gui_enum_widget.h"

namespace EB
{
    /**
     * @brief  this class defines combo box.
     */
    class EB_GUI_EXPORT ComboBox : public EnumWidget
    {
    public:
        /**
         * @brief  constructor for combo box.
         * @param[in]   name     name of combo box.
         * @param[in]   index    select index of combo box.
         * @param[in]   items    enum items.
         * @param[in]   slot     main function on combo box triggered.
         */
        ComboBox(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot = nullptr);
    
    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;
    };
}