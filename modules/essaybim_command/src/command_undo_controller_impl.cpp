#include "command_undo_controller_impl.h"

#include "command_undo_manager.h"

namespace EB
{
    UndoControllerImpl::UndoControllerImpl(UndoController* pFacade)
        : m_pFacade(pFacade)
    {

    }

    UndoControllerImpl::~UndoControllerImpl()
    {

    }

    void UndoControllerImpl::rollbackFiler(Filer* pFiler)
    {
        int endPos = pFiler->position();
        pFiler->seek(0);
        void* pObj = pFiler->readPointer();
        pFiler->seek(endPos);
        rollbackObject(pObj, pFiler);
    }

    void UndoControllerImpl::rollbackObject(void* pObject, Filer* pFiler)
    {
        while (pFiler->position() > sizeof(void*)) {
            int curPos = pFiler->position();
            int readLengthPos = curPos - sizeof(int);
            pFiler->seek(readLengthPos);
            int dataLength = pFiler->readInt();
            int readOpCodePos = readLengthPos - dataLength - sizeof(int);
            pFiler->seek(readOpCodePos);
            int opCode = pFiler->readInt();
            rollbackOperation(pObject, opCode, pFiler);
            pFiler->seek(readOpCodePos);
        }
    }

    void UndoControllerImpl::rollbackOperation(void* pObject, int opCode, Filer* pFiler)
    {
        auto funCbs = m_pFacade->rollbackFuncs();
        EB_CORE_ASSERT(funCbs.find(opCode) != funCbs.end());
        funCbs[opCode](pObject, pFiler);
    }

    void UndoControllerImpl::recallFiler(Filer* pFiler)
    {
        UndoManager::instance().recallFrom(m_pFacade, pFiler);
    }

}