#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"
#include "basic_vector.h"

#include <string>
#include <functional>

namespace EB
{
    /**
     * @brief  this class is to provide interfaces for export or import yaml data.
     */
    class EB_EXPORT YamlServer final
    {
        friend class YamlBase;
        EB_IMPL_DECLARATION_DISABLE_COPY(YamlServer)
    protected:
        /**
         * @brief   constructor for YamlServer.
         */
        YamlServer();

        /**
         * @brief   destructor for YamlServer.
         */
        ~YamlServer();

    public:
        /**
         * @brief   get global YamlServer instance.
         * @return  global YamlServer instance.
         */
        static YamlServer& instance();

    public:
        /**
         * @brief   begin yaml map session.
         */
        void beginMap();

        /**
         * @brief   end yaml map session.
         */
        void endMap();

        /**
         * @brief   start yaml recording, all yaml out data will be pushed into cache.
         */
        void startYamlOut();

        /**
         * @brief   end yaml out and flush cache to file.
         * @param[in]  filePath   export file path.
         */
        void endYamlOut(const std::string& filePath);

        /**
         * @brief   start yaml in and flush file to cache.
         * @param[in]   filePath   import file path.
         */
        void startYamlIn(const std::string& filePath);

        /**
         * @brief   end yaml in and clear cache.
         */
        void endYamlIn();

        /**
         * @brief    check if current yaml session has key.
         * @param[in]   key    yaml map key.
         * @return    true if has key.
         */
        bool hasKey(const std::string& key);

        /**
         * @breif    read value to yaml cache is key is not empty.
         * @param[in]   key    yaml map key.
         */
        void yamlIn(const std::string& key);

        /**
         * @breif    push a key to yaml cache is key is not empty.
         * @param[in]   key    yaml map key.
         */
        void yamlOut(const std::string& key);

        /**
         * @brief   read a bool value with key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  boolean value.
         */
        void yamlIn(const std::string& key, bool& value);

        /**
         * @brief  write a bool value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  boolean value.
         */
        void yamlOut(const std::string& key, bool value);

        /**
         * @brief   read a int value with key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  integer value.
         */
        void yamlIn(const std::string& key, int& value);

        /**
         * @brief  write a int value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  integer value.
         */
        void yamlOut(const std::string& key, int value);

        /**
         * @brief   read a real value with key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  real value.
         */
        void yamlIn(const std::string& key, float& value);

        /**
         * @brief  write a read value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  real value.
         */
        void yamlOut(const std::string& key, float value);

        /**
         * @brief   read a string value with key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  string value.
         */
        void yamlIn(const std::string& key, std::string& value);

        /**
         * @brief  write a string value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  string value.
         */
        void yamlOut(const std::string& key, const std::string& value);

        /**
         * @brief   read a vec2 value with key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  vec2 value.
         */
        void yamlIn(const std::string& key, Vec2f& value);

        /**
         * @brief  write a vec2 value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  vec2 value.
         */
        void yamlOut(const std::string& key, const Vec2f& value);

        /**
         * @brief   read a vec3 value with key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  vec3 value.
         */
        void yamlIn(const std::string& key, Vec3f& value);

        /**
         * @brief  write a vec3 value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  vec3 value.
         */
        void yamlOut(const std::string& key, const Vec3f& value);

        /**
         * @brief   read a vec4 value with key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  vec4 value.
         */
        void yamlIn(const std::string& key, Vec4f& value);

        /**
         * @brief  write a vec4 value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  vec4 value.
         */
        void yamlOut(const std::string& key, const Vec4f& value);

        /**
         * @brief  read a sequence from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   func   function return object pointer during reading.
         */
        void yamlInSequence(const std::string& key, std::function<YamlBase* ()> func);

        /**
         * @brief  write a sequence to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   func   function return object pointer during writing.
         */
        void yamlOutSequence(const std::string& key, std::function<YamlBase* ()> func);
    };



    /**
     * @brief  this class is used to serialize data into yaml file.
     */
    class EB_EXPORT YamlBase
    {
    public:
        /**
         * @brief  this class is used to auto insert yaml map key word.
         */
        class EB_EXPORT AutoMapWrapper
        {
        public:
            /**
             * @brief  constructor, auto export begin map keyword.
             */
            AutoMapWrapper();

            /**
             * @brief  destructor, auto export end map keyword.
             */
            ~AutoMapWrapper();
        };

    protected:
        /**
         * @brief   constructor for YamlBase.
         */
        YamlBase();

        /**
         * @brief   destructor for YamlBase.
         */
        ~YamlBase();

    public:
        /**
         * @brief   convert from yaml to this class data with key.
         * @param[in]    key     for yaml map.
         */
        void yamlIn(const std::string& key);

        /**
         * @brief   convert from class data to yaml data with key.
         * @param[in]    key     for yaml map.
         */
        void yamlOut(const std::string& key);

