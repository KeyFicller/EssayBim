#pragma once

#include "database_export.h"

#include "basic_impl_template.h"
#include "basic_handle.h"
#include "basic_yaml_base.h"

namespace EB
{
    class DbObject;
    class DbDatabaseImpl;

    /**
     * @brief   this class defines database base class.
     */
    class EB_DATABASE_EXPORT DbDatabase : public YamlBase
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(DbDatabase)
    public:
        /**
         * @brief  constructor for database.
         */
        DbDatabase();

        /**
         * @brief  constructor for database.
         * @param[in]   impl    implement of derived class.
         */
        DbDatabase(DbDatabaseImpl& impl);

        /**
         * @brief  destructor for database.
         */
        virtual ~DbDatabase();

    public:
        /**
         * @brief  add an object to this database.
         * @param[in]   pDbObj      pointer to new object.
         * @param[out]  hdl         allocated index.
         */
        void add(DbObject* pDbObj, Handle& hdl);

        /**
         * @brief  add an object to this database with it's original hdl.
         * @param[in]  pDbObj      pointer tot new object.
         * @param[in]  hdl         handle allocated on object added before.
         */
        void reAdd(DbObject* pDbObj, const Handle& hdl);

        /**
         * @brief   remove an object from database.
         * @param[in]  hdl         handle of removed object.
         */
        void remove(const Handle& hdl);

        /**
         * @brief   get all persistent objects handles in this database.
         * @return    handles.
         */
        std::vector<Handle> allObjects() const;

    protected:
        /**
         * @brief   interface for override import class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlIn(const std::string& key) override final;

        /**
         * @brief   interface for override export class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlOut(const std::string& key) override final;

    public:
        /**
         * @brief  extra logic on object added for derived classes.
         * @param[in]    pDbObject    object to add.
         */
        virtual void onDbObjectAdded(DbObject* pDbObj) = 0;

        /**
         * @brief  extra logic on object removed for derived classes.
         * @param[in]    pDbObject    object to remove.
         */
        virtual void onDbObjectRemoved(DbObject* pDbObj) = 0;
    };
}