#include "database_object.h"

#include "database_object_impl.h"

namespace EB
{

    DbObject::DbObject()
    {
        EB_IMPL() = createScoped<DbObjectImpl>(this);
    }

    DbObject::DbObject(DbObjectImpl& impl)
    {
        EB_IMPL() = Scoped<DbObjectImpl>(&impl);
    }

    DbObject::~DbObject()
    {
        EB_IMPL().reset();
    }

    Handle DbObject::handle() const
    {
        return EB_IMPL()->handle();
    }

    bool DbObject::open()
    {
        return EB_IMPL()->open();
    }

    bool DbObject::close()
    {
        return EB_IMPL()->close();
    }

    Filer* DbObject::filer() const
    {
        EB_DB_CHECK_WRITE_ENABLED();
        return EB_IMPL()->filer();
    }

    DbDatabase* DbObject::owner() const
    {
        EB_DB_CHECK_WRITE_ENABLED();
        return EB_IMPL()->owner();
    }

    void DbObject::assertWriteEnabled() const
    {
        EB_IMPL()->assertWriteEnabled();
    }

    void DbObject::setHandle(Handle hdl)
    {
        EB_IMPL()->setHandle(hdl);
    }

    void DbObject::setOwner(DbDatabase* pDb)
    {
        EB_DB_CHECK_WRITE_ENABLED();
        EB_IMPL()->setOwner(pDb);
    }

    void DbObject::onRender() const
    {
        EB_DB_CHECK_WRITE_ENABLED();
        EB_IMPL()->onRender();
    }

    DbObject* DbObject::clone() const
    {
        EB_DB_CHECK_WRITE_ENABLED();
        return EB_IMPL()->clone();
    }

    void DbObject::serialize(Filer* pFiler) const
    {
        EB_DB_CHECK_WRITE_ENABLED();
        EB_IMPL()->serialize(pFiler);
    }

    void DbObject::deSerialize(Filer* pFiler)
    {
        EB_DB_CHECK_WRITE_ENABLED();
        EB_IMPL()->deSerialize(pFiler);
    }

}