#pragma once

#include "command_base.h"
#include "command_export.h"

#include "basic_impl_template.h"

#include <functional>
#include <string>

namespace EB
{
    /**
     * @brief   this class defines command scheduler.
     */
    class EB_COMMAND_EXPORT CommandScheduler final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(CommandScheduler)
    public:
        using CreateCommandFunc = std::function<CommandBase* ()>;
    protected:
        /**
         * @brief   constructor for command scheduler.
         */
        CommandScheduler();

        /**
         * @brief   destructor for command scheduler.
         */
        ~CommandScheduler();

    public:
        /**
         * @brief   get global instance of command scheduler.
         * @return     global instance of command scheduler.
         */
        static CommandScheduler& instance();

    public:
        /**
         * @brief   register a command factory to command scheduler.
         * @param[in]   commandKey      key of command.
         * @param[in]   func            create command function.
         */
        void registerCommand(const std::string& commandKey, const CreateCommandFunc& func);

        /**
         * @brief   unregister a command factory to command scheduler.
         * @param[in]   commandKey      key of command.
         */
        void unregisterCommand(const std::string& commandKey);

        /**
         * @brief  whether there is a command to execute in command scheduler.
         * @return    whether has command in scheduler.
         */
        bool hasCommandToExecute();

        /**
         * @brief  enqueue a command waiting to execute.
         * @return    commandKey      key of command.
         */
        void enqueueCommand(const std::string& commandKey);

        /**
         * @brief   pop a command from command scheduler, return nullptr for no command to pop.
         * @return    command popped.
         */
        CommandBase* popCommand();
    };
}