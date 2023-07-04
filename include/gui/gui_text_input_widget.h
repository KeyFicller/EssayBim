#pragma once

#include "gui_base_widget.h"

namespace EB
{
    class TextInputWidgetImpl;

    /**
     * @brief  this class defines text input widget class.
     */
    class EB_GUI_EXPORT TextInputWidget : public BaseWidget
    {
    protected:
        /**
         * @brief   constructor for text input widget.
         * @param[in]    name       name of widget.
         * @param[in]    editStr    string on editing.
         * @param[in]    slot       main function on widget triggered.
         */
        TextInputWidget(const std::string& name, std::string& editStr, const WidgetSlot& slot = nullptr);

        /**
         * @brief   constructor for text input widget.
         * @param[in]  impl  implement of derived class.
         */
        TextInputWidget(TextInputWidgetImpl& impl);

    public:
        /**
         * @brief   get maximum size of input.
         * @return   maximum input size.
         */
        virtual unsigned int maxInputSize();
    };
}