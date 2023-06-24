#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"
#include "basic_vector.h"

#include <string>

namespace EB
{
    /**
     * @brief  this class is used to record data as stream for communicative.
     */
    class EB_EXPORT Filer
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Filer)
    public:
        /**
         * @brief  constructor for Filer.
         */
        Filer();

        /**
         * @brief  destructor for Filer
         */
        virtual ~Filer();

    public:
        /**
         * @brief  write a boolean value to stream.
         * @param[in]  value   bool value.
         */
        void writeBool(bool value);

        /**
         * @brief   read a boolean value from stream.
         * @return    bool value.
         */
        bool readBool() const;

        /**
         * @brief  write a integer value to stream.
         * @param[in]  value   integer value.
         */
        void writeInt(int value);

        /**
         * @brief   read a integer value from stream.
         * @return    integer value.
         */
        int readInt() const;

        /**
         * @brief  write a float value to stream.
         * @param[in]  value   float value.
         */
        void writeFloat(float value);

        /**
         * @brief   read a float value from stream.
         * @return    float value.
         */
        float readFloat() const;

        /**
         * @brief   write a vec2 value to stream.
         * @param[in]   value   vec2 value.
         */
        void writeVec2(const Vec2f& value);

        /**
         * @brief   read a vec2 value from stream
         * @return    vec2 value.
         */
        Vec2f readVec2() const;

        /**
         * @brief   write a vec3 value to stream.
         * @param[in]   value   vec3 value.
         */
        void writeVec3(const Vec3f& value);

        /**
         * @brief   read a vec3 value from stream
         * @return    vec3 value.
         */
        Vec3f readVec3() const;

        /**
         * @brief   write a vec4 value to stream.
         * @param[in]   value   vec4 value.
         */
        void writeVec4(const Vec4f& value);

        /**
         * @brief   read a vec4 value from stream
         * @return    vec4 value.
         */
        Vec4f readVec4() const;

        /**
         * @brief  write a string value to stream.
         * @param[in]  value   string value.
         */
        void writeString(const std::string& value);

        /**
         * @breif  write a const string value to stream.
         * @param[in]  value   const string value.
         */
        template <unsigned N>
        void writeString(const char(&value)[N])
        {
            return writeString(std::string(value));
        }

        /**
         * @brief   read a string value from stream.
         * @return    string value.
         */
        std::string readString() const;

        /**
         * @brief   flush in another filer.
         * @param[in] pFiler   pointer to another filer.
         */
        void flushIn(Filer* pFiler);

        /**
         * @brief    flush out some data to filer.
         * @param[out]  pFiler   pointer to created filer.
         * @param[in]   size     flushed out char size.
         */
        void flushOut(Filer*& pFiler, int size);

        /**
         * @brief    seek to specific index.
         * @return   false if seek failed.
         */
        bool seek(int index);

        /**
         * @brief    clear filer cache.
         */
        void clear();
    };
}