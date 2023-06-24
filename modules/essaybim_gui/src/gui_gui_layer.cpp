#include "gui_gui_layer.h"

#include "gui_button.h"
#include "gui_colored_button.h"
#include "gui_check_box.h"
#include "gui_image_button.h"
#include "gui_combo_box.h"
#include "gui_list_box.h"
#include "gui_slider_enum.h"
#include "gui_text.h"
#include "gui_arrow_button.h"
#include "gui_input_text.h"
#include "gui_multiline_input_text.h"
#include "gui_hint_input_text.h"
#include "gui_radio_button.h"
#include "gui_radio_button_group.h"
#include "gui_drag_value_input.h"
#include "gui_slider_value_input.h"
#include "gui_color_edit.h"
#include "gui_collapsing_header.h"
#include "gui_tree_node.h"
#include "gui_range_edit.h"
#include "gui_tap_widget.h"
#include "gui_modal_widget.h"
#include "gui_image_widget.h"
#include "gui_drag_and_drop.h"

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
            static ColoredButton::ButtonColor color{ EB_RED_4, EB_GREEN_4, EB_BLUE_4 };
            // notes:  i found that if i try to destruct global instance created by OpenGL, there will be an error
            static Texture2D* texture = new Texture2D(FileServer::instance().resourcesPathRoot() + "\\icons\\error.png");
            static int radioIndex = 0;
            
            EB_WIDGET_IMMEDIATE(Button, "button", EB_WIDGET_SLOT(EB_CORE_INFO("Button Clicked");));
            EB_WIDGET_IMMEDIATE(ColoredButton, "colored button", color, EB_WIDGET_SLOT(EB_CORE_INFO("Colored Button Clicked.");));
            EB_WIDGET_IMMEDIATE(ArrowButton, "arrow button", ArrowButton::eArrowDirection::kDown, EB_WIDGET_SLOT(EB_CORE_INFO("Arrow Button Clicked");));
            EB_WIDGET_IMMEDIATE(ImageButton, texture->rendererId(), Vec2(30.f, 30.f), EB_WIDGET_SLOT(EB_CORE_INFO("Image Button Clicked");));
            EB_WIDGET_IMMEDIATE(RadioButton, "radio button", radioIndex, 1, EB_WIDGET_SLOT(EB_CORE_INFO("Radio Button Clicked");));
            ImGui::Separator();
        }

        {   // check box
            static bool checked = false;
        
            EB_WIDGET_IMMEDIATE(CheckBox, "check box", checked, EB_WIDGET_SLOT(EB_CORE_INFO("Check Box Clicked");));
            ImGui::Separator();
        }

        {   // enum widget and it's derivations
            static std::vector<std::string> elements = { "gold", "wood", "water", "fire", "dirt" };
            static int index = 0;

            EB_WIDGET_IMMEDIATE(ComboBox, "elements", index, elements, EB_WIDGET_SLOT(EB_CORE_INFO("Combo Box Interacted");));
            EB_WIDGET_IMMEDIATE(ListBox, "elements", index, elements, EB_WIDGET_SLOT(EB_CORE_INFO("List Box Interacted");));
            // crash bug, disable for now.
            // EB_WIDGET_IMMEDIATE(SliderEnum, "elements", index, elements, EB_WIDGET_SLOT(EB_CORE_INFO("Slider Enum Interacted");));
            EB_WIDGET_IMMEDIATE(RadioButtonGroup, "elements", index, elements, EB_WIDGET_SLOT(EB_CORE_INFO("Ratio Button Group Interacted");));
            ImGui::Separator();
        }

        {   // text
        
            EB_WIDGET_IMMEDIATE(Text, "text by 1");
            EB_WIDGET_IMMEDIATE(Text, "text by %d", 2);
            EB_WIDGET_IMMEDIATE(ColoredText, EB_CYAN_4, "color text by 1");
            EB_WIDGET_IMMEDIATE(ColoredText, EB_CYAN_4, "color text by %d", 2);
            EB_WIDGET_IMMEDIATE(GrayText, "gray text by 1");
            EB_WIDGET_IMMEDIATE(GrayText, "gray text by %d", 2);
            ImGui::Separator();
        }

        {   // input text
            static std::string editingStr = "hello world";

            EB_WIDGET_IMMEDIATE(InputText, "input text", editingStr);
            EB_WIDGET_IMMEDIATE(MultilineInputText, "multiline input text", editingStr);
            EB_WIDGET_IMMEDIATE(HintInputText, "hint input text", editingStr, "enter");
            ImGui::Separator();
        }

        {   // interact value input
            static float v = 0.0;
            static Vec2 v2;
            static Vec3 v3;
            static Vec4 v4;

            EB_WIDGET_IMMEDIATE(DragValueInputF, "dvif", v);
            EB_WIDGET_IMMEDIATE(DragValueInputF, "dvif2", v2);
            EB_WIDGET_IMMEDIATE(DragValueInputF, "dvif3", v3);
            EB_WIDGET_IMMEDIATE(DragValueInputF, "dvif4", v4);
            EB_WIDGET_IMMEDIATE(SliderValueInputF, "svif", v);
            EB_WIDGET_IMMEDIATE(SliderValueInputF, "svif2", v2);
            EB_WIDGET_IMMEDIATE(SliderValueInputF, "svif3", v3);
            EB_WIDGET_IMMEDIATE(SliderValueInputF, "svif4", v4);
            EB_WIDGET_IMMEDIATE(ColorEdit, "ce3", v3);
            EB_WIDGET_IMMEDIATE(ColorEdit, "ce4", v4);
            ImGui::Separator();
        }

        {   // collapsing header
            static bool visible = true;

            EB_WIDGET_IMMEDIATE(CollapsingHeader, "collapsing header", visible,
                EB_WIDGET_SLOT(EB_WIDGET_IMMEDIATE(Button, "sub button");)
            );
        }

        {   // tree node
        
            Shared<TreeNode> t1 = createShared<TreeNode>("tree A");
            Shared<TreeNode> t2 = createShared<TreeNode>("tree B");
            Shared<TreeNode> t3 = createShared<TreeNode>("tree C");
            t1->addChild(t2);
            t2->addChild(t3);

            t1->onGuiRender();
            ImGui::Separator();
        }

        {   // range edit.
            static int mini, maxi;
            static float minf, maxf;
            
            EB_WIDGET_IMMEDIATE(RangeEditI, "range edit int", mini, maxi, EB_WIDGET_SLOT(EB_CORE_INFO("range edit int interacted");));
            EB_WIDGET_IMMEDIATE(RangeEditF, "range edit float", minf, maxf, EB_WIDGET_SLOT(EB_CORE_INFO("range edit float interacted");));
            ImGui::Separator();
        }

        {   // tab widget
            Shared<TabWidgetItem> item1 = createShared<TabWidgetItem>("item 1");
            Shared<TabWidgetItem> item2 = createShared<TabWidgetItem>("item 2");
            Shared<TabWidget> tabWidget = createShared<TabWidget>("tab widget");
            tabWidget->addTabItem(item1);
            tabWidget->addTabItem(item2);

            tabWidget->onGuiRender();
            ImGui::Separator();
        }

        {   // modal widget
            ModalWidget modal("delete object", EB_WIDGET_SLOT(
                EB_WIDGET_IMMEDIATE(ColoredText, EB_RED_4, "confirm ?");
                EB_WIDGET_IMMEDIATE(Button, "yes", EB_WIDGET_SLOT(ModalWidget::closeCurrentModalWidget();));
            ));
            EB_WIDGET_IMMEDIATE(Button, "delete", modal.activeSignal());
            modal.onGuiRender();
            ImGui::Separator();
        }

        {   // image widget
            // notes:  i found that if i try to destruct global instance created by OpenGL, there will be an error
            static Texture2D* texture = new Texture2D(FileServer::instance().resourcesPathRoot() + "\\textures\\game.jpg");

            EB_WIDGET_IMMEDIATE(ImageWidgetWithMagnifier, texture->rendererId(), Vec2(640.f, 400.f), 4.0f);
            ImGui::Separator();
        }

        {   // drag and drop
            static Vec3 v1;
            static Vec3 v2;

            EB_WIDGET_IMMEDIATE(DragValueInputF, "dvif3_1", v1);
            EB_WIDGET_IMMEDIATE(DragSource, "drag vec3", [&](Filer* filer) {
                filer->writeVec3(v1);
            });
            EB_WIDGET_IMMEDIATE(DragValueInputF, "dvif3_2", v2);
            EB_WIDGET_IMMEDIATE(DropTarget, "drag vec3", [&](const Filer* filer) {
                v2 = filer->readVec3();
            });
            ImGui::Separator();
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