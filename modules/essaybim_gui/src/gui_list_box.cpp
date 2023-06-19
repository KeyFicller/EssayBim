#include "gui_list_box.h"

#include "gui_enum_widget_impl.h"

#include "basic_color_defines.h"

#include <imgui.h>

namespace EB
{

    ListBox::ListBox(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot /*= nullptr*/)
        : EnumWidget(*new EnumWidgetImpl(this, name, index, items))
    {
        setSlot(slot);
    }

    bool ListBox::subOnImguiRender()
    {
        return ImGui::ListBox(name().c_str(), &EB_IMPL(EnumWidget)->index(), EB_IMPL(EnumWidget)->itemCStrs().data(), static_cast<int>(EB_IMPL(EnumWidget)->itemCStrs().size()));
    }

    void ListBox::pushStyle()
    {
        ImGui::PushStyleColor(ImGuiCol_TabActive, EB_CYAN_4);
    }

    void ListBox::popStyle()
    {
        ImGui::PopStyleColor();
    }

}
