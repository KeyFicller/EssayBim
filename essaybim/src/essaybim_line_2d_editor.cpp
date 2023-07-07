#include "essaybim_line_2d_editor.h"

#include "renderer_batch_render.h"
#include "geometry_line_3d.h"

namespace EB
{

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

    void Line2dEditor::handleInput(Event& e)
    {

    }

    void Line2dEditor::update()
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

    }

    void Line2dEditor::cancel()
    {

    }

    bool Line2dEditor::_handleMouseMove(MouseMovedEvent& e)
    {
        return false;
    }

    bool Line2dEditor::_handleMouseClick(MouseButtonEvent& e)
    {
        return false;
    }

}
