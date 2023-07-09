#pragma once

#include "database_database.h"

namespace EB
{
    class EB_DATABASE_EXPORT DbGeometryDatabase : public DbDatabase
    {
    public:
        DbGeometryDatabase();
        ~DbGeometryDatabase() override;

    public:
        void onDbObjectAdded(DbObject* pDbObj) override;
        void onDbObjectRemoved(DbObject* pDbObj) override;
    };
}