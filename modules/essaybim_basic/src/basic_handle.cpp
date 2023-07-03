#include "basic_handle.h"

namespace EB
{

    void* Handle::memory() const
    {
        return s_Table[m_Index];
    }

    std::vector<void*> Handle::s_Table;

}