#include "database_geometry_undo_controller.h"

#include "database_database.h"
#include "database_geometry_object.h"

namespace EB
{

    namespace
    {
        void undo_on_object_added(void* pObject, Filer* pFiler)
        {
            DbGeometry* pDbGeom = static_cast<DbGeometry*>(pObject);
            DbDatabase* pDb = pDbGeom->owner();
            pDb->remove(pDbGeom->handle());
        }

        void undo_on_object_deleted(void* pObject, Filer* pFiler)
        {
            
        }
    }

    DbGeUndoController::DbGeUndoController()
    {

    }

    DbGeUndoController::~DbGeUndoController()
    {

    }

    DbGeUndoController& DbGeUndoController::instance()
    {
        static DbGeUndoController ctrller;
        return ctrller;
    }

    const std::map<int, UndoController::UndoFunc>& DbGeUndoController::rollbackFuncs() const
    {
        static const std::map<int, UndoController::UndoFunc> rbFuncs = {
            {(int)DbGeUndoOpCode::kObjectAdd, undo_on_object_added},
            {(int)DbGeUndoOpCode::kObjectDelete, undo_on_object_deleted}
        };

        return rbFuncs;
    }

}