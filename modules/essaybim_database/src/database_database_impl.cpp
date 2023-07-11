#include "database_database_impl.h"

#include "database_object.h"

namespace EB
{

    EB_YAML_DECLARE_KEYS(Objects);

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
        m_Handles.emplace_back(hdl);
    }

    void DbDatabaseImpl::reAdd(DbObject* pDbObj, const Handle& hdl)
    {
        EB_CORE_ASSERT(!pDbObj->handle());
        pDbObj->setOwner(m_pFacade);
        pDbObj->setHandle(hdl);
        m_pFacade->onDbObjectAdded(pDbObj);
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

    void DbDatabaseImpl::subYamlIn(const std::string& key)
    {
        _clear();

        // TODO:   need to add a class identifier.
        //EB_YAML_IN_SEQ(s_Key.Objects, [&]() {
        //    
        //});
    }

    void DbDatabaseImpl::subYamlOut(const std::string& key)
    {

    }

    void DbDatabaseImpl::_clear()
    {
        for (auto hdl : m_Handles) {
            delete Handle::access<DbObject>(hdl);
        }
        m_Handles.clear();
    }

}