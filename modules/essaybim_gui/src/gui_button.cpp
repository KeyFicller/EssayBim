#include "gui_button.h"

#include <imgui.h>

namespace EB
{

    Button::Button(const std::string& name, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name)
    {
        setSlot(slot);
    }

    Button::Button(const std::string& name, const Vec2f& size, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name), m_Size(size)
    {
        setSlot(slot);
    }

    bool Button::subOnImguiRender()
    {
        return ImGui::Button(name().c_str(), m_Size);
    }

}