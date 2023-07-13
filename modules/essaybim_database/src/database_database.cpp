#include "database_database.h"

#include "database_database_impl.h"

namespace EB
{
    
    DbDatabase::DbDatabase()
    {
        EB_IMPL() = createScoped<DbDatabaseImpl>(this);
    }

    DbDatabase::DbDatabase(DbDatabaseImpl& impl)
    {
        EB_IMPL() = Scoped<DbDatabaseImpl>(&impl);
    }

    DbDatabase::~DbDatabase()
    {
        EB_IMPL().reset();
    }

    void DbDatabase::add(DbObject* pDbObj, Handle& hdl)
    {
        EB_IMPL()->add(pDbObj, hdl);
    }

    void DbDatabase::reAdd(DbObject* pDbObj, const Handle& hdl)
    {
        EB_IMPL()->reAdd(pDbObj, hdl);
    }

    void DbDatabase::remove(const Handle& hdl)
    {
        EB_IMPL()->remove(hdl);
    }

    std::vector<Handle> DbDatabase::allObjects() const
    {
        return EB_IMPL()->allObjects();
    }

    void DbDatabase::subYamlIn(const std::string& key)
    {
        YamlBase::subYamlIn(key);
        return EB_IMPL()->subYamlIn(key);
    }

    void DbDatabase::subYamlOut(const std::string& key) const
    {
        YamlBase::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        return EB_IMPL()->subYamlOut(key);
    }

}