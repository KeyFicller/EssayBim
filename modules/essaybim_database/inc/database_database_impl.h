#pragma once

#include "database_database.h"

#include <set>

namespace EB
{
    class DbDatabaseImpl
    {
    public:
        DbDatabaseImpl(DbDatabase* pFacade);
        virtual ~DbDatabaseImpl();

    public:
        virtual void add(DbObject* pDbObj, Handle& hdl);
        virtual void reAdd(DbObject* pDbObj, const Handle& hdl);
        virtual void remove(const Handle& hdl);
        std::vector<Handle> allObjects() const;

    protected:
        DbDatabase* m_pFacade = nullptr;
        std::vector<Handle> m_Handles;
    };
}