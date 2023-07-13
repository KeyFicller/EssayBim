#pragma once

#include "database_object.h"

namespace EB
{
    class DbObjectImpl
    {
    public:
        DbObjectImpl(DbObject* pFacade);
        virtual ~DbObjectImpl();

    public:
        Handle handle();
        bool open();
        bool close();
        void subClose();
        DbFiler* filer() const;
        void assertWriteEnabled();
        void setHandle(Handle hdl);
        DbDatabase* owner() const;
        void setOwner(DbDatabase* pDb);

    public:
        virtual void onRender() const;
        virtual DbObject* clone() const;
        virtual void serialize(Filer* pFiler) const;
        virtual void deSerialize(Filer* pFiler);
        void subYamlIn(const std::string& key);
        void subYamlOut(const std::string& key) const;

    protected:
        DbObject* m_pFacade = nullptr;
        DbDatabase* m_pDatabase = nullptr;
        Handle m_Handle = Handle::kNull;
        bool m_IsOpened = false;
        DbFiler* m_pFiler = nullptr;
    };
}