#pragma once

#include "database_export.h"
#include "database_filer.h"

#include "basic_handle.h"
#include "basic_impl_template.h"
#include "basic_yaml_base.h"

namespace EB
{
    class DbObjectImpl;
    class DbDatabase;

    /**
     * @brief  this class defines database object base class.
     */
    class EB_DATABASE_EXPORT DbObject : public YamlBase
    {
        friend class DbDatabase;
        friend class DbDatabaseImpl;
        EB_IMPL_DECLARATION_DISABLE_COPY(DbObject)
    public:
        /**
         * @brief  constructor for database object.
         */
        DbObject();

        /**
         * @brief   constructor for database object.
         * @param[in]   impl     implement class for derived class.
         */
        DbObject(DbObjectImpl& impl);

        /**
         * @brief  destructor for data base object.
         */
        virtual ~DbObject();

    public:
        /**
         * @brief    get object handle.
         * <p>
         * if an object has no handle, means that it doesn't managed by database.
         * @return     object handle.
         */
        Handle handle() const;

        /**
         * @brief    open this object for modify.
         * <p>
         * you can only modify object when it's opened, for example call any non-const interfaces.
         * @return     if opened successfully.
         */
        bool open();

        /**
         * @brief    close modified object.
         * <p>
         * when an object has been modified, the modified data will be backup by undo.
         * @return     if closed successfully.
         */
        bool close();

        /**
         * @brief    get current recording filer.
         * <p>
         * filer is created when object is opened, any modified data will be record as binary stream to this filer.
         * @return     undo filer.
         */
        DbFiler* filer() const;

        /**
         * @breif   get owner database.
         * @return    owner database of this object.
         */
        DbDatabase* owner() const;

    protected:
        /**
         * @brief  ensure object is write opened.
         */
        void assertWriteEnabled() const;

        /**
         * @brief   set handle to object.
         * @return   handle allocated.
         */
        void setHandle(Handle hdl);

        /**
         * @brief   set owner database of object.
         * @param[in]   pDb   owner database.
         */
        void setOwner(DbDatabase* pDb);

    public:
        /**
         * @brief   extra work by derived class, like commit undo data.
         */
        virtual void subClose();

        /**
         * @brief   deal with db object render.
         */
        virtual void onRender() const;

        /**
         * @brief   clone a same object.
         * @return    new created object.
         */
        virtual DbObject* clone() const;

        /**
         * @brief   serialize this object to an filer.
         * @param[in]      pFiler       filer to accept binary data.
         */
        virtual void serialize(Filer* pFiler) const;

        /**
         * @brief   deSerialize this object from an filer.
         * @param[in]      pFiler       filer to give binary data.
         */
        virtual void deSerialize(Filer* pFiler);

        /**
         * @brief   interface for override import class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlIn(const std::string& key) override;

        /**
         * @brief   interface for override export class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlOut(const std::string& key) const override;
    };
}


#define EB_DB_CHECK_WRITE_ENABLED()                                                          \
    if (handle() && !std::is_const<std::remove_pointer<decltype(this)>::type>::value)        \
        assertWriteEnabled()
