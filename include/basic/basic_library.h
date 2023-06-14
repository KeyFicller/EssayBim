#pragma once

#include "basic_yaml_base.h"
#include "basic_pointer.h"
#include "basic_assert.h"

#include <map>

namespace EB
{
    /**
     * @brief   a pure library template, header only.
     */
    template <typename item_t>
    class BaseLibrary : public YamlBase
    {
    public:
        /**
         * @brief  destructor for library.
         */
        virtual ~BaseLibrary() = default;

        /**
         * @brief   add an item to library.
         * @param[in]  key   key for search.
         * @param[in]  item  value to key.
         */
        void add(const std::string& key, const Shared<item_t>& item) {
            EB_CORE_ASSERT(!exist(key), "Already has this key.");
            m_ItemMap[key] = item;
        }

        /**
         * @brief  remove an item from library.
         * @param[in]  key   key for search.
         */
        void remove(const std::string& key) {
            EB_CORE_ASSERT(exist(key), "Doesn't have this key.");
            m_ItemMap.erase(key);
        }

        /**
         * @brief  remove all items.
         */
        void removeAll() {
            m_ItemMap.clear();
        }

        /**
         * @brief   get name list of stored items.
         * @return  name list.
         */
        std::vector<std::string> names() const {
            std::vector<std::string> res;
            for (auto& pair : m_ItemMap) {
                res.push_back(pair.first);
            }
            return res;
        }

        /**
         * @brief   get item by key.
         * @return   shared point of fined item.
         */
        Shared<item_t> get(const std::string& key) {
            EB_CORE_ASSERT(exist(key), "Doesn't have this key.");
            return m_ItemMap.at(key);
        }
    protected:
        /**
         * @brief  check if key exists in library.
         * @param[in]   key   key for search.
         * @return   whether key exists in library.
         */
        bool exist(const std::string& key) {
            return m_ItemMap.find(key) != m_ItemMap.end();
        }

    protected:
        /** < map implment of library > */
        std::map<std::string, Shared<item_t>> m_ItemMap;
    };
}