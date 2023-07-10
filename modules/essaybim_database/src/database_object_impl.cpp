#include "database_object_impl.h"

namespace EB
{

    DbObjectImpl::DbObjectImpl(DbObject* pFacade)
        : m_pFacade(pFacade), m_IsOpened(false)
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
        m_pFiler = new DbFiler(m_pFacade);
        return true;
    }

    bool DbObjectImpl::close()
    {
        if (!m_IsOpened) {
            return false;
        }
        // commit filer data.
        m_pFiler->pushSessionLength();
        if (m_pFiler->position() > sizeof(void*)) {
            // m_pFiler->writeInt(m_pFiler->position() - sizeof(void*));
            m_pFacade->subClose();
        }
        m_IsOpened = false;
        EB_SAFE_DELETE(m_pFiler);
        return true;
    }

    void DbObjectImpl::subClose()
    {

    }

    DbFiler* DbObjectImpl::filer() const
    {
        return m_pFiler;
    }

    void DbObjectImpl::assertWriteEnabled()
    {
        if (!m_IsOpened) {
            __debugbreak();
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