#include "database_geometry_database.h"

#include "database_object.h"
#include "database_database_impl.h"
#include "database_geometry_undo_controller.h"

namespace EB
{

    DbGeometryDatabase::DbGeometryDatabase()
        : DbDatabase()
    {

    }

    DbGeometryDatabase::~DbGeometryDatabase()
    {

    }

    void DbGeometryDatabase::onDbObjectAdded(DbObject* pDbObj)
    {
        pDbObj->open();
        pDbObj->filer()->writeInt(static_cast<int>(DbGeUndoOpCode::kObjectAdd));
        pDbObj->close();
    }

    void DbGeometryDatabase::onDbObjectRemoved(DbObject* pDbObj)
    {
        pDbObj->open();
        pDbObj->filer()->writeInt(static_cast<int>(DbGeUndoOpCode::kObjectDelete));
        pDbObj->filer()->writePointer(this);
        pDbObj->filer()->writeInt(pDbObj->handle());
        pDbObj->serialize(pDbObj->filer());
        pDbObj->close();
    }

}