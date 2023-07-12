#pragma once

#include "basic_export.h"

#include <string>
#include <map>
#include <functional>

namespace EB
{
    /**
     * @brief  this class is used for uniform registration.
     */
    template <typename T>
    class ObjectCreatorRegister
    {
    public:
        ObjectCreatorRegister() = delete;
    };

    /**
     * @brief  this class provides ability to construct a default object with class name string.
     * <p>
     * You have to known the base type of created object, eg. _class* ptr = ObjectCreator::create(xxx);
     * You can define a base class for all objects that can be created, but for now this class is only
     * designed for save and load.
     */
    class EB_BASIC_EXPORT ObjectCreator
    {
        template <typename T>
        friend class ObjectCreatorRegister;
    public:
        using createFunc = std::function<void* ()>;
    public:
        /**
         * @brief   create an object with class name.
         * <p>
         * Either specify template type or give pointer type to make compile successful.
         * @param[in]    className      stored class name.
         * @return   pointer to created object.
         */
        template <typename T>
        static T* create(const std::string& className) {
            return reinterpret_cast<T*>(m_CreateFuncs[className]);
        }

    protected:
        /**
         * @brief   register an object creation to factory.
         * @param[in]    className       name of class.
         * @param[in]    func            creation function.
         */
        static void registerCreation(const std::string& className, const createFunc& func);
    };
}


#define EB_OBJECT_CREATOR_REGISTRAION(_class)                                            \
    template<>                                                                           \
    class ObjectCreatorRegister<_class>                                                  \
    {                                                                                    \
    public:                                                                              \
        ObjectCreatorRegister()                                                          \
        {                                                                                \
            ::EB::ObjectCreator::registerCreation(#_class, [](){return new _class();});  \
        }                                                                                \
    };                                                                                   \
    static ObjectCreatorRegister<_class> g_ObjCreatorRegister##_class