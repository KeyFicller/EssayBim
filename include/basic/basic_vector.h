#pragma once

#include "basic_assert.h"

#ifdef USE_GLM_IN_MODULE
#include "glm/glm.hpp"
#endif

#ifdef USE_IMGUI_IN_MODULE

#endif

/*
 * comment by zhangyuhui:  latter i may change this from int[] to individual values.
 */

namespace EB
{
    /*
     * @brief  this struct is used a 2 component vector.
     */
    struct Vec2
    {
        /*
         * @brief  default constructor for Vec2.
         */
        Vec2() : m_Data{ 0.0, 0.0 } {}

        /*
         * @brief  constructor for Vec2.
         */
        Vec2(float x, float y) : m_Data{ x, y } {}

        /*
         * @brief   get first component.
         * @return  reference of first component.
         */
        float& x() { return m_Data[0]; }

        /*
         * @brief   get second component.
         * @return  reference of second component.
         */
        float& y() { return m_Data[1]; }

        /*
         * @brief   get first component.
         * @return  first component.
         */
        float x() const { return m_Data[0]; }

        /*
         * @brief   get second component.
         * @return  second component.
         */
        float y() const { return m_Data[1]; }

        /*
         * @brief   get component by index.
         * @return  reference of component at index.
         */
        float& operator [] (int index) {
            EB_CORE_ASSERT(index < 2, "Index out of range.");
            return m_Data[index];
        }

        /*
         * @brief   get component by index.
         * @return  component at index.
         */
        float operator [] (int index) const {
            EB_CORE_ASSERT(index < 2, "Index out of range.");
            return m_Data[index];
        }

        /* < data > */
        float m_Data[2] = { 0.0 };
    };

    /*
     * @brief  this struct is used a 3 component vector.
     */
    struct Vec3
    {
        /*
         * @brief  default constructor for Vec2.
         */
        Vec3() : m_Data{ 0.0, 0.0, 0.0 } {}

        /*
         * @brief  constructor for Vec2.
         */
        Vec3(float x, float y, float z) : m_Data{ x, y, z } {}

        /*
         * @brief   get first component.
         * @return  reference of first component.
         */
        float& x() { return m_Data[0]; }

        /*
         * @brief   get second component.
         * @return  reference of second component.
         */
        float& y() { return m_Data[1]; }

        /*
         * @brief   get third component.
         * @return  reference of third component.
         */
        float& z() { return m_Data[2]; }

        /*
         * @brief   get first component.
         * @return  first component.
         */
        float x() const { return m_Data[0]; }

        /*
         * @brief   get second component.
         * @return  second component.
         */
        float y() const { return m_Data[1]; }

        /*
         * @brief   get third component.
         * @return  third component.
         */
        float z() const { return m_Data[2]; }

        /*
         * @brief   get component by index.
         * @return  reference of component at index.
         */
        float& operator [] (int index) {
            EB_CORE_ASSERT(index < 3, "Index out of range.");
            return m_Data[index];
        }

        /*
         * @brief   get component by index.
         * @return  component at index.
         */
        float operator [] (int index) const {
            EB_CORE_ASSERT(index < 3, "Index out of range.");
            return m_Data[index];
        }

#ifdef USE_GLM_IN_MODULE
        /*
         * @brief    enable implicit cast to glm::vec3.s
         */
        operator glm::vec3() {
            return glm::vec3(m_Data[0], m_Data[1], m_Data[2]);
        }
#endif

        /* < data > */
        float m_Data[3] = { 0.0 };
    };

    /*
     * @brief  this struct is used a 4 component vector.
     */
    struct Vec4
    {
        /*
         * @brief  default constructor for Vec4.
         */
        Vec4() : m_Data{ 0.0, 0.0, 0.0, 0.0 } {}

        /*
         * @brief  constructor for Vec4.
         */
        Vec4(float x, float y, float z, float w) : m_Data{ x, y, z, w } {}

        /*
         * @brief   get first component.
         * @return  reference of first component.
         */
        float& x() { return m_Data[0]; }

        /*
         * @brief   get second component.
         * @return  reference of second component.
         */
        float& y() { return m_Data[1]; }

        /*
         * @brief   get third component.
         * @return  reference of third component.
         */
        float& z() { return m_Data[2]; }

        /*
         * @brief   get fourth component.
         * @return  reference of fourth component.
         */
        float& w() { return m_Data[3]; }

        /*
         * @brief   get first component.
         * @return  first component.
         */
        float x() const { return m_Data[0]; }

        /*
         * @brief   get second component.
         * @return  second component.
         */
        float y() const { return m_Data[1]; }

        /*
         * @brief   get third component.
         * @return  third component.
         */
        float z() const { return m_Data[2]; }

        /*
         * @brief   get fourth component.
         * @return  fourth component.
         */
        float w() const { return m_Data[3]; }

        /*
         * @brief   get component by index.
         * @return  reference of component at index.
         */
        float& operator [] (int index) {
            EB_CORE_ASSERT(index < 4, "Index out of range.");
            return m_Data[index];
        }

        /*
         * @brief   get component by index.
         * @return  component at index.
         */
        float operator [] (int index) const {
            EB_CORE_ASSERT(index < 4, "Index out of range.");
            return m_Data[index];
        }

#ifdef USE_GLM_IN_MODULE
        /*
         * @brief    enable implicit cast to glm::vec4.
         */
        operator glm::vec4() {
            return glm::vec4(m_Data[0], m_Data[1], m_Data[2], m_Data[3]);
        }
#endif

        /* < data > */
        float m_Data[4] = { 0.0 };
    };
}