#pragma once

#include "command_export.h"

#include "editor_base.h"

#include <string>

namespace EB
{
    /**
     * @brief  this class defines command type and name identify.
     */
    struct CommandAttribute
    {
        /**
         * @brief  this enum defines command type.
         */
        enum class CommandType
        {
            /** < normal command > */
            kNormal,

            /** < undo command > */
            kUndo,

            /** < redo command > */
            kRedo
        };

        /** < name of command > */
        std::string CommandName;

        /** < type of command > */
        CommandType Type;
    };

    class Layer;

    /**
     * @brief  this class defines command base.
     */
    class EB_COMMAND_EXPORT CommandBase
    {
    public:
        /**
         * @brief   this enum defines invoke result.
         */
        enum class InvokeResult
        {
            /** < command has executed successfully > */
            kNormal,

            /** < command failed or canceled > */
            kCancel
        };

    public:
        /**
         * @brief  constructor for command.
         */
        CommandBase();

        /**
         * @brief   destructor for command.
         */
        virtual ~CommandBase();

    public:
        /**
         * @brief  prepare environment and data for command execution.
         */
        virtual void beginInvoke();

        /**
         * @brief  command execution.
         */
        virtual bool onInvoke();

        /**
         * @brief   restore environment and clean up data after execution.
         */
        virtual InvokeResult endInvoke();

        /**
         * @brief   create editor for logic.
         */
        virtual EditorBase* editor() = 0;

        /**
         * @brief   get attribute of this command.
         * @return    attribute of command.
         */
        virtual CommandAttribute attribute() = 0;

        /**
         * @brief   is runnable.
         * @param[in]   pLayer      command execution environment.
         * @return    whether command is runnable.
         */
        virtual bool isRunnable(Layer* pLayer = nullptr) const;
    };
}