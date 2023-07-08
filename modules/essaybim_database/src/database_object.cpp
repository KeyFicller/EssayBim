#include "database_object.h"

#include "database_object_impl.h"

namespace EB
{

    DbObject::DbObject()
    {
        EB_IMPL() = createScoped<DbObjectImpl>();
    }

    DbObject::~DbObject()
    {
        EB_IMPL().reset();
    }

    Handle DbObject::handle() const
    {
        EB_DB_CHECK_WRITE_ENABLED();
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

    void DbObject::assertWriteEnabled() const
    {
        EB_IMPL()->assertWriteEnabled();
    }

    void DbObject::setHandle(Handle hdl)
    {
        EB_IMPL()->setHandle(hdl);
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