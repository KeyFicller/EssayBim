#include "basic_export.h"
#include "basic_assert.h"

#include <vector>

/**
 * TODO: temporary code, fix this before 7.15
 */

namespace EB
{
    class EB_EXPORT Handle
    {
    protected:
        template <typename T>
        Handle(int index) : m_Index(index) {}

    public:
        template <typename T>
        static Handle create()
        {
            int index = s_Table.size();
            s_Table.emplace_back(malloc());
            return Handle<T>(index);
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

    public:
        void* memory() const;

    protected:
        static std::vector<void*> s_Table;

    private:
        int m_Index = -1;
    };
}