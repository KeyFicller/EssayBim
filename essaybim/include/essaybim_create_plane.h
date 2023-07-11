#pragma once

#include "command_base.h"

namespace EB
{
    class CreatePlaneCmd : public CommandBase
    {
    public:
        CreatePlaneCmd();
        ~CreatePlaneCmd() override;

    public:
        void beginInvoke() override;
        EditorBase* editor() override;
        CommandAttribute attribute() override;
    };
}