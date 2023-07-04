#pragma once

#include "gui_base_widget.h"

namespace EB
{
    /**
     * @brief  this class defines collapsing header.
     */
    class EB_GUI_EXPORT CollapsingHeader : public BaseWidget
    {
    public:
        /**
         * @brief  constructor for collapsing header.
         * @param[in]   name       name of widget.
         * @param[in]   visible    whether collapsing header is opened.
         * @param[in]   slot       main function on collapsing header opened.
         */
        CollapsingHeader(const std::string& name, bool& visible, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < whether collapsing header is opened > */
        bool& m_Visible;
    };
}