#include "gui_combo_box.h"

#include "gui_enum_widget_impl.h"

#include <imgui.h>

namespace EB
{

    ComboBox::ComboBox(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot /*= nullptr*/)
        : EnumWidget(* new EnumWidgetImpl(this, name, index, items))
    {
        setSlot(slot);
    }

    bool ComboBox::subOnImguiRender()
    {
        return ImGui::Combo(name().c_str(), &EB_IMPL(EnumWidget)->index(), EB_IMPL(EnumWidget)->itemCStrs().data(), static_cast<int>(EB_IMPL(EnumWidget)->itemCStrs().size()));
    }

}