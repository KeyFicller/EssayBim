#pragma once

#include "command_base.h"

namespace EB
{
    class LoadCmd : public CommandBase
    {
    public:
        LoadCmd();
        ~LoadCmd() override;

    public:
        void beginInvoke() override;
        EditorBase* editor() override;
        CommandAttribute attribute() override;
    };
}