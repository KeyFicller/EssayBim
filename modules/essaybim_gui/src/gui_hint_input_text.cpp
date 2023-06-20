#include "gui_hint_input_text.h"

#include "gui_text_input_widget_impl.h"

#include <imgui.h>

namespace EB
{

    HintInputText::HintInputText(const std::string& name, std::string& editStr, const std::string& hintStr, const WidgetSlot& slot /*= nullptr*/)
        : TextInputWidget(*new TextInputWidgetImpl(this, name, editStr)), m_HintStr(hintStr)
    {
        setSlot(slot);
    }

    bool HintInputText::subOnImguiRender()
    {
        EB_IMPL(TextInputWidget)->beginInteract();
        bool interacted = ImGui::InputTextWithHint(EB_IMPL()->name().c_str(), m_HintStr.c_str(), EB_IMPL(TextInputWidget)->editBuff(), maxInputSize());
        EB_IMPL(TextInputWidget)->endInteract();
        return interacted;
    }

}