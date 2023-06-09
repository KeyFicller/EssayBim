#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"
#include "basic_vector.h"

#include <string>

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
         * @breif    push a key to yaml cache is key is not empty.
         * @param[in]   key    yaml map key.
         */
        void yamlOut(const std::string& key);

        /**
         * @breif    read value to yaml cache is key is not empty.
         * @param[in]   key    yaml map key.
         */
        void yamlIn(const std::string& key);

        /**
         * @brief   push a bool value with key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  boolean value.
         */
        void yamlIn(const std::string& key, bool& value);

        /**
         * @brief  read a bool value of key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  boolean value.
         */
        void yamlOut(const std::string& key, bool value);

        /**
         * @brief   push a int value with key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  integer value.
         */
        void yamlIn(const std::string& key, int& value);

        /**
         * @brief  read a int value of key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  integer value.
         */
        void yamlOut(const std::string& key, int value);

        /**
         * @brief   push a real value with key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  real value.
         */
        void yamlIn(const std::string& key, float& value);

        /**
         * @brief  read a read value of key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  real value.
         */
        void yamlOut(const std::string& key, float value);

        /**
         * @brief   push a string value with key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  string value.
         */
        void yamlIn(const std::string& key, std::string& value);

        /**
         * @brief  read a string value of key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  string value.
         */
        void yamlOut(const std::string& key, const std::string& value);

        /**
         * @brief   push a vec2 value with key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  vec2 value.
         */
        void yamlIn(const std::string& key, Vec2& value);

        /**
         * @brief  read a vec2 value of key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  vec2 value.
         */
        void yamlOut(const std::string& key, const Vec2& value);

        /**
         * @brief   push a vec3 value with key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  vec3 value.
         */
        void yamlIn(const std::string& key, Vec3& value);

        /**
         * @brief  read a vec3 value of key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  vec3 value.
         */
        void yamlOut(const std::string& key, const Vec3& value);

        /**
         * @brief   push a vec4 value with key to yaml cache.
         * @param[in]   key    yaml map key.
         * @param[in]   value  vec4 value.
         */
        void yamlIn(const std::string& key, Vec4& value);

        /**
         * @brief  read a vec4 value of key from yaml cache.
         * @param[in]   key    yaml map key.
         * @param[out]  value  vec4 value.
         */
        void yamlOut(const std::string& key, const Vec4& value);
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
        class AutoMapWrapper
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