#include "gui_gui_layer.h"

#include "gui_button.h"
#include "gui_colored_button.h"
#include "gui_check_box.h"
#include "gui_image_button.h"
#include "gui_combo_box.h"
#include "gui_list_box.h"
#include "gui_slider_enum.h"

#include "basic_assert.h"
#include "basic_color_defines.h"
#include "renderer_texture.h"

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

        setTheme();

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
        // ImGui::ShowDemoWindow();
        ImGui::Begin("Test Widgets");

        {   // button widget test
            EB_WIDGET_IMMEDIATE(Button, "button", EB_WIDGET_SLOT(EB_CORE_INFO("Button Clicked");));
        }

        {   // colored button widget test
            static ColoredButton::ButtonColor color{ EB_RED_4, EB_GREEN_4, EB_BLUE_4 };
            
            EB_WIDGET_IMMEDIATE(ColoredButton, "colored button", color, EB_WIDGET_SLOT(EB_CORE_INFO("Colored Button Clicked.");));
        }

        {   // check box
            static bool checked = false;
        
            EB_WIDGET_IMMEDIATE(CheckBox, "check box", checked, EB_WIDGET_SLOT(EB_CORE_INFO("Check Box Clicked");));
        }

        {   // image button
            // notes:  i found that if i try to destruct global instance created by OpenGL, there will be an error
            static Texture2D* texture = new Texture2D(FileServer::instance().resourcesPathRoot() + "\\icons\\error.png");

            EB_WIDGET_IMMEDIATE(ImageButton, texture->rendererId(), Vec2(30.f, 30.f), EB_WIDGET_SLOT(EB_CORE_INFO("Image Button Clicked");));
        }

        {   // enum widget and it's derivations
            static std::vector<std::string> elements = { "gold", "wood", "water", "fire", "dirt" };
            static int index = 0;

            EB_WIDGET_IMMEDIATE(ComboBox, "elements", index, elements, EB_WIDGET_SLOT(EB_CORE_INFO("Combo Box Interacted");));
            EB_WIDGET_IMMEDIATE(ListBox, "elements", index, elements, EB_WIDGET_SLOT(EB_CORE_INFO("List Box Interacted");));
            // crash bug, disable for now.
            // EB_WIDGET_IMMEDIATE(SliderEnum, "elements", index, elements, EB_WIDGET_SLOT(EB_CORE_INFO("Slider Enum Interacted");));
        }

        ImGui::End();
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

    void GuiLayer::setTheme(const GuiTheme& theme /*= GuiTheme()*/)
    {
        auto& colors = ImGui::GetStyle().Colors;
        colors[ImGuiCol_WindowBg] = theme.m_Colors.WindowBg;

        // Headers
        colors[ImGuiCol_Header] = theme.m_Colors.Header;
        colors[ImGuiCol_HeaderHovered] = theme.m_Colors.HeaderHovered;
        colors[ImGuiCol_HeaderActive] = theme.m_Colors.HeaderActive;

        // Buttons
        colors[ImGuiCol_Button] = theme.m_Colors.Button;
        colors[ImGuiCol_ButtonHovered] = theme.m_Colors.ButtonHovered;
        colors[ImGuiCol_ButtonActive] = theme.m_Colors.ButtonActive;

        // Frame BG
        colors[ImGuiCol_FrameBg] = theme.m_Colors.FrameBg;
        colors[ImGuiCol_FrameBgHovered] = theme.m_Colors.FrameBgHovered;
        colors[ImGuiCol_FrameBgActive] = theme.m_Colors.FrameBgActive;

        // Tabs
        colors[ImGuiCol_Tab] = theme.m_Colors.Tab;
        colors[ImGuiCol_TabHovered] = theme.m_Colors.TabHovered;
        colors[ImGuiCol_TabActive] = theme.m_Colors.TabActive;
        colors[ImGuiCol_TabUnfocused] = theme.m_Colors.TabUnfocused;
        colors[ImGuiCol_TabUnfocusedActive] = theme.m_Colors.TabUnfocusedActive;

        // Title
        colors[ImGuiCol_TitleBg] = theme.m_Colors.TitleBg;
        colors[ImGuiCol_TitleBgActive] = theme.m_Colors.TitleBgActive;
        colors[ImGuiCol_TitleBgCollapsed] = theme.m_Colors.TitleBgCollapsed;

        ImGuiIO& io = ImGui::GetIO();
        io.Fonts->AddFontFromFileTTF(theme.m_Fonts.FontPath.c_str(), theme.m_Fonts.FontSize);
        io.FontDefault = io.Fonts->AddFontFromFileTTF(theme.m_Fonts.DefaultFontPath.c_str(), theme.m_Fonts.FontSize);
    }

}