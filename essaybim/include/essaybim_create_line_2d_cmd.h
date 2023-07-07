#pragma once

#include "command_base.h"

namespace EB
{
    class CreateLine2dCmd : public CommandBase
    {
    public:
        CreateLine2dCmd() = default;
        ~CreateLine2dCmd() override = default;

    public:
        virtual EditorBase& editor();

    protected:

    };
}