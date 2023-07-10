#include "command_base.h"

#include "command_undo_manager.h"

namespace EB
{

    CommandBase::CommandBase()
    {

    }

    CommandBase::~CommandBase()
    {

    }

    void CommandBase::beginInvoke()
    {
        UndoManager::instance().beforeCommand(attribute());
        editor().init();
    }

    CommandBase::InvokeResult CommandBase::invoke()
    {
        // TODO: redesign this part.
        return editor().status() == EditorBase::EditorStatus::kConfirmed ? InvokeResult::kNormal : InvokeResult::kCancel;
    }

    void CommandBase::endInvoke()
    {
        UndoManager::instance().afterCommand();
    }

    bool CommandBase::isRunnable() const
    {
        return true;
    }

}