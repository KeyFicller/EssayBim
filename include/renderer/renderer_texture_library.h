#pragma once

#include "renderer_export.h"
#include "renderer_texture.h"

#include "basic_impl_template.h"
#include "basic_library.h"

namespace EB
{
    /**
     * @brief  this class is defined to manage texture.
     */
    class EB_RENDERER_EXPORT Texture2DLibrary : public BaseLibrary<Texture2D>
    {
    public:
        /**
         * @brief  destructor for texture library.
         */
        ~Texture2DLibrary() override = default;

    public:
        /**
         * @brief  get texture by key.
         * @param[in]  key   key for search.
         * @return  shared pointer of found texture.
         */
        Shared<Texture2D> texture(const std::string& key);

        /**
         * @brief   add an existing texture to library.
         * @param[in]  texture  shared pointer of texture.
         */
        void add(const Shared<Texture2D>& texture);

        /**
         * @brief   remove an existing texture from library.
         * @param[in]  texture  shared pointer of texture.
         */
        void remove(const Shared<Texture2D>& texture);

    protected:
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