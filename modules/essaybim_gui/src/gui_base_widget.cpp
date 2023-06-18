#include "gui_base_widget.h"

#include "gui_base_widget_impl.h"

namespace EB
{

    BaseWidget::BaseWidget(const std::string& name /*= std::string()*/)
    {
        EB_IMPL() = createScoped<BaseWidgetImpl>(this, name);
    }

    BaseWidget::BaseWidget(BaseWidgetImpl& impl)
    {
        EB_IMPL() = std::unique_ptr<BaseWidgetImpl>(&impl);
    }

    BaseWidget::~BaseWidget()
    {
        EB_IMPL().reset();
    }

    void BaseWidget::onGuiRender()
    {
        EB_IMPL()->onGuiRender();
    }

    void BaseWidget::setNameVisibility(bool visible /*= true*/)
    {
        EB_IMPL()->setNameVisibility(visible);
    }

    void BaseWidget::setEnabled(bool enable /*= true*/)
    {
        EB_IMPL()->setEnabled(enable);
    }

    void BaseWidget::setToolTip(const WidgetSlot& slot)
    {
        EB_IMPL()->setToolTip(slot);
    }

    bool BaseWidget::isNameVisible() const
    {
        return EB_IMPL()->isNameVisible();
    }

    void BaseWidget::setSlot(const WidgetSlot& slot)
    {
        EB_IMPL()->setSlot(slot);
    }

    const std::string& BaseWidget::name() const
    {
        return EB_IMPL()->name();
    }

    void BaseWidget::pushStyle()
    {

    }

    void BaseWidget::popStyle()
    {

    }

}