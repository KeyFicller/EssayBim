#pragma once

#include "command_base.h"

namespace EB
{
    class RedoCmd : public CommandBase
    {
    public:
        RedoCmd();
        ~RedoCmd() override;

    public:
        void beginInvoke() override;
        EditorBase* editor() override;
        CommandAttribute attribute() override;
        bool isRunnable(Layer* pLayer = nullptr) const override;
    };
}