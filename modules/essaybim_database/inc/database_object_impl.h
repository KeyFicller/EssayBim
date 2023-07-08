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
        Filer* filer() const;
        void assertWriteEnabled();
        void setHandle(Handle hdl);

    public:
        virtual void onRender() const;
        virtual DbObject* clone() const;
        virtual void serialize(Filer* pFiler) const;
        virtual void deSerialize(Filer* pFiler);

    protected:
        DbObject* m_pFacade = nullptr;
        Handle m_Handle = Handle::Null;
        bool m_IsOpened = false;
        Filer* m_Filer = nullptr;
    };
}