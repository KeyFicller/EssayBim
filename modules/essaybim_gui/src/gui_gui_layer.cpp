#include "gui_gui_layer.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace EB
{

    GuiLayer::GuiLayer(const std::string& name, const Shared<Window>& window)
        : Layer(name), m_Window(window)
    {

    }

    void GuiLayer::onAttach()
    {
        IMGUI_CHECKVERSION();

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(m_Window->native(), true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void GuiLayer::onDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void GuiLayer::onUpdate(const TimeStep& ts)
    {

    }

    void GuiLayer::onGuiRender()
    {
        ImGui::ShowDemoWindow();
    }

    void GuiLayer::onEvent(Event& e)
    {

    }

    void GuiLayer::begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void GuiLayer::end()
    {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2((float)m_Window->width(), (float)m_Window->height());

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

}