#include "essaybim_undo_cmd.h"

#include "editor_base.h"
#include "command_undo_manager.h"

namespace EB
{
    UndoCmd::UndoCmd()
    {

    }

    UndoCmd::~UndoCmd()
    {
        
    }

    void UndoCmd::beginInvoke()
    {
        CommandBase::beginInvoke();
        UndoManager::instance().undo();
    }

    EditorBase* UndoCmd::editor()
    {
        return nullptr;
    }

    CommandAttribute UndoCmd::attribute()
    {
        return { "Undo", CommandAttribute::CommandType::kUndo };
    }

    bool UndoCmd::isRunnable(Layer* /*pLayer*/) const
    {
        return UndoManager::instance().commandsInUndoStack().size();
    }

}