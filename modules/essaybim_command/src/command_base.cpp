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
        if (editor()) {
            editor()->init();
        }
    }

    bool CommandBase::onInvoke()
    {
        return editor() ? editor()->status() == EditorBase::EditorStatus::kInterating : false;
    }

    CommandBase::InvokeResult CommandBase::endInvoke()
    {
        InvokeResult res = InvokeResult::kNormal;
        if (editor()) {
            res = editor()->status() == EditorBase::EditorStatus::kCanceled ? InvokeResult::kCancel : res;
        }
        if (res == InvokeResult::kNormal) {
            UndoManager::instance().afterCommand();
        }
        return res;
    }

    bool CommandBase::isRunnable(Layer* /*pLayer*/) const
    {
        return true;
    }

}