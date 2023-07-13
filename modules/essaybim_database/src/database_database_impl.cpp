#include "database_database_impl.h"

#include "database_object.h"

#include "basic_object_creator.h"

namespace EB
{

    EB_YAML_DECLARE_KEYS(Classes, Handles, Objects);

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

        std::vector<std::string> classes;
        std::vector<int> handles;
        EB_YAML_IN(s_Key.Classes, classes);
        EB_YAML_IN(s_Key.Handles, handles);

        auto iter = classes.begin();
        std::vector<DbObject*> created;
        EB_YAML_IN_SEQ(s_Key.Objects, [&]() {
            created.push_back(ObjectCreator::create<DbObject>(*iter));
            iter++;
            return created.back();
        });

        for (unsigned int i = 0; i < created.size(); i++) {
            m_pFacade->reAdd(created[i], Handle(handles[i]));
        }
    }

    void DbDatabaseImpl::subYamlOut(const std::string& key)
    {
        std::vector<std::string> classes;
        std::vector<int> handles;
        for (auto& hdl : m_Handles) {
            classes.emplace_back(Handle::access<DbObject>(hdl)->className());
            handles.push_back((int)hdl);
        }
        EB_YAML_OUT(s_Key.Classes, classes);
        EB_YAML_OUT(s_Key.Handles, handles);

        auto iter = m_Handles.begin();
        EB_YAML_OUT_SEQ(s_Key.Objects, [&]() {
            YamlBase* pYamlObj = nullptr;
            if (iter != m_Handles.end()) {
                pYamlObj = Handle::access<DbObject>(*iter);
                iter++;
            }
            return pYamlObj;
        });
    }

    void DbDatabaseImpl::_clear()
    {
        for (auto hdl : m_Handles) {
            delete Handle::access<DbObject>(hdl);
        }
        m_Handles.clear();
    }

}