    protected:
        /**
         * @brief   interface for override import class data.
         * @param[in]    key    for yaml map.
         */
        virtual void subYamlIn(const std::string& key);

        /**
         * @brief   interface for override export class data.
         * @param[in]    key    for yaml map.
         */
        virtual void subYamlOut(const std::string& key);
    };
}


#define EB_YAML_OUT(...)     ::EB::YamlServer::instance().yamlOut(__VA_ARGS__)
#define EB_YAML_IN(...)      ::EB::YamlServer::instance().yamlIn(__VA_ARGS__)
#define EB_YAML_OUT_SEQ(...) ::EB::YamlServer::instance().yamlOutSequence(__VA_ARGS__)
#define EB_YAML_IN_SEQ(...) ::EB::YamlServer::instance().yamlInSequence(__VA_ARGS__)
#define EB_YAML_AUTO_MAP() ::EB::YamlBase::AutoMapWrapper wrapper

#define EB_YAML_DEFINE_KEY(_key_name)   const std::string _key_name = #_key_name;
#define EB_YAML_DEFINE_KEYS_0()
#define EB_YAML_DEFINE_KEYS_1(_first_key) EB_YAML_DEFINE_KEY(_first_key)
#define EB_YAML_DEFINE_KEYS_2(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_1(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_3(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_2(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_4(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_3(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_5(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_4(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_6(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_5(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_7(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_6(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_8(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_7(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_9(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_8(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_10(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_9(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_11(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_10(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_12(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_11(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_13(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_12(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_14(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_13(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_15(_first_key, ...) EB_YAML_DEFINE_KEY(_first_key) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_14(__VA_ARGS__))

#define EB_YAML_DEFINE_KEYS_N(...) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_GET_MACRO(EB_ARGS_AUGMENTER(__VA_ARGS__))(__VA_ARGS__))
#define EB_YAML_DEFINE_KEYS_GET_MACRO(...) EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_GET_MARCO_NAME(             \
    __VA_ARGS__,                                                                                           \
    EB_YAML_DEFINE_KEYS_15,                                                                                \
    EB_YAML_DEFINE_KEYS_14,                                                                                \
    EB_YAML_DEFINE_KEYS_13,                                                                                \
    EB_YAML_DEFINE_KEYS_12,                                                                                \
    EB_YAML_DEFINE_KEYS_11,                                                                                \
    EB_YAML_DEFINE_KEYS_10,                                                                                \
    EB_YAML_DEFINE_KEYS_9,                                                                                 \
    EB_YAML_DEFINE_KEYS_8,                                                                                 \
    EB_YAML_DEFINE_KEYS_7,                                                                                 \
    EB_YAML_DEFINE_KEYS_6,                                                                                 \
    EB_YAML_DEFINE_KEYS_5,                                                                                 \
    EB_YAML_DEFINE_KEYS_4,                                                                                 \
    EB_YAML_DEFINE_KEYS_3,                                                                                 \
    EB_YAML_DEFINE_KEYS_2,                                                                                 \
    EB_YAML_DEFINE_KEYS_1,                                                                                 \
    EB_YAML_DEFINE_KEYS_0                                                                                  \
))
#define EB_YAML_DEFINE_KEYS_GET_MARCO_NAME(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _macro, ...) _macro

#define EB_YAML_DECLARE_KEYS(...)                                                \
    namespace {                                                                  \
        struct KeyRegistration {                                                 \
            EB_EXPAND_MACRO(EB_YAML_DEFINE_KEYS_N(__VA_ARGS__))                  \
        };                                                                       \
    }                                                                            \
    static KeyRegistration s_Key

#define EB_YAML_DEFAULT_IN(_key_name)   EB_YAML_IN(s_Key._key_name, _key_name)
#define EB_YAML_DEFAULT_INS_0()
#define EB_YAML_DEFAULT_INS_1(_first_key) EB_YAML_DEFAULT_IN(_first_key)
#define EB_YAML_DEFAULT_INS_2(_first_key, ...) EB_YAML_DEFAULT_IN(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_1(__VA_ARGS__))
#define EB_YAML_DEFAULT_INS_3(_first_key, ...) EB_YAML_DEFAULT_IN(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_2(__VA_ARGS__))
#define EB_YAML_DEFAULT_INS_4(_first_key, ...) EB_YAML_DEFAULT_IN(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_3(__VA_ARGS__))
#define EB_YAML_DEFAULT_INS_5(_first_key, ...) EB_YAML_DEFAULT_IN(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_4(__VA_ARGS__))
#define EB_YAML_DEFAULT_INS_6(_first_key, ...) EB_YAML_DEFAULT_IN(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_5(__VA_ARGS__))
#define EB_YAML_DEFAULT_INS_7(_first_key, ...) EB_YAML_DEFAULT_IN(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_6(__VA_ARGS__))
#define EB_YAML_DEFAULT_INS_8(_first_key, ...) EB_YAML_DEFAULT_IN(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_7(__VA_ARGS__))
#define EB_YAML_DEFAULT_INS_9(_first_key, ...) EB_YAML_DEFAULT_IN(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_8(__VA_ARGS__))
#define EB_YAML_DEFAULT_INS_10(_first_key, ...) EB_YAML_DEFAULT_IN(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_9(__VA_ARGS__))

