#pragma once

#include "editor_base.h"

#include "geometry_line_2d.h"
#include "geometry_plane.h"
#include "event_mouse_event.h"
#include "event_mouse_button_event.h"

namespace EB
{
    class Line2dEditor : public EditorBase
    {
    public:
        Line2dEditor();
        ~Line2dEditor() override;

    public:
        EditorStatus status() override;
        void init() override;
        void handleInput(Event& e) override;
        void update() override;
        void updateDisplay() override;
        void confirm() override;
        void cancel() override;

        bool _handleMouseMove(MouseMovedEvent& e);
        bool _handleMouseClick(MouseButtonPressedEvent& e);

    protected:
        GePlane m_Plane;
        GeLine2d m_LineSeg;
        EditorStatus m_Status = EditorBase::EditorStatus::kInterating;
        int m_InteractIndex = 0;
    };
}