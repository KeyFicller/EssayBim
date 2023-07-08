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

        static Handle Null;
    protected:
        Handle(int index) : m_Index(index) {}

    public:
        template <typename T>
        static Handle create()
        {
            int index = static_cast<int>(s_Table.size());
            s_Table.emplace_back(malloc(sizeof(T)));
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

        bool operator = (const Handle& other)
        {
            return m_Index == other.m_Index;
        }

        operator bool() const
        {
            return (*this) == Null;
        }

    private:
        void* memory() const;

    protected:
        static std::vector<void*> s_Table;

    private:
        int m_Index = -1;
    };
}