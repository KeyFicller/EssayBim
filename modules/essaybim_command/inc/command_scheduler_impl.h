#pragma once

#include "command_scheduler.h"

#include "basic_library.h"

#include <queue>

namespace EB
{
    class CommandSchedulerImpl
    {
    public:
        CommandSchedulerImpl();
        ~CommandSchedulerImpl();

    public:
        void registerCommand(const std::string& commandKey, const CommandScheduler::CreateCommandFunc& func);
        void unregisterCommand(const std::string& commandKey);

        bool hasCommandToExecute();
        void enqueueCommand(const std::string& commandKey);
        CommandBase* popCommand();

    protected:
        std::queue<std::string> m_CommandQueue;
        std::map<std::string, CommandScheduler::CreateCommandFunc> m_CommandLib;
    };
}