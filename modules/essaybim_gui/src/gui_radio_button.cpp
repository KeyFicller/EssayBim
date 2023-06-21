#include "gui_radio_button.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{

    RadioButton::RadioButton(const std::string& name, int& index, int myIndex, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name), m_Index(index), m_MyIndex(myIndex)
    {
        setSlot(slot);
    }

    bool RadioButton::subOnImguiRender()
    {
        return ImGui::RadioButton(EB_IMPL()->name().c_str(), &m_Index, m_MyIndex);
    }

}