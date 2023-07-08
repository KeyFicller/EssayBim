#pragma once

#include "editor_base.h"

#include "geometry_circle_2d.h"
#include "geometry_plane.h"
#include "event_mouse_event.h"
#include "event_mouse_button_event.h"

namespace EB
{
    class Circle2dEditor : public EditorBase
    {
    public:
        Circle2dEditor();
        ~Circle2dEditor() override;

    public:
        EditorStatus status() override;
        void init() override;
        void handleInput(Event& e, const EventExtension& extension) override;
        void update() override;
        void updateDisplay() override;
        void confirm() override;
        void cancel() override;

        bool _handleMouseMove(MouseMovedEvent& e, const GeLine3d& rayLine);
        bool _handleMouseClick(MouseButtonPressedEvent& e, Handle handle);

    protected:
        GePlane m_Plane;
        GeCircle2d m_Circle;
        EditorStatus m_Status = EditorBase::EditorStatus::kInterating;
        int m_InteractIndex = 0;
    };
}