#include "gui_range_edit.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{

    RangeEditF::RangeEditF(const std::string& name, float& min, float& max, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name), m_Min(min), m_Max(max)
    {
        setSlot(slot);
    }

    bool RangeEditF::subOnImguiRender()
    {
        return ImGui::DragFloatRange2(EB_IMPL()->name().c_str(), &m_Min, &m_Max);
    }

    RangeEditI::RangeEditI(const std::string& name, int& min, int& max, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name), m_Min(min), m_Max(max)
    {
        setSlot(slot);
    }

    bool RangeEditI::subOnImguiRender()
    {
        return ImGui::DragIntRange2(EB_IMPL()->name().c_str(), &m_Min, &m_Max);
    }

}