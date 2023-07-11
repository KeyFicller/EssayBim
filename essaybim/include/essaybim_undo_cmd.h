#pragma once

#include "command_base.h"

namespace EB
{
    class UndoCmd : public CommandBase
    {
    public:
        UndoCmd();
        ~UndoCmd() override;

    public:
        void beginInvoke() override;
        EditorBase* editor() override;
        CommandAttribute attribute() override;
        bool isRunnable() const override;
    };
}