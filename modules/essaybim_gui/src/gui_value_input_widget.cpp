#include "gui_value_input_widget.h"

#include "gui_value_input_widget_impl.h"

#include <imgui.h>

namespace EB
{

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