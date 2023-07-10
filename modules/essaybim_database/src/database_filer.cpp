#include "database_filer.h"

namespace EB
{

    DbFiler::DbFiler(DbObject* pObj)
        : Filer(), m_SessionStart(sizeof(void*) + sizeof(int))
    {
        writePointer(pObj);
    }

    DbFiler::~DbFiler()
    {

    }

    void DbFiler::pushSessionLength()
    {
        if (position() >= m_SessionStart) {
            writeInt(position() - m_SessionStart);
            m_SessionStart = position() + sizeof(int);
        }
    }

}