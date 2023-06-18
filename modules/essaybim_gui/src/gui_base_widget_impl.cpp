#include "gui_base_widget_impl.h"

#include "imgui.h"

namespace EB
{
    namespace
    {
        std::string anonymousWidgetName()
        {
            static int index = 0;
            char buff[256];
            sprintf_s(buff, 256, "AnonymouseWidget-%d", index++);
            return buff;
        }
    }


    BaseWidgetImpl::BaseWidgetImpl(BaseWidget* pFacade, const std::string& name)
        : m_pFacade(pFacade), m_Name(name.empty() ? anonymousWidgetName() : name)
    {

    }

    BaseWidgetImpl::~BaseWidgetImpl()
    {

    }

    void BaseWidgetImpl::onGuiRender()
    {
        if (m_Enabled) {
            m_pFacade->pushStyle();
            if (m_pFacade->subOnImguiRender()) {
                if (m_Slot) {
                    m_Slot();
                }
            }
            m_pFacade->popStyle();
            if (m_TipSlot && ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal)) {
                ImGui::BeginTooltip();
                m_TipSlot();
                ImGui::EndTooltip();
            }
        }
    }

    void BaseWidgetImpl::setNameVisibility(bool visible /*= true*/)
    {
        m_NameVisible = visible;
    }

    bool BaseWidgetImpl::isNameVisible() const
    {
        return m_NameVisible;
    }

    void BaseWidgetImpl::setEnabled(bool enable /*= true*/)
    {
        m_Enabled = true;
    }

    void BaseWidgetImpl::setToolTip(const BaseWidget::WidgetSlot& slot)
    {
        m_TipSlot = slot;
    }

    void BaseWidgetImpl::setSlot(const BaseWidget::WidgetSlot& slot)
    {
        m_Slot = slot;
    }

    const std::string& BaseWidgetImpl::name() const
    {
        return m_Name;
    }

}