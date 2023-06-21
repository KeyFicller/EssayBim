#include "gui_radio_button_group.h"

#include "gui_enum_widget_impl.h"

#include <imgui.h>

namespace EB
{

    RadioButtonGroup::RadioButtonGroup(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot /*= nullptr*/)
        : EnumWidget(name, index, items, slot)
    {

    }

    void RadioButtonGroup::setSameLine(bool set /*= true*/)
    {
        m_SameLine = set;
    }

    void RadioButtonGroup::setSeparateHeader(bool set /*= true*/)
    {
        m_SeparateHeader = set;
    }

    bool RadioButtonGroup::subOnImguiRender()
    {
        ImGui::Text((EB_IMPL()->name() + ":").c_str());
        if (!m_SeparateHeader) {
            ImGui::SameLine();
        }
        bool interacted = false;
        auto& items = EB_IMPL(EnumWidget)->itemCStrs();
        for (unsigned int i = 0; i < items.size(); i++) {
            interacted |= ImGui::RadioButton(items[i], &EB_IMPL(EnumWidget)->index(), i);
            if (i != items.size() - 1) {
                if (m_SameLine) {
                    ImGui::SameLine();
                }
            }
        }

        return interacted;
    }

}