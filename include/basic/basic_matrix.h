#pragma once

#include "basic_assert.h"
#include "basic_vector.h"

#ifdef USE_GLM_IN_MODULE
#include "glm/glm.hpp"
#endif

#ifdef USE_IMGUI_IN_MODULE

#endif

namespace EB
{
    /**
     * @brief  this struct is used as a 2 x 2 matrix.
     */
    struct Mat2
    {
        /**
         * @brief  default constructor for Vec2.
         */
        Mat2() : m_Data{ Vec2(), Vec2() } {}

        /**
         * @brief   get vector by index.
         * @return  reference of vector at index.
         */
        Vec2& operator [] (int index) {
            EB_CORE_ASSERT(index < 2, "Index out of range.");
            return m_Data[index];
        }

        /**
         * @brief   get vector by index.
         * @return  vector at index.
         */
        Vec2 operator [] (int index) const {
            EB_CORE_ASSERT(index < 2, "Index out of range.");
            return m_Data[index];
        }

        /** < data > */
        Vec2 m_Data[2];
    };

    /**
     * @brief  this struct is used as a 3 x 3 matrix.
     */
    struct Mat3
    {
        /**
         * @brief  default constructor for Vec3.
         */
        Mat3() : m_Data{ Vec3(), Vec3(), Vec3() } {}

        /**
         * @brief   get vector by index.
         * @return  reference of vector at index.
         */
        Vec3& operator [] (int index) {
            EB_CORE_ASSERT(index < 3, "Index out of range.");
            return m_Data[index];
        }

        /**
         * @brief   get vector by index.
         * @return  vector at index.
         */
        Vec3 operator [] (int index) const {
            EB_CORE_ASSERT(index < 3, "Index out of range.");
            return m_Data[index];
        }

#ifdef USE_GLM_IN_MODULE
        /**
         * @brief    enable implicit cast to glm::mat3.
         */
        operator glm::mat3() {
            return glm::mat3(
                static_cast<glm::vec3>(m_Data[0]),
                static_cast<glm::vec3>(m_Data[1]),
                static_cast<glm::vec3>(m_Data[2])
            );
        }

        /**
         * @brief    enable implicit cast from glm::mat3.
         * @param[in]    other      glm:: mat3 value.
         */
        Mat3(const glm::mat3& other) {
            m_Data = { other[0], other[1], other[2] };
        }

        /*
         * @breif   enable operator = with glm::mat3.
         * @param[in]   other       glm::mat3 value.
         */
        Mat3& operator = (const glm::mat3& other) {
            m_Data = { other[0], other[1], other[2] };
            return *this;
        }
#endif

        /** < data > */
        Vec3 m_Data[3];
    };

    /**
     * @brief  this struct is used as a 4 x 4 matrix.
     */
    struct Mat4
    {
        /**
         * @brief  default constructor for Vec4.
         */
        Mat4() : m_Data{ Vec4(),Vec4(), Vec4(), Vec4() } {}

        /**
         * @brief   get vector by index.
         * @return  reference of vector at index.
         */
        Vec4& operator [] (int index) {
            EB_CORE_ASSERT(index < 4, "Index out of range.");
            return m_Data[index];
        }

        /**
         * @brief   get vector by index.
         * @return  vector at index.
         */
        Vec4 operator [] (int index) const {
            EB_CORE_ASSERT(index < 4, "Index out of range.");
            return m_Data[index];
        }

#ifdef USE_GLM_IN_MODULE
        /**
         * @brief    enable implicit cast to glm::mat4.
         */
        operator glm::mat4() {
            return glm::mat4(
                static_cast<glm::vec3>(m_Data[0]),
                static_cast<glm::vec3>(m_Data[1]),
                static_cast<glm::vec3>(m_Data[2]),
                static_cast<glm::vec3>(m_Data[3])
            );
        }

        /**
         * @brief    enable implicit cast from glm::mat4.
         * @param[in]    other      glm:: mat4 value.
         */
        Mat4(const glm::mat4& other) {
            m_Data = { other[0], other[1], other[2], other[3] };
        }

        /*
         * @breif   enable operator = with glm::mat4.
         * @param[in]   other       glm::mat4 value.
         */
        Mat4& operator = (const glm::mat4& other) {
            m_Data = { other[0], other[1], other[2], other[3] };
            return *this;
        }
#endif

        /** < data > */
        Vec4 m_Data[4];
    };
}