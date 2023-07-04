#pragma once

#include "gui_enum_widget.h"

namespace EB
{
    /**
     * @brief  this class defines radio button group.
     */
    class EB_GUI_EXPORT RadioButtonGroup : public EnumWidget
    {
    public:
        /**
         * @brief  constructor for radio button group.
         * @param[in]   name     name of enum widget.
         * @param[in]   index    select index of enum widget.
         * @param[in]   items    enum items.
         * @param[in]   slot     main function on enum widget triggered.
         */
        RadioButtonGroup(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot = nullptr);

    public:
        /**
         * @brief  set all radio button same line.
         * @param[in]  set       whether set or not.
         */
        void setSameLine(bool set = true);

        /**
         * @brief  set header and buttons same line.
         * @param[in]  set       whether set or not.
         */
        void setSeparateHeader(bool set = true);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < whether all radio button same line > */
        bool m_SameLine = true;
        
        /** < whether header and buttons same line > */
        bool m_SeparateHeader = true;
    };
}