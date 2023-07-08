#include "essaybim_circle_2d_editor.h"
#include "essaybim_test_layer.h"

#include "event_event_dispatcher.h"
#include "database_database.h"
#include "database_geometry_object.h"
#include "event_mouse_button_defines.h"
#include "geometry_line_3d.h"
#include "geometry_circle_3d.h"
#include "geometry_arithmetic.h"
#include "geometry_matrix_3d.h"
#include "renderer_batch_render.h"
#include "essaybim_test_layer.h"
#include "geometry_utils.h"

namespace EB
{
#define BIND_EVENT_FN(x) std::bind(&Circle2dEditor::x, this, std::placeholders::_1, std::placeholders::_2)

    Circle2dEditor::Circle2dEditor()
    {

    }

    Circle2dEditor::~Circle2dEditor()
    {

    }

    EditorBase::EditorStatus Circle2dEditor::status()
    {
        return m_Status;
    }

    void Circle2dEditor::init()
    {
        m_Plane = GePlane();
    }

    void Circle2dEditor::handleInput(Event& e, const EventExtension& extension)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<MouseMovedEvent>(BIND_EVENT_FN(_handleMouseMove), extension.MouseRayLine);
        dispatcher.dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(_handleMouseClick), extension.EntityHandle);
    }

    void Circle2dEditor::update()
    {

    }

    void Circle2dEditor::updateDisplay()
    {
        if (m_InteractIndex == 0)
        {
            return;
        }
        GeCircle3d* circle = static_cast<GeCircle3d*>(m_Circle.create3D(m_Plane));
        auto pts = circle->sampler(0.02f);
        std::vector<Vec3f> vecPts;
        for (unsigned int i = 0; i < pts.size(); i++) {
            vecPts.emplace_back(pts[i]);
        }
        BatchRender::polyline(vecPts);
        EB_SAFE_DELETE(circle);
    }

    void Circle2dEditor::confirm()
    {
        DbGeometry* dbGeom = new DbGeometry;
        dbGeom->setGeometry(static_cast<GeCircle3d*>(m_Circle.create3D(m_Plane)));
        Handle hdl;
        TestLayer::currentDb().add(dbGeom, hdl);
    }

    void Circle2dEditor::cancel()
    {

    }

    bool Circle2dEditor::_handleMouseMove(MouseMovedEvent& e, const GeLine3d& rayLine)
    {
        if (m_InteractIndex == 0) {
            auto pt = m_Plane.planeToWorldMatrix().inverse() * GeIntersectUtils::intersect(rayLine, m_Plane);
            m_Circle.setCenter(GePoint2d(pt.x(), pt.y()));
        }
        else if (m_InteractIndex == 1) {
            auto pt = m_Plane.planeToWorldMatrix().inverse() * GeIntersectUtils::intersect(rayLine, m_Plane);
            auto other = GePoint2d(pt.x(), pt.y());
            m_Circle.setRadius(other.distanceTo(m_Circle.center()));
        }
        return false;
    }

    bool Circle2dEditor::_handleMouseClick(MouseButtonPressedEvent& e, Handle handle)
    {
        if (e.button() != MOUSE_BUTTON_LEFT)
        {
            return false;
        }
        if (m_InteractIndex == 0) {
            m_Circle.setRadius(0);
        }
        else if (m_InteractIndex == 1) {
            m_Status = EditorBase::EditorStatus::kConfirmed;
            confirm();
        }
        m_InteractIndex++;
        return false;
    }

}
