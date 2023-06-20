#pragma once

#include "gui_text_input_widget.h"

namespace EB
{
    /**
     * @brief  this class defines multiline input text.
     */
    class EB_EXPORT MultilineInputText : public TextInputWidget
    {
    public:
        /**
         * @brief   constructor for multiline input text.
         * @param[in]    name       name of widget.
         * @param[in]    editStr    string on editing.
         * @param[in]    slot       main function on widget triggered.
         */
        MultilineInputText(const std::string& name, std::string& editStr, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

        /**
         * @brief   get maximum size of input.
         * @return   maximum input size.
         */
        unsigned int maxInputSize() override;
    };
}