#include "gui_enum_widget.h"

#include "gui_enum_widget_impl.h"

namespace EB
{

    EnumWidget::EnumWidget(const std::string& name, int& index, const std::vector<std::string>& items, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(*new EnumWidgetImpl(this, name, index, items))
    {
        setSlot(slot);
    }

    EnumWidget::EnumWidget(EnumWidgetImpl& impl)
        : BaseWidget(impl)
    {

    }

}