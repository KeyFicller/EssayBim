#include "basic_handle.h"

namespace EB
{

    Handle Handle::kNull = Handle(-1);

    void* Handle::memory() const
    {
        return s_Table[m_Index];
    }

    bool operator==(const Handle& hdl1, const Handle& hdl2)
    {
        if (hdl1 && hdl2) {
            return hdl1.m_Index == hdl2.m_Index;
        }
        return false;
    }

    std::vector<void*> Handle::s_Table;

}