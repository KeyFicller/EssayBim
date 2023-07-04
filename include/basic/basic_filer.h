#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"
#include "basic_vector.h"

#include <type_traits>
#include <string>

namespace EB
{
    /**
     * @brief  this class is used to record data as stream for communicative.
     */
    class EB_BASIC_EXPORT Filer
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
         * @brief  write bytes to stream
         * @param[in]   value      byte data.
         * @param[in]   size       char size of byte data.
         */
        void writeBytes(const char* value, int size);

        /**
         * @brief   read bytes from stream
         * @param[in]   value      byte cache for export;
         * @param[in]    size      char size of byte data.
         */
        void readBytes(char* value, int size) const;

        /**
         * @brief   write a vector to stream.
         * @param[in]    value     vector value.
         */
        template <typename Vec_t>
        void writeVec(const Vec_t& value);

        /**
         * @brief   read a vector from stream.
         * @return        vector value.
         */
        template <typename Vec_t>
        Vec_t readVec() const;

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

    template <typename Vec_t>
    Vec_t Filer::readVec() const
    {
        static_assert(isVec<Vec_t>());
        Vec_t tmp;
        readBytes((char*)&tmp, sizeof(Vec_t));
        return tmp;
    }

    template <typename Vec_t>
    void Filer::writeVec(const Vec_t& value)
    {
        static_assert(isVec<Vec_t>());
        writeBytes((const char*)&value, sizeof(Vec_t));
    }

}