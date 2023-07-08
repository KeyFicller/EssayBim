#include "essaybim_line_2d_editor.h"

#include "essaybim_test_layer.h"

#include "basic_handle.h"
#include "event_event_dispatcher.h"
#include "event_mouse_button_defines.h"
#include "database_geometry_object.h"
#include "database_database.h"
#include "geometry_arithmetic.h"
#include "geometry_line_3d.h"
#include "geometry_matrix_3d.h"
#include "geometry_utils.h"
#include "renderer_batch_render.h"

namespace EB
{
#define BIND_EVENT_FN(x) std::bind(&Line2dEditor::x, this, std::placeholders::_1, std::placeholders::_2)

    Line2dEditor::Line2dEditor()
    {

    }

    Line2dEditor::~Line2dEditor()
    {

    }

    EditorBase::EditorStatus Line2dEditor::status()
    {
        return m_Status;
    }

    void Line2dEditor::init()
    {
        m_Plane = GePlane();
    }

    void Line2dEditor::handleInput(Event& e, const EventExtension& extension)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<MouseMovedEvent>(BIND_EVENT_FN(_handleMouseMove), extension.MouseRayLine);
        dispatcher.dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(_handleMouseClick), extension.EntityHandle);
    }

    void Line2dEditor::update()
    {

    }

    void Line2dEditor::updateDisplay()
    {
        if (m_InteractIndex == 0)
        {
            return;
        }
        GeLine3d* line3d = static_cast<GeLine3d*>(m_LineSeg.create3D(m_Plane));
        BatchRender::line(line3d->start(), line3d->end());
        EB_SAFE_DELETE(line3d);
    }

    void Line2dEditor::confirm()
    {
        DbGeometry* dbGeom = new DbGeometry;
        dbGeom->setGeometry(static_cast<GeLine3d*>(m_LineSeg.create3D(m_Plane)));
        Handle hdl;
        TestLayer::currentDb().add(dbGeom, hdl);
    }

    void Line2dEditor::cancel()
    {

    }

    bool Line2dEditor::_handleMouseMove(MouseMovedEvent& e, const GeLine3d& rayLine)
    {
        if (m_InteractIndex == 0) {
            auto pt = m_Plane.planeToWorldMatrix().inverse() * GeIntersectUtils::intersect(rayLine, m_Plane);
            m_LineSeg.setStart(GePoint2d(pt.x(), pt.y()));
        }
        else if (m_InteractIndex == 1) {
            auto pt = m_Plane.planeToWorldMatrix().inverse() * GeIntersectUtils::intersect(rayLine, m_Plane);
            m_LineSeg.setEnd(GePoint2d(pt.x(), pt.y()));
        }
        return false;
    }

    bool Line2dEditor::_handleMouseClick(MouseButtonPressedEvent& e, Handle handle)
    {
        if (e.button() != MOUSE_BUTTON_LEFT)
        {
            return false;
        }
        if (m_InteractIndex == 0) {
            m_LineSeg.setEnd(m_LineSeg.start());
        }
        else if (m_InteractIndex == 1) {
            m_Status = EditorBase::EditorStatus::kConfirmed;
            confirm();
        }
        m_InteractIndex++;
        return false;
    }

}
