#include "command_scheduler.h"

#include "command_scheduler_impl.h"

namespace EB
{

    CommandScheduler::CommandScheduler()
    {
        EB_IMPL() = createScoped<CommandSchedulerImpl>();
    }

    CommandScheduler::~CommandScheduler()
    {
        EB_IMPL().reset();
    }

    CommandScheduler& CommandScheduler::instance()
    {
        static CommandScheduler scheduler;
        return scheduler;
    }

    void CommandScheduler::registerCommand(const std::string& commandKey, const CreateCommandFunc& func)
    {
        EB_IMPL()->registerCommand(commandKey, func);
    }

    void CommandScheduler::unregisterCommand(const std::string& commandKey)
    {
        EB_IMPL()->unregisterCommand(commandKey);
    }

    bool CommandScheduler::hasCommandToExecute()
    {
        return EB_IMPL()->hasCommandToExecute();
    }

    void CommandScheduler::enqueueCommand(const std::string& commandKey)
    {
        EB_IMPL()->enqueueCommand(commandKey);
    }

    CommandBase* CommandScheduler::popCommand()
    {
        return EB_IMPL()->popCommand();
    }

}