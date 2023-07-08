#pragma once

#include "database_export.h"

#include "basic_impl_template.h"
#include "basic_handle.h"
#include "basic_yaml_base.h"

namespace EB
{
    class DbObject;
    class DbDatabaseImpl;

    class EB_DATABASE_EXPORT DbDatabase : public YamlBase
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(DbDatabase)
    public:
        DbDatabase();
        DbDatabase(DbDatabaseImpl& impl);
        virtual ~DbDatabase();

    public:
        virtual void add(DbObject* pDbObj, Handle& hdl);
        virtual void remove(const Handle& hdl);
        std::vector<Handle> allObjects() const;

    public:
        virtual void onDbObjectAdded() {}
        virtual void onDbObjectRemoved() {}
    };
}