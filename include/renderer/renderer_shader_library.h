#pragma once

#include "renderer_export.h"
#include "renderer_shader.h"

#include "basic_library.h"

namespace EB
{
    /**
     * @brief  this class define library for shader.
     */
    class EB_RENDERER_EXPORT ShaderLibrary : public BaseLibrary<Shader>
    {
    public:
        /**
         * @brief  destructor for shader library.
         */
        ~ShaderLibrary() override = default;

    public:
        /**
         * @brief  get shader by key.
         * @param[in]   key    key for search.
         * @return   shared pointer of found shader.
         */
        Shared<Shader> shader(const std::string& key);

        /**
         * @brief  add an existing shader to library.
         * @param[in]  shader   shared pointer of shader.
         */
        void add(const Shared<Shader>& shader);

        /**
         * @brief  remove an existing shader from library.
         * @param[in]  shader   shared pointer of shader.
         */
        void remove(const Shared<Shader>& shader);

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