#include "command_undo_controller.h"

#include "command_undo_controller_impl.h"

namespace EB
{

    UndoController::UndoController()
    {
        EB_IMPL() = createScoped<UndoControllerImpl>(this);
    }

    UndoController::~UndoController()
    {
        EB_IMPL().reset();
    }

    void UndoController::rollbackFiler(Filer* pFiler)
    {
        EB_IMPL()->rollbackFiler(pFiler);
    }

    void UndoController::rollbackObject(void* pObject, Filer* pFiler)
    {
        EB_IMPL()->rollbackObject(pObject, pFiler);
    }

    void UndoController::rollbackOperation(void* pObject, int opCode, Filer* pFiler)
    {
        EB_IMPL()->rollbackOperation(pObject, opCode, pFiler);
    }

    void UndoController::recallFiler(Filer* pFiler)
    {
        EB_IMPL()->recallFiler(pFiler);
    }

}