#include "basic_stream.h"

#include "basic_filer_impl.h"

namespace EB
{

    Stream::Stream()
        : Filer()
    {

    }

    Stream::~Stream()
    {

    }

    void Stream::offer(Filer* filer, int size)
    {
        filer->writeBytes(EB_IMPL()->m_Data.data() + position(), size);
    }

    void Stream::accept(Filer* filer)
    {
        EB_IMPL()->writeBytes(filer->m_pImpl->m_Data.data(), filer->position());
    }

    int Stream::readIndex()
    {
        return EB_IMPL()->readInt();
    }

    int Stream::readLength()
    {
        return EB_IMPL()->readInt();
    }

    void Stream::writeIndex(int index)
    {
        EB_IMPL()->writeInt(index);
    }

    void Stream::writeLength(int length)
    {
        EB_IMPL()->writeInt(length);
    }

}