#include "gui_dock_space_impl.h"

#include "basic_vector.h"

#include <imgui.h>

namespace EB
{

    DockSpaceImpl& DockSpaceImpl::instance()
    {
        static DockSpaceImpl impl;
        return impl;
    }

    void DockSpaceImpl::begin(const std::string& name, bool& dockEnabled, bool fullScreen)
    {
        instance().m_DockName = name;
        instance().m_pDockEnabled = &dockEnabled;

        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

        if (fullScreen)
        {
            ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->Pos);
            ImGui::SetNextWindowSize(viewport->Size);
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        }

        if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) {
            window_flags |= ImGuiWindowFlags_NoBackground;
        }

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, Vec2f(0.f, 0.f));
        ImGui::Begin(instance().m_DockName.c_str(), instance().m_pDockEnabled, window_flags);
        ImGui::PopStyleVar();

        if (fullScreen) {
            ImGui::PopStyleVar(2);
        }

        ImGuiIO& io = ImGui::GetIO();
        ImGuiStyle& style = ImGui::GetStyle();
        float minWinSizeX = style.WindowMinSize.x;
        style.WindowMinSize.x = 400.f;
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
            ImGuiID dockspace_id = ImGui::GetID(instance().m_DockName.c_str());
            ImGui::DockSpace(dockspace_id, Vec2f(0.f, 0.f), dockspace_flags);
        }
        style.WindowMinSize.x = minWinSizeX;
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, Vec2f(0.f, 0.f));
    }

    void DockSpaceImpl::end()
    {
        ImGui::PopStyleVar();
        ImGui::End();
    }

}