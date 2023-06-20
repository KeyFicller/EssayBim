#pragma once

#include "gui_text_input_widget.h"

namespace EB
{
    /**
     * @brief this class defines hint input text.
     */
    class EB_EXPORT HintInputText : public TextInputWidget
    {
    public:
        /**
         * @brief   constructor for input text.
         * @param[in]    name       name of widget.
         * @param[in]    editStr    string on editing.
         * @param[in]    hintStr    string of hint.
         * @param[in]    slot       main function on widget triggered.
         */
        HintInputText(const std::string& name, std::string& editStr, const std::string& hintStr, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < string of hint > */
        std::string m_HintStr;
    };
}