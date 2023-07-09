#include "essaybim_create_circle_2d_cmd.h"

#include "essaybim_circle_2d_editor.h"

namespace EB
{

    CreateCircle2dCmd::CreateCircle2dCmd()
    {
        m_pEditor = new Circle2dEditor();
    }

    CreateCircle2dCmd::~CreateCircle2dCmd()
    {
        EB_SAFE_DELETE(m_pEditor);
    }

    EditorBase& CreateCircle2dCmd::editor()
    {
        return *m_pEditor;
    }

    CommandAttribute CreateCircle2dCmd::attribute()
    {
        return { "Create Circle 2D" , CommandAttribute::CommandType::kNormal };
    }

}