#include "database_database_impl.h"

#include "database_object.h"

namespace EB
{

    DbDatabaseImpl::DbDatabaseImpl(DbDatabase* pFacade)
        : m_pFacade(pFacade)
    {

    }

    DbDatabaseImpl::~DbDatabaseImpl()
    {

    }

    void DbDatabaseImpl::add(DbObject* pDbObj, Handle& hdl)
    {
        if (pDbObj->handle()) {
            EB_CORE_ASSERT(false, "Object already in database.");
        }
        hdl = Handle::create(pDbObj);
        pDbObj->setOwner(m_pFacade);
        pDbObj->setHandle(hdl);
        m_pFacade->onDbObjectAdded(pDbObj);
        pDbObj->close();
        m_Handles.emplace_back(hdl);
    }

    void DbDatabaseImpl::remove(const Handle& hdl)
    {
        auto iter = std::find(m_Handles.begin(), m_Handles.end(), hdl);
        EB_CORE_ASSERT(iter != m_Handles.end());
        m_Handles.erase(iter);
        m_pFacade->onDbObjectRemoved(Handle::access<DbObject>(hdl));
        Handle::free<DbObject>(hdl);
    }

    std::vector<Handle> DbDatabaseImpl::allObjects() const
    {
        return m_Handles;
    }

}