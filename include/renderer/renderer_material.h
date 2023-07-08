#pragma once

#include "renderer_export.h"

#include "basic_impl_template.h"
#include "basic_vector.h"
#include "basic_yaml_base.h"

#include <string>

namespace EB
{
    /**
     * @biref  this struct define material property.
     */
    struct EB_RENDERER_EXPORT Material : public YamlBase
    {
        /** < name of material > */
        std::string Name;

        /** < ambient of material > */
        Vec3f Ambient;

        /** < diffuse of material > */
        Vec3f Diffuse;

        /** < specular of maaterial > */
        Vec3f Specular;

        /** < shiniess of material > */
        float Shininess;

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
        void subYamlOut(const std::string& key) override;
    };
}