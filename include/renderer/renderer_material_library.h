#pragma once

#include "renderer_material.h"

#include "basic_library.h"

namespace EB
{
    /**
     * @brief   this class is used for material management
     */
    class EB_RENDERER_EXPORT MaterialLibrary : public BaseLibrary<Material>
    {
    public:
        /**
         * @brief  destructor for material library.
         */
        ~MaterialLibrary() override = default;

    public:
        /**
         * @brief  get material by key.
         * @param[in]   key    key for search.
         * @return   shared pointer of found material.
         */
        Shared<Material> material(const std::string & key);

        /**
         * @brief  add an existing material to library.
         * @param[in]  shader   shared pointer of material.
         */
        void add(const Shared<Material>& material);

        /**
         * @brief  remove an existing material from library.
         * @param[in]  shader   shared pointer of material.
         */
        void remove(const Shared<Material>& material);

    protected:
        /**
         * @brief   interface for override import class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlIn(const std::string & key) override;

        /**
         * @brief   interface for override export class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlOut(const std::string & key) override;
    };
}