#pragma once

#include "command_base.h"

namespace EB
{
    class CreateCircle2dCmd : public CommandBase
    {
    public:
        CreateCircle2dCmd();
        ~CreateCircle2dCmd() override;

    public:
        EditorBase* editor() override;
        CommandAttribute attribute() override;

    protected:
        EditorBase* m_pEditor = nullptr;
    };
}