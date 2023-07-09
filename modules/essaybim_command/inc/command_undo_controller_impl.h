#pragma once

#include "command_undo_controller.h"

namespace EB
{
    class UndoControllerImpl final
    {
    public:
        UndoControllerImpl(UndoController* pFacade);
        ~UndoControllerImpl();

    public:
        void rollbackFiler(Filer* pFiler);
        void rollbackObject(void* pObject, Filer* pFiler);
        void rollbackOperation(void* pObject, int opCode, Filer* pFiler);
        void recallFiler(Filer* pFiler);

    protected:
        UndoController* m_pFacade = nullptr;
    };
}