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
        virtual EditorBase& editor();

    protected:
        EditorBase* m_pEditor = nullptr;
    };
}