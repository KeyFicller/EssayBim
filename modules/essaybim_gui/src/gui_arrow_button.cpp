#include "gui_arrow_button.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{
    
    ArrowButton::ArrowButton(const std::string& name, eArrowDirection direction /*= eArrowDirection::kRight*/, const WidgetSlot& slot /*= nullptr*/)
        : Button(name, slot), m_Direction(direction)
    {

    }

    bool ArrowButton::subOnImguiRender()
    {
        return ImGui::ArrowButton(EB_IMPL()->name().c_str(), (ImGuiDir)m_Direction);
    }

    void ArrowButton::pushStyle()
    {
        ImGui::PushButtonRepeat(true);
    }

    void ArrowButton::popStyle()
    {
        ImGui::PopButtonRepeat();
    }

}