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
        void yamlIn(const std::string& key, Vec2& value);

        /**
         * @brief  write a vec2 value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  vec2 value.
         */
        void yamlOut(const std::string& key, const Vec2& value);

        /**
         * @brief   read a vec3 value with key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  vec3 value.
         */
        void yamlIn(const std::string& key, Vec3& value);

        /**
         * @brief  write a vec3 value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  vec3 value.
         */
        void yamlOut(const std::string& key, const Vec3& value);

        /**
         * @brief   read a vec4 value with key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  vec4 value.
         */
        void yamlIn(const std::string& key, Vec4& value);

        /**
         * @brief  write a vec4 value of key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  vec4 value.
         */
        void yamlOut(const std::string& key, const Vec4& value);

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
    protected:
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

#define EB_DEFINE_YAML_KEY(_key_name)                      \
    const std::string _key_name = #_key_name;

#define EB_YAML_AUTO_MAP() ::EB::YamlBase::AutoMapWrapper wrapper
#define EB_DEFINE_YAML_KEY_EXPAND(x) x

#define EB_DEFINE_YAML_KEY_0()
#define EB_DEFINE_YAML_KEY_1(_first_key) EB_DEFINE_YAML_KEY(_first_key)
#define EB_DEFINE_YAML_KEY_2(_first_key, ...) EB_DEFINE_YAML_KEY(_first_key) EB_DEFINE_YAML_KEY_EXPAND(EB_DEFINE_YAML_KEY_1(__VA_ARGS__))
#define EB_DEFINE_YAML_KEY_3(_first_key, ...) EB_DEFINE_YAML_KEY(_first_key) EB_DEFINE_YAML_KEY_EXPAND(EB_DEFINE_YAML_KEY_2(__VA_ARGS__))
#define EB_DEFINE_YAML_KEY_4(_first_key, ...) EB_DEFINE_YAML_KEY(_first_key) EB_DEFINE_YAML_KEY_EXPAND(EB_DEFINE_YAML_KEY_3(__VA_ARGS__))
#define EB_DEFINE_YAML_KEY_5(_first_key, ...) EB_DEFINE_YAML_KEY(_first_key) EB_DEFINE_YAML_KEY_EXPAND(EB_DEFINE_YAML_KEY_4(__VA_ARGS__))

// from https://stackoverflow.com/questions/2124339/c-preprocessor-va-args-number-of-arguments
#define GET_ARG_COUNT(...)  INTERNAL_EXPAND_ARGS_PRIVATE(INTERNAL_ARGS_AUGMENTER(__VA_ARGS__))
#define INTERNAL_ARGS_AUGMENTER(...) unused, __VA_ARGS__
#define INTERNAL_EXPAND(x) x
#define INTERNAL_EXPAND_ARGS_PRIVATE(...) INTERNAL_EXPAND(INTERNAL_GET_ARG_COUNT_PRIVATE(__VA_ARGS__, EB_DEFINE_YAML_KEY_5, EB_DEFINE_YAML_KEY_4, EB_DEFINE_YAML_KEY_3, EB_DEFINE_YAML_KEY_2, EB_DEFINE_YAML_KEY_1, EB_DEFINE_YAML_KEY_0))
#define INTERNAL_GET_ARG_COUNT_PRIVATE(_1_, _2_, _3_, _4_, _5_, _6_, count, ...) count

#define EB_DEFINE_YAML_KEY_N(...) EB_DEFINE_YAML_KEY_EXPAND(GET_ARG_COUNT(__VA_ARGS__)(__VA_ARGS__))

#define EB_DECLARE_YAML_KEYS(...)                                                \
    namespace {                                                                  \
        struct KeyRegistration {                                                 \
            EB_DEFINE_YAML_KEY_EXPAND(EB_DEFINE_YAML_KEY_N(__VA_ARGS__))         \
        };                                                                       \
    }                                                                            \
    static KeyRegistration s_Key