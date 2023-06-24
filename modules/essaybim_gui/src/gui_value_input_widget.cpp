#include "gui_value_input_widget.h"

#include "gui_value_input_widget_impl.h"

#include <imgui.h>

namespace EB
{

    ValueInputWidget::ValueBoundary ValueInputWidget::vb_0_to_1 = { 0.0, 1.0 };

    ValueInputWidget::ValueBoundary ValueInputWidget::vb_0_to_100 = { 0.0, 100.0 };

    ValueInputWidget::ValueBoundary ValueInputWidget::vb_negInf_to_posInf = { -1e6, 1e6 };

    ValueInputWidget::ValueInputWidget(const std::string& name, void* data, int component, const ValueBoundary& boundary, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(*new ValueInputWidgetImpl(this, name, data, component, boundary))
    {
        setSlot(slot);
    }

    ValueInputWidget::ValueInputWidget(ValueInputWidgetImpl& impl)
        : BaseWidget(impl)
    {

    }

    void ValueInputWidget::setValueBoundary(const ValueBoundary& boundary)
    {
        EB_IMPL(ValueInputWidget)->setValueBoundary(boundary);
    }

}