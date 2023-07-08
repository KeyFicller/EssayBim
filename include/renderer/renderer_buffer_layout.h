#pragma once

#include "renderer_export.h"

#include "basic_impl_template.h"

#include <string>
#include <vector>

namespace EB
{
    /**
     * @brief   this enum class is used to define data type.
     */
    enum class eShaderDataType
    {
        /** < unknown type > */
        kNone,

        /** < boolean type > */
        kBool,

        /** < integer type of different component > */
        kInt, kInt2, kInt3, kInt4,

        /** < float type of different component > */
        kFloat, kFloat2, kFloat3, kFloat4,

        /** < matrix type of different component > */
        kMat2, kMat3, kMat4
    };

    /**
     * @brief   this struct is used to define element data structural in layout.
     */
    struct EB_RENDERER_EXPORT BufferLayoutElement
    {
        /** < element name identifier > */
        std::string Name = "Unknown";

        /** < element data type > */
        eShaderDataType Type = eShaderDataType::kNone;

        /** < data size corresponding to type > */
        unsigned int Size = 0;

        /** < offset position of this data in buffer > */
        unsigned int Offset = 0;

        /** < whether this data should be normalized > */
        bool Normalized = false;

        /** < how much component this data type owns > */
        unsigned int Component = 0;

    public:
        /**
         * @brief  default constructor for buffer layout element.
         */
        BufferLayoutElement() = default;

        /**
         * @brief  constructor for buffer layout element.
         * @param[in]     name          name of component.
         * @param[in]     type          enum type of data.
         * @param[in]     normalized    whether this data should be normalized.
         */
        BufferLayoutElement(const std::string& name, eShaderDataType type, bool normalized = false);
    };

    /**
     * @brief   this class is used to specify buffer data structural.
     */
    class EB_RENDERER_EXPORT BufferLayout
    {
        EB_IMPL_DECLARATION_ENABLE_COPY(BufferLayout)
    public:
        /**
         * @brief   constructor for buffer layout.
         */
        BufferLayout();

        /**
         * @brief  constructor for buffer layout.
         * @param[in]   elements      elements consists of buffer layout.
         */
        BufferLayout(const std::initializer_list<BufferLayoutElement>& elements);

        /**
         * @brief   destructor for buffer layout.
         */
        ~BufferLayout();

    public:
        /**
         * @brief   get elements of layout.
         * @return    elements of layout.
         */
        const std::vector<BufferLayoutElement>& elements() const;

        /**
         * @brief   get total data length of layout.
         * @return     total data length of char.
         */
        unsigned int stride() const;
    };
}