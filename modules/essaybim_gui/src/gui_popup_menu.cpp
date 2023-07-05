#include "gui_popup_menu.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{

    PopupMenuItem::PopupMenuItem(const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget("")
    {
        setSlot(slot);
    }

    bool PopupMenuItem::subOnImguiRender()
    {
        return true;
    }

    PopupMenu::PopupMenu(const std::string& name, const std::vector<PopupMenuItem>& menuItems /*= {}*/)
        : BaseWidget(name), m_MenuItems(menuItems)
    {
        setSlot([&]() {
            for (auto& menuItem : m_MenuItems) {
                menuItem.onGuiRender();
            }
        });
    }

    bool PopupMenu::subOnImguiRender()
    {
        return ImGui::BeginPopup(EB_IMPL()->name().c_str());
    }

    void PopupMenu::postAction()
    {
        ImGui::EndPopup();
    }

    void PopupMenu::addMenuItem(const PopupMenuItem& item)
    {
        m_MenuItems.emplace_back(item);
    }

    BaseWidget::WidgetSlot PopupMenu::activateSignal()
    {

    }

}