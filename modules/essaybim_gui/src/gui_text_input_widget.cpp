#include "gui_text_input_widget.h"

#include "gui_text_input_widget_impl.h"

namespace EB
{

    TextInputWidget::TextInputWidget(const std::string& name, std::string& editStr, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(*new TextInputWidgetImpl(this, name, editStr))
    {
        setSlot(slot);
    }

    TextInputWidget::TextInputWidget(TextInputWidgetImpl& impl)
        : BaseWidget(impl)
    {

    }

    unsigned int TextInputWidget::maxInputSize()
    {
        return 256;
    }

}