#define EB_YAML_DEFAULT_INS_N(...) EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_GET_MACRO(EB_ARGS_AUGMENTER(__VA_ARGS__))(__VA_ARGS__))
#define EB_YAML_DEFAULT_INS_GET_MACRO(...) EB_EXPAND_MACRO(EB_YAML_DEFAULT_INS_GET_MARCO_NAME(             \
    __VA_ARGS__,                                                                                           \
    EB_YAML_DEFAULT_INS_10,                                                                                \
    EB_YAML_DEFAULT_INS_9,                                                                                 \
    EB_YAML_DEFAULT_INS_8,                                                                                 \
    EB_YAML_DEFAULT_INS_7,                                                                                 \
    EB_YAML_DEFAULT_INS_6,                                                                                 \
    EB_YAML_DEFAULT_INS_5,                                                                                 \
    EB_YAML_DEFAULT_INS_4,                                                                                 \
    EB_YAML_DEFAULT_INS_3,                                                                                 \
    EB_YAML_DEFAULT_INS_2,                                                                                 \
    EB_YAML_DEFAULT_INS_1,                                                                                 \
    EB_YAML_DEFAULT_INS_0                                                                                  \
))
#define EB_YAML_DEFAULT_INS_GET_MARCO_NAME(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _macro, ...) _macro

#define EB_YAML_IN_DEFAULT_IMPLMENTS(...) EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_N(__VA_ARGS__))

#define EB_YAML_DEFAULT_OUT(_key_name)   EB_YAML_OUT(s_Key._key_name, _key_name)
#define EB_YAML_DEFAULT_OUTS_0()
#define EB_YAML_DEFAULT_OUTS_1(_first_key) EB_YAML_DEFAULT_OUT(_first_key)
#define EB_YAML_DEFAULT_OUTS_2(_first_key, ...) EB_YAML_DEFAULT_OUT(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_1(__VA_ARGS__))
#define EB_YAML_DEFAULT_OUTS_3(_first_key, ...) EB_YAML_DEFAULT_OUT(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_2(__VA_ARGS__))
#define EB_YAML_DEFAULT_OUTS_4(_first_key, ...) EB_YAML_DEFAULT_OUT(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_3(__VA_ARGS__))
#define EB_YAML_DEFAULT_OUTS_5(_first_key, ...) EB_YAML_DEFAULT_OUT(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_4(__VA_ARGS__))
#define EB_YAML_DEFAULT_OUTS_6(_first_key, ...) EB_YAML_DEFAULT_OUT(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_5(__VA_ARGS__))
#define EB_YAML_DEFAULT_OUTS_7(_first_key, ...) EB_YAML_DEFAULT_OUT(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_6(__VA_ARGS__))
#define EB_YAML_DEFAULT_OUTS_8(_first_key, ...) EB_YAML_DEFAULT_OUT(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_7(__VA_ARGS__))
#define EB_YAML_DEFAULT_OUTS_9(_first_key, ...) EB_YAML_DEFAULT_OUT(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_8(__VA_ARGS__))
#define EB_YAML_DEFAULT_OUTS_10(_first_key, ...) EB_YAML_DEFAULT_OUT(_first_key); EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_9(__VA_ARGS__))

#define EB_YAML_DEFAULT_OUTS_N(...) EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_GET_MACRO(EB_ARGS_AUGMENTER(__VA_ARGS__))(__VA_ARGS__))
#define EB_YAML_DEFAULT_OUTS_GET_MACRO(...) EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_GET_MARCO_NAME(             \
    __VA_ARGS__,                                                                                           \
    EB_YAML_DEFAULT_OUTS_10,                                                                                \
    EB_YAML_DEFAULT_OUTS_9,                                                                                 \
    EB_YAML_DEFAULT_OUTS_8,                                                                                 \
    EB_YAML_DEFAULT_OUTS_7,                                                                                 \
    EB_YAML_DEFAULT_OUTS_6,                                                                                 \
    EB_YAML_DEFAULT_OUTS_5,                                                                                 \
    EB_YAML_DEFAULT_OUTS_4,                                                                                 \
    EB_YAML_DEFAULT_OUTS_3,                                                                                 \
    EB_YAML_DEFAULT_OUTS_2,                                                                                 \
    EB_YAML_DEFAULT_OUTS_1,                                                                                 \
    EB_YAML_DEFAULT_OUTS_0                                                                                  \
))
#define EB_YAML_DEFAULT_OUTS_GET_MARCO_NAME(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _macro, ...) _macro

#define EB_YAML_OUT_DEFAULT_IMPLMENTS(...) EB_EXPAND_MACRO(EB_YAML_DEFAULT_OUTS_N(__VA_ARGS__))