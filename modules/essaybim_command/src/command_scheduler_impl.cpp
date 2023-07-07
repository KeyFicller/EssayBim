#include "command_scheduler_impl.h"

namespace EB
{

    CommandSchedulerImpl::CommandSchedulerImpl()
    {

    }

    CommandSchedulerImpl::~CommandSchedulerImpl()
    {

    }

    void CommandSchedulerImpl::registerCommand(const std::string& commandKey, const CommandScheduler::CreateCommandFunc& func)
    {
        m_CommandLib[commandKey] = func;
    }

    void CommandSchedulerImpl::unregisterCommand(const std::string& commandKey)
    {
        m_CommandLib.erase(commandKey);
    }

    bool CommandSchedulerImpl::hasCommandToExecute()
    {
        return m_CommandQueue.size();
    }

    void CommandSchedulerImpl::enqueueCommand(const std::string& commandKey)
    {
        EB_CORE_ASSERT(m_CommandLib.find(commandKey) != m_CommandLib.end());
        m_CommandQueue.push(commandKey);
    }

    CommandBase* CommandSchedulerImpl::popCommand()
    {
        if (!hasCommandToExecute()) {
            return nullptr;
        }
        auto cmdKey = m_CommandQueue.front();
        m_CommandQueue.pop();
        return m_CommandLib[cmdKey]();
    }

}