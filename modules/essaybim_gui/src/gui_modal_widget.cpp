#include "gui_modal_widget.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{

    ModalWidget::ModalWidget(const std::string& name, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(name)
    {
        setSlot(slot);
    }

    void ModalWidget::closeCurrentModalWidget()
    {
        ImGui::CloseCurrentPopup();
    }

    BaseWidget::WidgetSlot ModalWidget::activeSignal()
    {
        return EB_WIDGET_SLOT(ImGui::OpenPopup(EB_IMPL()->name().c_str()););
    }

    bool ModalWidget::subOnImguiRender()
    {
        return ImGui::BeginPopupModal(EB_IMPL()->name().c_str());
    }

    void ModalWidget::postAction()
    {
        ImGui::EndPopup();
    }

}