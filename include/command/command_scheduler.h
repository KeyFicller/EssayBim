#pragma once

#include "command_export.h"
#include "command_base.h"

#include "basic_impl_template.h"

#include <functional>
#include <string>

namespace EB
{
    class EB_COMMAND_EXPORT CommandScheduler final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(CommandScheduler)
    public:
        using CreateCommandFunc = std::function<CommandBase* ()>;
    protected:
        CommandScheduler();
        ~CommandScheduler();

    public:
        CommandScheduler& instance();

    public:
        void registerCommand(const std::string& commandKey, const CreateCommandFunc& func);
        void unregisterCommand(const std::string& commandKey);

        bool hasCommandToExecute();
        void enqueueCommand(const std::string& commandKey);
        CommandBase* popCommand();
    };
}