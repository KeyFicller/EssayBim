#include "gui_slider_enum.h"

#include "gui_enum_widget_impl.h"

#include <imgui.h>

namespace EB
{

    SliderEnum::SliderEnum(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot /*= nullptr*/)
        : EnumWidget(*new EnumWidgetImpl(this, name, index, items))
    {
        setSlot(slot);
    }

    bool SliderEnum::subOnImguiRender()
    {
        return ImGui::SliderInt(
            name().c_str(),
            &EB_IMPL(EnumWidget)->index(),
            0,
            static_cast<int>(EB_IMPL(EnumWidget)->itemCStrs().size()) - 1,
            EB_IMPL(EnumWidget)->itemStrs().at(EB_IMPL(EnumWidget)->index()).c_str()
        );
    }

}