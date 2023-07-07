#include "command_base.h"

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
        editor().init();
    }

    CommandBase::InvokeResult CommandBase::invoke()
    {
        // TODO: redesign this part.
        return editor().status() == EditorBase::EditorStatus::kConfirmed ? InvokeResult::kNormal : InvokeResult::kCancel;
    }

    void CommandBase::endInvoke()
    {
        
    }

}