#pragma once

#include "command_base.h"

namespace EB
{
    class CreateLine2dCmd : public CommandBase
    {
    public:
        CreateLine2dCmd();
        ~CreateLine2dCmd() override;

    public:
        virtual EditorBase& editor();

    protected:
        EditorBase* m_pEditor = nullptr;
    };
}