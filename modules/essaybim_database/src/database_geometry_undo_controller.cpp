#include "database_geometry_undo_controller.h"

#include "database_database.h"
#include "database_geometry_object.h"
#include "database_geometry_database.h"

namespace EB
{

    namespace
    {
        void undo_on_object_added(void* /*pObject*/, Filer* pFiler)
        {
            Handle hdl = Handle(pFiler->readInt());
            DbGeometry* pDbGeom = Handle::access<DbGeometry>(hdl);
            DbDatabase* pDb = pDbGeom->owner();
            pDb->remove(hdl);
        }

        void undo_on_object_deleted(void* /*pObject*/, Filer* pFiler)
        {
            DbDatabase* pDbGe = static_cast<DbDatabase*>(pFiler->readPointer());
            Handle hdl = Handle(pFiler->readInt());
            DbGeometry* pDbGeom = new DbGeometry();
            pDbGeom->deSerialize(pFiler);
            hdl.resurrect(pDbGeom);
            pDbGe->reAdd(pDbGeom, hdl);
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