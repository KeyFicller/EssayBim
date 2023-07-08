#include "database_object_impl.h"

namespace EB
{

    DbObjectImpl::DbObjectImpl(DbObject* pFacade)
        : m_pFacade(pFacade), m_IsOpened(true)
    {

    }

    DbObjectImpl::~DbObjectImpl()
    {

    }

    Handle DbObjectImpl::handle()
    {
        return m_Handle;
    }

    bool DbObjectImpl::open()
    {
        if (m_IsOpened) {
            return false;
        }
        m_IsOpened = true;
        m_Filer = new Filer();
        return true;
    }

    bool DbObjectImpl::close()
    {
        if (!m_IsOpened) {
            return false;
        }
        m_IsOpened = false;
        // commit filer data.
        EB_SAFE_DELETE(m_Filer);
        return true;
    }

    Filer* DbObjectImpl::filer() const
    {
        return m_Filer;
    }

    void DbObjectImpl::assertWriteEnabled()
    {
        if (!m_IsOpened) {
            // __debugbreak();
        }
    }

    void DbObjectImpl::setHandle(Handle hdl)
    {
        m_Handle = hdl;
    }

    DbDatabase* DbObjectImpl::owner() const
    {
        return m_pDatabase;
    }

    void DbObjectImpl::setOwner(DbDatabase* pDb)
    {
        m_pDatabase = pDb;
    }

    void DbObjectImpl::onRender() const
    {

    }

    DbObject* DbObjectImpl::clone() const
    {
        return nullptr;
    }

    void DbObjectImpl::serialize(Filer* pFiler) const
    {

    }

    void DbObjectImpl::deSerialize(Filer* pFiler)
    {

    }

}