#include "gui_window_widget.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

namespace EB
{

    WindowWidget::WindowWidget(const std::string& name, const WidgetSlot& slot)
        : BaseWidget(name)
    {
        setSlot(slot);
    }

    bool WindowWidget::isHovered()
    {
        return ImGui::IsWindowHovered();
    }

    std::vector<Vec2f> WindowWidget::viewportBounds()
    {
        std::vector<Vec2f> res;
        ImVec2 viewportMinRegion = ImGui::GetWindowContentRegionMin();
        ImVec2 viewportMaxRegion = ImGui::GetWindowContentRegionMax();
        ImVec2 viewportOffset = ImGui::GetWindowPos();
        res.emplace_back(Vec2f{ viewportMinRegion.x + viewportOffset.x, viewportMinRegion.y + viewportOffset.y });
        res.emplace_back(Vec2f{ viewportMaxRegion.x + viewportOffset.x, viewportMaxRegion.y + viewportOffset.y });
        return res;
    }

    Vec2f WindowWidget::viewportAvailiable()
    {
        return ImGui::GetContentRegionAvail();
    }

    bool WindowWidget::subOnImguiRender()
    {
        ImGui::Begin(EB_IMPL()->name().c_str());
        return true;
    }

    void WindowWidget::postAction()
    {
        ImGui::End();
    }

}