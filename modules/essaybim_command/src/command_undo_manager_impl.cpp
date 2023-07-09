#include "command_undo_manager_impl.h"

#include "command_undo_controller.h"

namespace EB
{

    UndoManagerImpl::UndoManagerImpl()
        : m_UndoStream(new Stream), m_RedoStream(new Stream)
    {
        m_RecordStream = m_UndoStream;
        m_RollbackStream = nullptr;
        m_PushInStack = &m_UndoStack;
        m_PopOutStack = nullptr;
    }

    UndoManagerImpl::~UndoManagerImpl()
    {
        EB_SAFE_DELETE(m_UndoStream);
        EB_SAFE_DELETE(m_RedoStream);
    }


    void UndoManagerImpl::undo()
    {
        auto cmdInfo = m_UndoStack.back();
        m_UndoStack.pop_back();
        rollbackTo(cmdInfo.Begin);
    }

    void UndoManagerImpl::redo()
    {
        auto cmdInfo = m_RedoStack.back();
        m_RedoStack.pop_back();
        rollbackTo(cmdInfo.Begin);
    }

    Stream* UndoManagerImpl::currentRecordStream() const
    {
        return m_RecordStream;
    }

    Stream* UndoManagerImpl::currentRollbackStream() const
    {
        return m_RollbackStream;
    }

    std::vector<std::string> UndoManagerImpl::commandsInUndoStack() const
    {
        std::vector<std::string> res;
        for (auto& cmd : m_UndoStack) {
            res.emplace_back(cmd.CommandName);
        }
        return res;
    }

    std::vector<std::string> UndoManagerImpl::commandsInRedoStack() const
    {
        std::vector<std::string> res;
        for (auto& cmd : m_RedoStack) {
            res.emplace_back(cmd.CommandName);
        }
        return res;
    }

    void UndoManagerImpl::addController(UndoController* pController)
    {
        if (m_CtrllerToIndex.find(pController) == m_CtrllerToIndex.end()) {
            int index = (int)m_CtrllerToIndex.size();
            m_CtrllerToIndex[pController] = index;
            m_IndexToCtrller[index] = pController;
        }
    }

    void UndoManagerImpl::beforeCommand(const CommandAttribute& attribute)
    {
        std::string cmdName;
        if (attribute.Type == CommandAttribute::CommandType::kNormal) {
            m_PushInStack = &m_UndoStack;
            m_PopOutStack = nullptr;
            m_RecordStream = m_UndoStream;
            m_RollbackStream = nullptr;
            cmdName = attribute.CommandName;
            cleanUpRedo();
        }
        else if (attribute.Type == CommandAttribute::CommandType::kUndo) {
            m_PushInStack = &m_RedoStack;
            m_PopOutStack = nullptr;
            m_RecordStream = m_RedoStream;
            m_RollbackStream = m_UndoStream;
            cmdName = m_UndoStack.back().CommandName;
        }
        else if (attribute.Type == CommandAttribute::CommandType::kRedo) {
            m_PushInStack = &m_UndoStack;
            m_PopOutStack = nullptr;
            m_RecordStream = m_UndoStream;
            m_RollbackStream = m_RedoStream;
            cmdName = m_RedoStack.back().CommandName;
        }

        m_PushInStack->emplace_back(CommandInfo{ cmdName, m_RecordStream->position(), -1 });
    }

    void UndoManagerImpl::afterCommand()
    {
        m_PushInStack->back().End = m_RecordStream->position();
    }

    void UndoManagerImpl::rollbackTo(int position)
    {
        while (m_RollbackStream->position() > position) {
            int curPosition = m_RollbackStream->position();
            m_RollbackStream->seek(curPosition - sizeof(int));
            int readLengthPosition = m_RollbackStream->position();
            int dataLength = m_RollbackStream->readLength();
            int readIndexPosition = readLengthPosition - dataLength - sizeof(int);
            m_RollbackStream->seek(readIndexPosition);
            int index = m_RollbackStream->readIndex();
            Filer filer;
            m_RollbackStream->offer(&filer, dataLength);
            dispatch(index, &filer);
            m_RollbackStream->seek(readIndexPosition);
        }
    }

    void UndoManagerImpl::dispatch(int ctrllerIndex, Filer* filer)
    {
        m_IndexToCtrller[ctrllerIndex]->rollbackFiler(filer);
    }

    void UndoManagerImpl::recallFrom(UndoController* pCtrller, Filer* filer)
    {
        m_RecordStream->writeIndex(m_CtrllerToIndex[pCtrller]);
        int pos1 = m_RecordStream->position();
        m_RecordStream->accept(filer);
        int pos2 = m_RecordStream->position();
        m_RecordStream->writeLength(pos2 - pos1);
    }

    void UndoManagerImpl::cleanUpRedo()
    {
        m_RedoStack.clear();
        m_RedoStream->clear();
    }

}