#pragma once

#include "command_base.h"
#include "command_undo_manager.h"

#include "basic_stream.h"

#include <stack>
#include <map>

namespace EB
{
    struct CommandInfo
    {
        std::string CommandName;
        int Begin;
        int End;
    };

    class UndoController;

    class UndoManagerImpl
    {
    public:
        UndoManagerImpl();
        ~UndoManagerImpl();

    public:
        // entry interface
        void undo();
        void redo();

        // query interface
        Stream* currentRecordStream() const;
        Stream* currentRollbackStream() const;
        std::vector<std::string> commandsInUndoStack() const;
        std::vector<std::string> commandsInRedoStack() const;

        // operation interface
        void addController(UndoController* pController);
        void beforeCommand(const CommandAttribute& attribute);
        void afterCommand();
        void rollbackTo(int position);
        void recallFrom(UndoController* pCtrller, Filer* pFiler);

        void cleanUpRedo();

        void dispatch(int ctrllerIndex, Filer* filer);

    protected:
        std::vector<CommandInfo> m_UndoStack;
        std::vector<CommandInfo> m_RedoStack;
        std::vector<CommandInfo>* m_PushInStack = nullptr;
        std::vector<CommandInfo>* m_PopOutStack = nullptr;
        Stream* m_UndoStream = nullptr;
        Stream* m_RedoStream = nullptr;
        Stream* m_RecordStream = nullptr;
        Stream* m_RollbackStream = nullptr;
        std::map<int, UndoController*> m_IndexToCtrller;
        std::map<UndoController*, int> m_CtrllerToIndex;
    };
}