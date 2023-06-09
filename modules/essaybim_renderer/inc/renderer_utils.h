#pragma once

#include "renderer_buffer_layout.h"

#include <glad/glad.h>

#include <unordered_map>

namespace EB
{
    namespace Utils_Renderer
    {
        /**
         * @brief   get char size of type.
         * @param[in]   type     data type of shader data.
         * @return    char size of data.
         */
        unsigned int shaderTypeSize(eShaderDataType type);

        /**
         * @brief   get component count of type.
         * @param[in]   type     data type of shader data.
         * @return    component of data.
         */
        unsigned int shaderTypeComponent(eShaderDataType type);

        /**
         * @brief   get OpenGL date type of type.
         * @param[in]   type     data type of shader data.
         * @return    OpenGL data type.
         */
        GLenum glTypeOfShaderType(eShaderDataType type);

        /**
         * @brief   parse shader source into vertex shader source and fragment shader source.
         * @param[in]   source    source data.
         * @return    map of vertex shader source and fragment shader source.
         */
        std::unordered_map<GLenum, std::string> parseShaderSource(const std::string& source);
    }
}