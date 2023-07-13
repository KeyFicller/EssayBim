#pragma once

#include "command_base.h"

namespace EB
{
    class SaveCmd : public CommandBase
    {
    public:
        SaveCmd();
        ~SaveCmd() override;

    public:
        void beginInvoke() override;
        EditorBase* editor() override;
        CommandAttribute attribute() override;
    };
}