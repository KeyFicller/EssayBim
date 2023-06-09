#pragma once

#include "basic_filer.h"
#include "basic_assert.h"

#include <string>
#include <vector>

#pragma warning(disable: 26451)

namespace EB
{
    class FilerImpl final
    {
        friend class Filer;
        friend class Stream;
    public:
        FilerImpl();
        ~FilerImpl();

    public:
        void writeBool(bool value);
        bool readBool();
        void writeInt(int value);
        int readInt();
        void writeFloat(float value);
        float readFloat();
        void writePointer(void* value);
        void* readPointer();
        void writeString(const std::string& value);
        std::string readString();
        void flushIn(Filer* pFiler);
        void flushOut(Filer*& pFiler, int size);
        int position() const;
        bool seek(int index);
        void clear();

    private:
        void writeBytes(const char* value, int size)
        {
            int capacity = m_Index + size;
            if (capacity > static_cast<int>(m_Data.size())) {
                auto copy = m_Data;
                m_Data.resize(2 * capacity);
                memcpy_s(m_Data.data(), copy.size(), copy.data(), copy.size());
            }
            memcpy_s(m_Data.data() + m_Index, size, value, size);
            m_Index += size;
        }

        void readBytes(char* value, int size)
        {
            if (m_Index + size > static_cast<int>(m_Data.size())) {
                EB_CORE_ASSERT(false, "Index out of range.");
            }
            memcpy_s(value, size, m_Data.data() + m_Index, size);
            m_Index += size;
        }

        template <typename T>
        void write_impl(const T& value)
        {
            constexpr int size = sizeof(T);
            auto ch_value = reinterpret_cast<const char*>(&value);
            writeBytes(ch_value, size);
        }

        template <typename T>
        T read_Impl()
        {
            constexpr int size = sizeof(T);
            char* buff = new char[size];
            readBytes(buff, size);
            T res = *(reinterpret_cast<T*>(buff));
            delete[] buff;
            return res;
        }

    private:
        /* < storage of stream data > */
        std::vector<char> m_Data;

        /* < cursor pos > */
        int m_Index;
    };
}