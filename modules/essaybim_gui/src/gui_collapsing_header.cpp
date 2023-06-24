#include "gui_collapsing_header.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{

    CollapsingHeader::CollapsingHeader(const std::string& name, bool& visible, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name), m_Visible(visible)
    {
        setSlot(slot);
    }

    bool CollapsingHeader::subOnImguiRender()
    {
        return ImGui::CollapsingHeader(EB_IMPL()->name().c_str(), m_Visible);
    }

}