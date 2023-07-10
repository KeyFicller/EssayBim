#pragma once

#include "basic_export.h"
#include "basic_assert.h"

#include <vector>

/**
 * TODO: temporary code, fix this before 7.15
 */

namespace EB
{
    class EB_BASIC_EXPORT Handle
    {
    public:
        Handle() : m_Index(-1) {}

        static Handle kNull;
    protected:
        Handle(int index) : m_Index(index) {}

    public:
        Handle(const Handle& other) : m_Index(other.m_Index) {}
        Handle& operator = (const Handle& other) { m_Index = other.m_Index; return *this; }

    public:
        template <typename T>
        static Handle create()
        {
            int index = static_cast<int>(s_Table.size());
            s_Table.emplace_back(malloc(sizeof(T)));
            return Handle(index);
        }

        static Handle create(void* ptr)
        {
            int index = static_cast<int>(s_Table.size());
            s_Table.emplace_back(ptr);
            return Handle(index);
        }

        template <typename T>
        static void free(const Handle& handle)
        {
            EB_SAFE_DELETE(s_Table[handle.m_Index]);
        }

        template <typename T>
        static T* access(const Handle& handle)
        {
            void* ptr = handle.memory();
            EB_CORE_ASSERT(ptr);
            return reinterpret_cast<T*>(ptr);
        }

        operator bool() const
        {
            return m_Index != -1;
        }

        operator int() const
        {
            return m_Index;
        }

    private:
        void* memory() const;

    protected:
        static std::vector<void*> s_Table;

    public:
        int m_Index = -1;
    };

    EB_BASIC_STATIC_EXPORT bool operator == (const Handle& hdl1, const Handle& hdl2);
    
}