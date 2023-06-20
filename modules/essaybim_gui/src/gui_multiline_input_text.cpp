#include "gui_multiline_input_text.h"

#include "gui_text_input_widget_impl.h"

#include <imgui.h>

namespace EB
{

    MultilineInputText::MultilineInputText(const std::string& name, std::string& editStr, const WidgetSlot& slot /*= nullptr*/)
        : TextInputWidget(* new TextInputWidgetImpl(this, name, editStr))
    {
        setSlot(slot);
    }

    bool MultilineInputText::subOnImguiRender()
    {
        EB_IMPL(TextInputWidget)->beginInteract();
        bool interacted = ImGui::InputTextMultiline(EB_IMPL()->name().c_str(), EB_IMPL(TextInputWidget)->editBuff(), maxInputSize());
        EB_IMPL(TextInputWidget)->endInteract();
        return interacted;
    }

    unsigned int MultilineInputText::maxInputSize()
    {
        return 4096;
    }

}