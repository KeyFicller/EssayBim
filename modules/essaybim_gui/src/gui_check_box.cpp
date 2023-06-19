#include "gui_check_box.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{
    CheckBox::CheckBox(const std::string& name, bool& value, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name), m_Value(value)
    {
        setSlot(slot);
    }

    bool CheckBox::subOnImguiRender()
    {
        return ImGui::Checkbox(name().c_str(), &m_Value);
    }

}