#pragma once

#include "gui_base_widget.h"

namespace EB
{
    /**
     * @brief  this class defines radio button class
     */
    class EB_GUI_EXPORT RadioButton : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for radio button.
         * @param[in]    name     name of widget.
         * @param[in]    index    index of radio group.
         * @param[in]    myIndex  index of this radio button.
         */
        RadioButton(const std::string& name, int& index, int myIndex, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < index of radio group > */
        int& m_Index;

        /** < index of this radio button > */
        int m_MyIndex;
    };
}