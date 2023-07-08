#include "essaybim_create_line_2d_cmd.h"

#include "essaybim_line_2d_editor.h"

namespace EB
{

    CreateLine2dCmd::CreateLine2dCmd()
    {
        m_pEditor = new Line2dEditor();
    }

    CreateLine2dCmd::~CreateLine2dCmd()
    {
        EB_SAFE_DELETE(m_pEditor);
    }

    EditorBase& CreateLine2dCmd::editor()
    {
        return *m_pEditor;
    }

}