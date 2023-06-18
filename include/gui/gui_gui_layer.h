#pragma once

#include "window_window.h"
#include "window_layer.h"

namespace EB
{
    class EB_EXPORT GuiLayer : public Layer
    {
    public:
        GuiLayer(const std::string& name, const Shared<Window>& window);
        ~GuiLayer() override = default;
    public:
        void onAttach() override;
        void onDetach() override;
        void onUpdate(const TimeStep & ts) override;
        void onGuiRender() override;
        void onEvent(Event & e) override;

    public:
        void begin();
        void end();

    private:
        Shared<Window> m_Window;
    };
}