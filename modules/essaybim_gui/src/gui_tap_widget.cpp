#include "gui_tap_widget.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{
    namespace {
        ImGuiTabBarFlags s_flags = ImGuiTabBarFlags_TabListPopupButton |
                                   ImGuiTabBarFlags_AutoSelectNewTabs;
    }

    TabWidgetItem::TabWidgetItem(const std::string& name, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name)
    {
        setSlot(slot);
    }

    bool TabWidgetItem::subOnImguiRender()
    {
        return ImGui::BeginTabItem(EB_IMPL()->name().c_str());
    }

    void TabWidgetItem::postAction()
    {
        ImGui::EndTabItem();
    }

    TabWidget::TabWidget(const std::string& name, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name)
    {
        setSlot(slot);
    }

    void TabWidget::addTabItem(const Shared<TabWidgetItem>& item)
    {
        m_TabItems.push_back(item);
    }

    bool TabWidget::subOnImguiRender()
    {
        return ImGui::BeginTabBar(EB_IMPL()->name().c_str(), s_flags);
    }

    void TabWidget::postAction()
    {
        for (auto& item : m_TabItems) {
            item->onGuiRender();
        }
        ImGui::EndTabBar();
    }

}