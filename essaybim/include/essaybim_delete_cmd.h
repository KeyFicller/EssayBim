#pragma once

#include "command_base.h"

#include "basic_handle.h"

#include <vector>

namespace EB
{
    class DeleteCmd : public CommandBase
    {
    public:
        DeleteCmd();
        ~DeleteCmd() override;

    public:
        void beginInvoke() override;
        EditorBase* editor() override;
        CommandAttribute attribute() override;
        bool isRunnable(Layer* pLayer = nullptr) const override;
    };
}