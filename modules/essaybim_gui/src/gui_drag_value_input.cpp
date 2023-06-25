#include "gui_drag_value_input.h"

#include "gui_value_input_widget_impl.h"

namespace EB
{

    DragValueInputF::DragValueInputF(const std::string& name, float& value, const ValueInputWidget::ValueBoundary& boundary, const WidgetSlot& slot /*= nullptr*/)
        : ValueInputWidget(name, &value, 1, boundary, slot)
    {

    }

    DragValueInputF::DragValueInputF(const std::string& name, Vec2f& value, const ValueInputWidget::ValueBoundary& boundary, const WidgetSlot& slot /*= nullptr*/)
        : ValueInputWidget(name, &value, 2, boundary, slot)
    {

    }

    DragValueInputF::DragValueInputF(const std::string& name, Vec3f& value, const ValueInputWidget::ValueBoundary& boundary, const WidgetSlot& slot /*= nullptr*/)
        : ValueInputWidget(name, &value, 3, boundary, slot)
    {

    }

    DragValueInputF::DragValueInputF(const std::string& name, Vec4f& value, const ValueInputWidget::ValueBoundary& boundary, const WidgetSlot& slot /*= nullptr*/)
        : ValueInputWidget(name, &value, 4, boundary, slot)
    {

    }

    bool DragValueInputF::subOnImguiRender()
    {
        auto [lb, ub] = EB_IMPL(ValueInputWidget)->realVB();
        switch (EB_IMPL(ValueInputWidget)->component())
        {
        case 1:
            return ImGui::DragFloat(EB_IMPL()->name().c_str(), EB_IMPL(ValueInputWidget)->real(), (ub - lb) / 10.f, lb, ub);
        case 2:
            return ImGui::DragFloat2(EB_IMPL()->name().c_str(), EB_IMPL(ValueInputWidget)->real(), (ub - lb) / 10.f, lb, ub);
        case 3:
            return ImGui::DragFloat3(EB_IMPL()->name().c_str(), EB_IMPL(ValueInputWidget)->real(), (ub - lb) / 10.f, lb, ub);
        case 4:
            return ImGui::DragFloat4(EB_IMPL()->name().c_str(), EB_IMPL(ValueInputWidget)->real(), (ub - lb) / 10.f, lb, ub);
        }
        return false;
    }

}