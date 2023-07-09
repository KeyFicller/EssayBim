#pragma once

#include "database_export.h"

#include "basic_filer.h"

namespace EB
{
    class DbObject;

    class EB_DATABASE_EXPORT DbFiler : public Filer
    {
    public:
        DbFiler(DbObject* pObj);
        ~DbFiler() override;

    public:
        void pushSessionLength();

    protected:
        int m_SessionStart = sizeof(void*);
    };
}