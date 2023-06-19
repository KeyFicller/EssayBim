#pragma once

#include "gui_base_widget.h"

namespace EB
{
    class BaseWidgetImpl
    {
    public:
        BaseWidgetImpl(BaseWidget* pFacade, const std::string& name);
        virtual ~BaseWidgetImpl();

    public:
        void onGuiRender();
        void setNameVisibility(bool visible = true);
        bool isNameVisible() const;
        void setEnabled(bool enable = true);
        void setToolTip(const BaseWidget::WidgetSlot& slot);
        void setSlot(const BaseWidget::WidgetSlot& slot);
        const std::string name() const;
    protected:
        BaseWidget* m_pFacade = nullptr;
        std::string m_Name;
        bool m_NameVisible = true;
        bool m_Enabled = true;
        BaseWidget::WidgetSlot m_Slot = nullptr;
        BaseWidget::WidgetSlot m_TipSlot = nullptr;
    };
}