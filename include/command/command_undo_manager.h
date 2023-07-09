#pragma once

#include "command_export.h"
#include "command_base.h"

#include "basic_impl_template.h"

namespace EB
{
    class UndoController;

    /**
     * @brief  this class defines global undo manager class.
     */
    class EB_COMMAND_EXPORT UndoManager final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(UndoManager)
    protected:
        /**
         * @brief  constructor for undo manager.
         */
        UndoManager();

        /**
         * @brief   destructor for undo manager.
         */
        ~UndoManager();

    public:
        /**
         * @brief   get global instance of undo manager.
         */
        static UndoManager& instance();

    public:
        /**
         * @brief   operation before command.
         * @param[in]   attribute    command extension information.
         */
        void beforeCommand(const CommandAttribute& attribute);

        /**
         * @brief   operation after command.
         */
        void afterCommand();

        /**
         * @brief   undo a command.
         */
        void undo();

        /**
         * @brief   redo a command.
         */
        void redo();

        /**
         * @brief   add a undo controller to undo manager.
         * @param[in]  pController    point to persistent controller.
         */
        void addController(UndoController* pController);

        /**
         * @brief   get commit undo data from controller.
         * @param[in]  pController     controller that commit undo data.
         * @param[in]  pFiler          committed undo data.
         */
        void recallFrom(UndoController* pController, Filer* pFiler);

        /**
         * @brief   get undo command name list.
         * @return     name list of undo commands.
         */
        std::vector<std::string> commandsInUndoStack() const;

        /**
         * @brief   get redo command name list.
         * @return     name list of redo commands.
         */
        std::vector<std::string> commandsInRedoStack() const;
    };
}