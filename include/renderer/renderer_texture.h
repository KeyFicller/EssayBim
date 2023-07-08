#pragma once

#include "renderer_export.h"

#include "basic_impl_template.h"

#include <string>

namespace EB
{
    /**
     * @brief  this class is used to define Texture.
     */
    class EB_RENDERER_EXPORT Texture2D
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Texture2D);
    public:
        /**
         * @brief   create texture 2d with specified file.
         * @param[in]   filePath    texture file path.
         * @param[in]   name        name of created texture, if null, will use file name.
         * @return  shared pointer of created texture2d.
         */
        static Shared<Texture2D> create(const std::string& filePath, const std::string& name = std::string());

        /**
         * @brief   create texutre2d with width and height.
         * @param[in]   name        name of created texture.
         * @param[in]   width       width of texture.
         * @param[in]   height      height of texture.
         */
        static Shared<Texture2D> create(const std::string& name, unsigned int width, unsigned int height);

    public:
        /**
         * @brief   construct texture 2d with specified file.
         * @param[in]   filePath    texture file path.
         * @param[in]   name        name of created texture, if null, will use file name.
         */
        Texture2D(const std::string& filePath, const std::string& name = std::string());

        /**
         * @brief   constructor texutre2d with width and height.
         * @param[in]   name        name of created texture.
         * @param[in]   width       width of texture.
         * @param[in]   height      height of texture.
         */
        Texture2D(const std::string& name, unsigned int width, unsigned int height);

        /**
         * @brief   destructor for texture.
         */
        ~Texture2D();

    public:
        /**
         * @brief  get texture width.
         * @return  width of texture.
         */
        unsigned int width() const;

        /**
         * @brief  get texture height.
         * @return  height of texture.
         */
        unsigned int height() const;

        /**
         * @brief  bind texture to slot.
         * @param[in]  slot    0 - 32
         */
        void bind(unsigned int slot = 0) const;

        /**
         * @brief  unbind texture.
         */
        void unbind() const;

        /**
         * @brief  set data to texture directly.
         * @param[in]  data    texture raw data.
         * @param[in]  size    size of data in char.
         */
        void setData(void* data, unsigned int size);

        /**
         * @brief  get identifier allocated by OpenGL.
         * @return  identifier.
         */
        unsigned int rendererId() const;

        /**
         * @brief   override for texture compare.
         * @param[in]  other   pointer to other Texture2d.
         * @return  whether texture is the same.
         */
        bool operator == (const Texture2D* other) const;

        /**
         * @brief  get texture name.
         * @return name of texture.
         */
        std::string name() const;

        /**
         * @brief    get texture file path.
         * @return   file path of texture.
         */
        std::string filepath() const;
    };
}