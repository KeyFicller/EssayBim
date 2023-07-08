#pragma once

#include "document_export.h"

#include "basic_impl_template.h"
#include "basic_matrix.h"
#include "basic_yaml_base.h"

namespace EB
{
    class Window;
    class CameraImpl;

    /**
     * @brief  this class defines camera.
     */
    class EB_DOCUMENT_EXPORT Camera : public YamlBase
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Camera)
    protected:
        /**
         * @brief  construct for camera.
         * @param[in]   pWindow       window of camera.
         * @param[in]   projection    projection matrix.
         */
        Camera(Window* pWindow, const Mat4& projection = Mat4());

        /**
         * @brief   constructor for camera.
         * @param[in]   impl          implement of derived class.
         */
        Camera(CameraImpl& impl);

        /**
         * @brief   destructor for camera.
         */
        virtual ~Camera();

    public:
        /**
         * @brief  get projection matrix.
         * @return   projection matrix.
         */
        const Mat4 projectionMatrix() const;

        /**
         * @brief   get related window.
         * @return  related window.
         */
        Window* window() const;

    protected:
        /**
         * @brief   interface for override import class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlIn(const std::string& key) override final;

        /**
         * @brief   interface for override export class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlOut(const std::string& key) override final;
    };
}