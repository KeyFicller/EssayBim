#include "gui_input_text.h"

#include "gui_text_input_widget_impl.h"

#include <imgui.h>

namespace EB
{

    InputText::InputText(const std::string& name, std::string& editStr, const WidgetSlot& slot /*= nullptr*/)
        : TextInputWidget(*new TextInputWidgetImpl(this, name, editStr))
    {
        setSlot(slot);
    }

    bool InputText::subOnImguiRender()
    {
        EB_IMPL(TextInputWidget)->beginInteract();
        bool interacted = ImGui::InputText(EB_IMPL()->name().c_str(), EB_IMPL(TextInputWidget)->editBuff(), maxInputSize());
        EB_IMPL(TextInputWidget)->endInteract();
        return interacted;
    }

}