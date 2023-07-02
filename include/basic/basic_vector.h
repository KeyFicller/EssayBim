#pragma once

#include "basic_assert.h"

#include <type_traits>

#ifdef USE_GLM_IN_MODULE
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#endif

#ifdef USE_IMGUI_IN_MODULE
#include <imgui.h>
#endif

/**
 * comment by zhangyuhui:  latter i may change this from int[] to individual values.
 * this is a header only file, thus no need to export.
 */

namespace EB
{

    /**
     * @brief   this struct defines implement for vector.
     */
    template <typename T, int N>
    struct VecImpl
    {
        /**
         * @brief   constructor for elements.
         * @param[in]  elements    first N element of vector.
         */
        VecImpl(const std::initializer_list<T>& elements) {
            EB_CORE_ASSERT(elements.size() <= N, "Invalid init.");
            memset(m_Data, 0, sizeof(VecImpl));
            int i = 0;
            for (auto& element : elements) {
                m_Data[i++] = element;
            }
        }

        /**
         * @brief   get component by index.
         * @return  reference of component at index.
         */
        T& operator [] (int index) {
            EB_CORE_ASSERT(index < N, "Index out of range.");
            return m_Data[index];
        }

        /**
         * @brief   get component by index.
         * @return  component at index.
         */
        float operator [] (int index) const {
            EB_CORE_ASSERT(index < N, "Index out of range.");
            return m_Data[index];
        }

        /** < data > */
        T m_Data[N];
    };

    /**
     * @brief  this struct is used a 2 component vector.
     */
    template <typename T>
    struct Vec2 : public VecImpl<T, 2>
    {
        /**
         * @brief  default constructor for Vec2.
         */
        Vec2() : VecImpl<T, 2>({}) {}

        /**
         * @brief  constructor for Vec2.
         */
        Vec2(T x, T y) : VecImpl<T, 2>({ x, y }) {}

        /**
         * @brief   get first component.
         * @return  reference of first component.
         */
        T& x() { return VecImpl<T, 2>::m_Data[0]; }

        /**
         * @brief   get second component.
         * @return  reference of second component.
         */
        T& y() { return VecImpl<T, 2>::m_Data[1]; }

        /**
         * @brief   get first component.
         * @return  first component.
         */
        T x() const { return VecImpl<T, 2>::m_Data[0]; }

        /**
         * @brief   get second component.
         * @return  second component.
         */
        T y() const { return VecImpl<T, 2>::m_Data[1]; }
    };

    /**
     * @brief  this struct is used a 3 component vector
     */
    template <typename T>
    struct Vec3 : public VecImpl<T, 3>
    {
        /**
         * @brief  default constructor for Vec3.
         */
        Vec3() : VecImpl<T, 3>({}) {}

        /**
         * @brief  constructor for Vec3.
         */
        Vec3(T x, T y, T z) : VecImpl<T, 3>({ x, y, z }) {}

        /**
         * @brief   get first component.
         * @return  reference of first component.
         */
        T& x() { return VecImpl<T, 3>::m_Data[0]; }

        /**
         * @brief   get second component.
         * @return  reference of second component.
         */
        T& y() { return VecImpl<T, 3>::m_Data[1]; }

        /**
         * @brief   get third component.
         * @return  reference of second component.
         */
        T& z() { return VecImpl<T, 3>::m_Data[2]; }

        /**
         * @brief   get first component.
         * @return  first component.
         */
        T x() const { return VecImpl<T, 3>::m_Data[0]; }

        /**
         * @brief   get second component.
         * @return  second component.
         */
        T y() const { return VecImpl<T, 3>::m_Data[1]; }

        /**
         * @brief   get third component.
         * @return  second component.
         */
        T z() const { return VecImpl<T, 3>::m_Data[2]; }
    };

    /**
     * @brief  this struct is used a 4 component vector
     */
    template <typename T>
    struct Vec4 : public VecImpl<T, 4>
    {
        /**
         * @brief  default constructor for Vec4.
         */
        Vec4() : VecImpl<T, 4>({}) {}

        /**
         * @brief  constructor for Vec3.
         */
        Vec4(T x, T y, T z, T w) : VecImpl<T, 4>({ x, y, z, w }) {}

        /**
         * @brief   get first component.
         * @return  reference of first component.
         */
        T& x() { return VecImpl<T, 4>::m_Data[0]; }

        /**
         * @brief   get second component.
         * @return  reference of second component.
         */
        T& y() { return VecImpl<T, 4>::m_Data[1]; }

        /**
         * @brief   get third component.
         * @return  reference of second component.
         */
        T& z() { return VecImpl<T, 4>::m_Data[2]; }

        /**
         * @brief   get fourth component.
         * @return  reference of second component.
         */
        T& w() { return VecImpl<T, 4>::m_Data[3]; }

        /**
         * @brief   get first component.
         * @return  first component.
         */
        T x() const { return VecImpl<T, 4>::m_Data[0]; }

        /**
         * @brief   get second component.
         * @return  second component.
         */
        T y() const { return VecImpl<T, 4>::m_Data[1]; }

        /**
         * @brief   get third component.
         * @return  second component.
         */
        T z() const { return VecImpl<T, 4>::m_Data[2]; }

        /**
         * @brief   get fourth component.
         * @return  second component.
         */
        T w() const { return VecImpl<T, 4>::m_Data[3]; }
    };

