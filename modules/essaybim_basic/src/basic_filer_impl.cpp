#include "basic_filer_impl.h"

namespace EB
{
    FilerImpl::FilerImpl()
        : m_Index(0)
    {
        m_Data.clear();
    }

    FilerImpl::~FilerImpl()
    {

    }

    void FilerImpl::writeBool(bool value)
    {
        write_impl<bool>(value);
    }

    bool FilerImpl::readBool()
    {
        return read_Impl<bool>();
    }

    void FilerImpl::writeInt(int value)
    {
        write_impl<int>(value);
    }

    int FilerImpl::readInt()
    {
        return read_Impl<int>();
    }

    void FilerImpl::writeFloat(float value)
    {
        write_impl<float>(value);
    }

    float FilerImpl::readFloat()
    {
        return read_Impl<float>();
    }

    void FilerImpl::writeVec2(const Vec2& value)
    {
        writeBytes((char*)&value, sizeof(Vec2));
    }

    Vec2 FilerImpl::readVec2()
    {
        Vec2 temp;
        readBytes((char*)&temp, sizeof(Vec2));
        return temp;
    }

    void FilerImpl::writeVec3(const Vec3& value)
    {
        writeBytes((char*)&value, sizeof(Vec3));
    }

    Vec3 FilerImpl::readVec3()
    {
        Vec3 temp;
        readBytes((char*)&temp, sizeof(Vec3));
        return temp;
    }

    void FilerImpl::writeVec4(const Vec4& value)
    {
        writeBytes((char*)&value, sizeof(Vec4));
    }

    Vec4 FilerImpl::readVec4()
    {
        Vec4 temp;
        readBytes((char*)&temp, sizeof(Vec4));
        return temp;
    }

    void FilerImpl::writeString(const std::string& value)
    {
        writeInt(static_cast<int>(value.size()));
        writeBytes(value.c_str(), static_cast<int>(value.size()));
    }

    std::string FilerImpl::readString()
    {
        int size = 0;
        size = readInt();
        std::string res;
        res.resize(size);
        readBytes(res.data(), size);
        return res;
    }

    void FilerImpl::flushIn(Filer* pFiler)
    {
        auto& data = pFiler->m_pImpl->m_Data;
        writeBytes(data.data(), static_cast<int>(data.size()));
    }

    void FilerImpl::flushOut(Filer*& pFiler, int size)
    {
        if (m_Index + size > static_cast<int>(m_Data.size())) {
            EB_CORE_ASSERT(false, "Index out of range.");
        }
        pFiler = new Filer();
        pFiler->m_pImpl->writeBytes(m_Data.data() + m_Index, size);
    }

    bool FilerImpl::seek(int index)
    {
        if (index >= m_Data.size() || index < 0) {
            return false;
        }
        m_Index = index;
        return true;
    }

    void FilerImpl::clear()
    {
        m_Data.clear();
        m_Index = 0;
    }

}