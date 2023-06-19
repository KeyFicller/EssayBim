#pragma once

#include "gui_base_widget.h"

namespace EB
{
    /**
     * @brief  this class defines check box.
     */
    class EB_EXPORT CheckBox : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for check box.
         * @param[in]   name     name of check box.
         * @param[in]   value    reference to check status.
         * @param[in]   slot     main function on widget triggered.
         */
        CheckBox(const std::string& name, bool& value, const WidgetSlot& slot = nullptr);
    
    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < reference to check status > */
        bool& m_Value;
    };
}