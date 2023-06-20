#pragma once

#include "gui_text_input_widget.h"

namespace EB
{
    /**
     * @brief  this class defines input text class.
     */
    class EB_EXPORT InputText : public TextInputWidget
    {
    public:
        /**
         * @brief   constructor for input text.
         * @param[in]    name       name of widget.
         * @param[in]    editStr    string on editing.
         * @param[in]    slot       main function on widget triggered.
         */
        InputText(const std::string& name, std::string& editStr, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;
    };
}