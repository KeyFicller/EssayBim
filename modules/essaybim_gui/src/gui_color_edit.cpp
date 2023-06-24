#include "gui_color_edit.h"

#include "gui_value_input_widget_impl.h"

namespace EB
{

    ColorEdit::ColorEdit(const std::string& name, Vec3& value, const WidgetSlot& slot /*= nullptr*/)
        : ValueInputWidget(name, &value, 3, ValueInputWidget::vb_0_to_1, slot)
    {

    }

    ColorEdit::ColorEdit(const std::string& name, Vec4& value, const WidgetSlot& slot /*= nullptr*/)
        : ValueInputWidget(name, &value, 4, ValueInputWidget::vb_0_to_1, slot)
    {

    }

    bool ColorEdit::subOnImguiRender()
    {
        switch (EB_IMPL(ValueInputWidget)->component())
        {
        case 3:
            return ImGui::ColorEdit3(EB_IMPL()->name().c_str(), EB_IMPL(ValueInputWidget)->real());
        case 4:
            return ImGui::ColorEdit4(EB_IMPL()->name().c_str(), EB_IMPL(ValueInputWidget)->real());
        }
        return false;
    }

}