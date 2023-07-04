#pragma once

#include "renderer_export.h"
#include "basic_impl_template.h"
#include "basic_matrix.h"

#include <string>

namespace EB
{
    /**
     * @brief   this class is used to define basic shader class.
     */
    class EB_RENDERER_EXPORT Shader
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Shader)
    public:
        /**
         * @brief   create a shader with name and shader sources.
         * @param[in]     name          name of this shader.
         * @param[in]     vertexSrc     source string of vertex shader.
         * @param[in]     fragmentSrc   source string of fragment shader.
         * @return  shared pointer to created shader.
         */
        static Shared<Shader> create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);

        /**
         * @brief    create a shader with name and shader source path.
         * @param[in]     name          name of this shader.
         * @param[in]     filePath      file path of shader source.
         * @return  shared pointer to created shader.
         */
        static Shared<Shader> create(const std::string& name, const std::string& filePath);

        /**
         * @brief   create a shader with shader source path.
         * <p>
         * the file name will be set as shader name.
         * @param[in]     filePath      file path of shader source.
         * @return  shared pointer to created shader.
         */
        static Shared<Shader> create(const std::string& filePath);

    public:
        /**
         * @brief    constructor for shader.
         * @param[in]     name          name of this shader.
         * @param[in]     vertexSrc     source string of vertex shader.
         * @param[in]     fragmentSrc   source string of fragment shader.
         */
        Shader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);

        /**
         * @brief    constructor for shader.
         * @param[in]     name          name of this shader.
         * @param[in]     filePath      file path of shader source.
         */
        Shader(const std::string& name, const std::string& filePath);

        /**
         * @brief    constructor for shader.
         * <p>
         * the file name will be set as shader name.
         * @param[in]     filePath      file path of shader source.
         */
        Shader(const std::string& filePath);

        /**
         * @brief    destructor for shader.
         */
        ~Shader();

    public:
        /**
         * @brief    bind this shader to OpenGL for renderer.
         */
        void bind() const;

        /**
         * @brief    unbind this shader to OpenGL.
         */
        void unbind() const;

        /**
         * @brief    get shader name.
         * @return     name of shader.
         */
        std::string name() const;

        /**
         * @brief   set int value to uniform variable.
         * @param[in]    key    name of uniform variable.
         * @param[in]    value  int value.
         */
        void setInt(const std::string& key, int value);

        /**
         * @brief   set int value array to uniform variable.
         * @param[in]    key       name of uniform variable.
         * @param[in]    pValues   pointer to int value array data.
         */
        void setIntArray(const std::string& key, unsigned int count, int* pValues);

        /**
         * @brief   set float value to uniform variable.
         * @param[in]    key       name of uniform variable.
         * @param[in]    value     float value.
         */
        void setFloat(const std::string& key, float value);

        /**
         * @brief   set 2 component float value to uniform variable.
         * @param[in]    key       name of uniform variable.
         * @param[in]    value     float value.
         */
        void setFloat2(const std::string& key, const Vec2f& value);

        /**
         * @brief   set 3 component float value to uniform variable.
         * @param[in]    key       name of uniform variable.
         * @param[in]    value     float value.
         */
        void setFloat3(const std::string& key, const Vec3f& value);

        /**
         * @brief   set 4 component float value to uniform variable.
         * @param[in]    key       name of uniform variable.
         * @param[in]    value     float value.
         */
        void setFloat4(const std::string& key, const Vec4f& value);

        /**
         * @brief   set a 3 x 3 matrix to uniform variable.
         * @param[in]    key       name of uniform variable.
         * @param[in]    value     matrix value.
         */
        void setMat3(const std::string& key, const Mat3& value);

        /**
         * @brief   set a 4 x 4 matrix to uniform variable.
         * @param[in]    key       name of uniform variable.
         * @param[in]    value     matrix value.
         */
        void setMat4(const std::string& key, const Mat4& value);
    };
}