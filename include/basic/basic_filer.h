#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

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
        bool readBool();

        /**
         * @brief  write a integer value to stream.
         * @param[in]  value   integer value.
         */
        void writeInt(int value);

        /**
         * @brief   read a integer value from stream.
         * @return    integer value.
         */
        int readInt();

        /**
         * @brief  write a float value to stream.
         * @param[in]  value   float value.
         */
        void writeFloat(float value);

        /**
         * @brief   read a float value from stream.
         * @return    float value.
         */
        float readFloat();

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
        std::string readString();

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
    };
}