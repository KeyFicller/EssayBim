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

    void Filer::writeVec2(const Vec2& value)
    {
        EB_IMPL()->writeVec2(value);
    }

    Vec2 Filer::readVec2() const
    {
        return EB_IMPL()->readVec2();
    }

    void Filer::writeVec3(const Vec3& value)
    {
        EB_IMPL()->writeVec3(value);
    }

    Vec3 Filer::readVec3() const
    {
        return EB_IMPL()->readVec3();
    }

    void Filer::writeVec4(const Vec4& value)
    {
        EB_IMPL()->writeVec4(value);
    }

    Vec4 Filer::readVec4() const
    {
        return EB_IMPL()->readVec4();
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