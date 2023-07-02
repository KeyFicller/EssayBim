#include "basic_filer.h"

#include "basic_filer_impl.h"

namespace EB
{

    Filer::Filer()
    {
        EB_IMPL() = createScoped<FilerImpl>();
    }

    Filer::~Filer()
    {
        EB_IMPL().reset();
    }

    void Filer::writeBool(bool value)
    {
        EB_IMPL()->writeBool(value);
    }

    bool Filer::readBool() const
    {
        return EB_IMPL()->readBool();
    }

    void Filer::writeInt(int value)
    {
        EB_IMPL()->writeInt(value);
    }

    int Filer::readInt() const
    {
        return EB_IMPL()->readInt();
    }

    void Filer::writeFloat(float value)
    {
        EB_IMPL()->writeFloat(value);
    }

    float Filer::readFloat() const
    {
        return EB_IMPL()->readFloat();
    }

    void Filer::writeBytes(const char* value, int size)
    {
        EB_IMPL()->writeBytes(value, size);
    }

    void Filer::readBytes(char* value, int size) const
    {
        EB_IMPL()->readBytes(value, size);
    }

    void Filer::writeString(const std::string& value)
    {
        EB_IMPL()->writeString(value);
    }

    std::string Filer::readString() const
    {
        return EB_IMPL()->readString();
    }

    void Filer::flushIn(Filer* pFiler)
    {
        EB_IMPL()->flushIn(pFiler);
    }

    void Filer::flushOut(Filer*& pFiler, int size)
    {
        EB_IMPL()->flushOut(pFiler, size);
    }

    bool Filer::seek(int index)
    {
        return EB_IMPL()->seek(index);
    }

    void Filer::clear()
    {
        EB_IMPL()->clear();
    }

}