    /**
     * @brief  this struct is used a 2 int component vector.
     */
    struct Vec2i : public Vec2<int>
    {
        using Vec2<int>::Vec2;
    };

    /**
     * @brief  this struct is used a 2 float component vector.
     */
    struct Vec2f : public Vec2<float>
    {
        using Vec2<float>::Vec2;

#ifdef USE_IMGUI_IN_MODULE
        /**
         * @brief    enable implicit cast to ImVec2.
         */
        operator ImVec2& () {
            return *reinterpret_cast<ImVec2*>(this);
        }

        /**
         * @brief    enable implicit cast to ImVec2.
         */
        operator ImVec2() const {
            return *reinterpret_cast<const ImVec2*>(this);
        }

        /**
         * @brief    enable implicit cast from ImVec2.
         * @param[in]    other      ImVec2 value.
         */
        Vec2f(const ImVec2& other) {
            m_Data[0] = other.x;
            m_Data[1] = other.y;
        }

        /*
         * @breif   enable operator = with ImVec2.
         * @param[in]   other       ImVec2 value.
         */
        Vec2f& operator = (const ImVec2& other) {
            m_Data[0] = other.x;
            m_Data[1] = other.y;
            return *this;
        }
#endif

    };

    /**
     * @brief  this struct is used a 3 float component vector
     */
    struct Vec3f : public Vec3<float>
    {
        using Vec3<float>::Vec3;

#ifdef USE_GLM_IN_MODULE
        /**
         * @brief    enable implicit cast to glm::vec3.
         */
        operator glm::vec3& () {
            return *reinterpret_cast<glm::vec3*>(this);
        }

        /**
         * @brief    enable implicit cast to glm::vec3.
         */
        operator glm::vec3() const {
            return *reinterpret_cast<const glm::vec3*>(this);
        }

        /**
         * @brief    enable implicit cast from glm::vec3.
         * @param[in]    other      glm:: vec3 value.
         */
        Vec3f(const glm::vec3& other) {
            m_Data[0] = other.x;
            m_Data[1] = other.y;
            m_Data[2] = other.z;
        }

        /*
         * @breif   enable operator = with glm::vec3.
         * @param[in]   other       glm::vec3 value.
         */
        Vec3f& operator = (const glm::vec3& other) {
            m_Data[0] = other.x;
            m_Data[1] = other.y;
            m_Data[2] = other.z;
            return *this;
        }
#endif

    };

    /**
     * @brief  this struct is used a 3 int component vector
     */
    struct Vec3i : public Vec3<int>
    {
        using Vec3<int>::Vec3;
    };

    /**
     * @brief  this struct is used a 4 float component vector
     */
    struct Vec4f : public Vec4<float>
    {
        using Vec4<float>::Vec4;

#ifdef USE_GLM_IN_MODULE
        /**
         * @brief    enable implicit cast to glm::vec4.
         */
        operator glm::vec4& () {
            return *reinterpret_cast<glm::vec4*>(this);
        }

        /**
         * @brief    enable implicit cast to glm::vec4.
         */
        operator glm::vec4() const {
            return *reinterpret_cast<const glm::vec4*>(this);
        }

        /**
         * @brief    enable implicit cast from glm::vec4.
         * @param[in]    other      glm:: vec4 value.
         */
        Vec4f(const glm::vec4& other) {
            m_Data[0] = other.x;
            m_Data[1] = other.y;
            m_Data[2] = other.z;
            m_Data[3] = other.w;
        }

        /*
         * @breif   enable operator = with glm::vec4.
         * @param[in]   other       glm::vec4 value.
         */
        Vec4f& operator = (const glm::vec4& other) {
            m_Data[0] = other.x;
            m_Data[1] = other.y;
            m_Data[2] = other.z;
            m_Data[3] = other.w;
            return *this;
        }
#endif

#ifdef USE_IMGUI_IN_MODULE
        /**
         * @brief    enable implicit cast to ImVec4.
         */
        operator ImVec4& () {
            return *reinterpret_cast<ImVec4*>(this);
        }

        /**
         * @brief    enable implicit cast to ImVec4.
         */
        operator ImVec4() const {
            return *reinterpret_cast<const ImVec4*>(this);
        }

        /**
         * @brief    enable implicit cast from ImVec4.
         * @param[in]    other      ImVec4 value.
         */
        Vec4f(const ImVec4& other) {
            m_Data[0] = other.x;
            m_Data[1] = other.y;
            m_Data[2] = other.z;
            m_Data[3] = other.w;
        }

        /*
         * @breif   enable operator = with ImVec4.
         * @param[in]   other       ImVec4 value.
         */
        Vec4f& operator = (const ImVec4& other) {
            m_Data[0] = other.x;
            m_Data[1] = other.y;
            m_Data[2] = other.z;
            m_Data[3] = other.w;
            return *this;
        }
#endif
    };

    /**
     * @brief  test if template T is defined vector.
     * @return     whether T is defined vector.
     */
    template <typename T>
    constexpr bool isVec()
    {
        return std::is_base_of<Vec2<int>, T>() ||
               std::is_base_of<Vec2<float>, T>() ||
               std::is_base_of<Vec3<int>, T>() ||
               std::is_base_of<Vec3<float>, T>() ||
               std::is_base_of<Vec4<int>, T>() ||
               std::is_base_of<Vec4<float>, T>();
    }
}