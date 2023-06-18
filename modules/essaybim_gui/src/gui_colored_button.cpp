#include "gui_colored_button.h"

#include "gui_gui_layer.h"

#include <imgui.h>

namespace EB
{

    ColoredButton::ButtonColor::ButtonColor()
    {
        static Vec4 defaultNormal = GuiTheme().m_Colors.Button;
        static Vec4 defaultHovered = GuiTheme().m_Colors.ButtonHovered;
        static Vec4 defaultClicked = GuiTheme().m_Colors.ButtonActive;

        Normal = defaultNormal;
        Hovered = defaultHovered;
        Clicked = defaultClicked;
    }

    ColoredButton::ButtonColor::ButtonColor(const Vec4& normal, const Vec4& hovered, const Vec4& clicked)
        : Normal(normal), Hovered(hovered), Clicked(clicked)
    {

    }

    ColoredButton::ColoredButton(const std::string& name, const ButtonColor& color, const WidgetSlot& slot /*= nullptr*/)
        : Button(name, slot), m_Color(color)
    {

    }

    ColoredButton::ColoredButton(const std::string& name, const Vec2& size, const ButtonColor& color, const WidgetSlot& slot /*= nullptr*/)
        : Button(name, size, slot), m_Color(color)
    {

    }

    void ColoredButton::pushStyle()
    {
        ImGui::PushStyleColor(ImGuiCol_Button, m_Color.Normal);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, m_Color.Hovered);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, m_Color.Clicked);
    }

    void ColoredButton::popStyle()
    {
        ImGui::PopStyleColor(3);
    }

}