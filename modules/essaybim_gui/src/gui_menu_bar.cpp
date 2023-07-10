#include "gui_menu_bar.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{

    MenuBarMenuItem::MenuBarMenuItem(const std::string& name, const std::string& shortCut, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name), m_ShortCut(shortCut)
    {
        setSlot(slot);
    }

    bool MenuBarMenuItem::subOnImguiRender()
    {
        return ImGui::MenuItem(EB_IMPL()->name().c_str(), m_ShortCut.c_str());
    }

    MenuBarMenu::MenuBarMenu(const std::string& name)
        : BaseWidget(name)
    {
        setSlot([&]() {
            for (auto& menuItem : m_MenuItems) {
                menuItem->onGuiRender();
            }
        });
    }

    bool MenuBarMenu::subOnImguiRender()
    {
        return ImGui::BeginMenu(EB_IMPL()->name().c_str());
    }

    void MenuBarMenu::postAction()
    {
        ImGui::EndMenu();
    }

    void MenuBarMenu::addMenuItem(const Shared<MenuBarMenuItem>& item)
    {
        m_MenuItems.push_back(item);
    }

    MenuBar::MenuBar()
        : BaseWidget()
    {
        setSlot([&]() {
            for (auto& menu : m_Menus) {
                menu->onGuiRender();
            }
        });
    }

    bool MenuBar::subOnImguiRender()
    {
        return ImGui::BeginMenuBar();
    }

    void MenuBar::postAction()
    {
        ImGui::EndMenuBar();
    }

    void MenuBar::addMenu(const Shared<MenuBarMenu>& menu)
    {
        m_Menus.push_back(menu);
    }

}