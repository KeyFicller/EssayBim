#include "essaybim_redo_cmd.h"

#include "editor_base.h"
#include "command_undo_manager.h"

namespace EB
{

    RedoCmd::RedoCmd()
    {
        
    }

    RedoCmd::~RedoCmd()
    {
        
    }

    void RedoCmd::beginInvoke()
    {
        CommandBase::beginInvoke();
        UndoManager::instance().redo();
    }

    EditorBase* RedoCmd::editor()
    {
        return nullptr;
    }

    CommandAttribute RedoCmd::attribute()
    {
        return { "Redo", CommandAttribute::CommandType::kRedo };
    }

    bool RedoCmd::isRunnable() const
    {
        return UndoManager::instance().commandsInRedoStack().size();
    }

}