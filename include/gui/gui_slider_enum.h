#pragma once

#include "gui_enum_widget.h"

namespace EB
{
    /**
     * @brief  this class defines list box.
     */
    class EB_EXPORT SliderEnum : public EnumWidget
    {
    public:
        /**
         * @brief  constructor for slider enum.
         * @param[in]   name     name of slider enum.
         * @param[in]   index    select index of slider enum.
         * @param[in]   items    enum items.
         * @param[in]   slot     main function on slider enum triggered.
         */
        SliderEnum(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;
    };
}
