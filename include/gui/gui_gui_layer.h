#pragma once

#include "basic_vector.h"
#include "basic_file_server.h"

#include "gui_export.h"
#include "window_window.h"
#include "window_layer.h"

namespace EB
{
    /**
     * @brief  this struct define theme properties.
     */
    struct GuiTheme
    {
        struct Colors
        {
            /** < window back ground color > */
            Vec4f WindowBg = { 0.2f, 0.205f, 0.21f, 1.0f };

            /** < head color normal > */
            Vec4f Header = { 0.2f, 0.205f, 0.21f, 1.0f };

            /** < head color hovered > */
            Vec4f HeaderHovered = { 0.3f, 0.305f, 0.31f, 1.0f };

            /** < head color active > */
            Vec4f HeaderActive = { 0.15f, 0.1505f, 0.151f, 1.0f };

            /** < button color normal > */
            Vec4f Button = { 0.2f, 0.205f, 0.21f, 1.0f };

            /** < button color hovered > */
            Vec4f ButtonHovered = { 0.3f, 0.305f, 0.31f, 1.0f };

            /** < button color active > */
            Vec4f ButtonActive = { 0.15f, 0.1505f, 0.151f, 1.0f };

            /** < frame back ground color normal > */
            Vec4f FrameBg = { 0.2f, 0.205f, 0.21f, 1.0f };

            /** < frame back ground color hovered > */
            Vec4f FrameBgHovered = { 0.3f, 0.305f, 0.31f, 1.0f };

            /** < frame back ground color active > */
            Vec4f FrameBgActive = { 0.15f, 0.1505f, 0.151f, 1.0f };

            /** < tab color normal > */
            Vec4f Tab = { 0.15f, 0.1505f, 0.151f, 1.0f };

            /** < tab color hovered > */
            Vec4f TabHovered = { 0.38f, 0.3805f, 0.381f, 1.0f };

            /** < tab color active > */
            Vec4f TabActive = { 0.28f, 0.2805f, 0.281f, 1.0f };

            /** < tab color unfocused > */
            Vec4f TabUnfocused = { 0.15f, 0.1505f, 0.151f, 1.0f };

            /** < tab color unfocused active > */
            Vec4f TabUnfocusedActive = { 0.2f, 0.205f, 0.21f, 1.0f };

            /** < title back ground color > */
            Vec4f TitleBg = { 0.15f, 0.1505f, 0.151f, 1.0f };

            /** < title back ground active > */
            Vec4f TitleBgActive = { 0.15f, 0.1505f, 0.151f, 1.0f };

            /** < title back ground collapsed > */
            Vec4f TitleBgCollapsed = { 0.15f, 0.1505f, 0.151f, 1.0f };

        } m_Colors;
        struct Fonts
        {
            /** < file path of font > */
            std::string FontPath = FileServer::resourcesPathRoot() + "\\fonts\\OpenSans-Semibold.ttf";

            /** < file path of default font > */
            std::string DefaultFontPath = FileServer::resourcesPathRoot() + "\\fonts\\Karla-Regular.ttf";

            /** < size of font > */
            float FontSize = 30.f;
        } m_Fonts;
    };

    /**
     * @brief  this class defines gui layer
     */
    class EB_GUI_EXPORT GuiLayer : public Layer
    {
    public:
        /**
         * @brief  constructor for gui layer.
         * @param[in]  window  pointer to window.
         */
        GuiLayer(const Shared<Window>& window);

        /**
         * @brief  destructor for gui layer.
         */
        ~GuiLayer() override = default;

    public:
        /**
         * @brief  handle layer attach.
         */
        void onAttach() override;
        
        /**
         * @brief  handle layer detach.
         */
        void onDetach() override;
        
        /**
         * @brief  handle layer update.
         * @param[in]  ts   real time spent.
         */
        void onUpdate(const TimeStep & ts) override;
        
        /**
         * @brief   handle ui render.
         */
        void onGuiRender() override;
        
        /**
         * @brief   handle event.
         * @param[in]   e   event.
         */
        void onEvent(Event & e) override;

    public:
        /**
         * @brief   begin gui render with this window.
         */
        void begin();

        /**
         * @brief   end gui render in this window.
         */
        void end();

        /**
         * @brief   set gui layer theme.
         * @param[in]   theme     theme properties.
         */
        static void setTheme(const GuiTheme& theme = GuiTheme());

    private:
        /** < pointer to related window > */
        Shared<Window> m_Window;
    };
}