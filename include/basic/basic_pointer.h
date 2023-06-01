#pragma once

#include <memory>

/*
 * comment by zhangyuhui:  mainly because i don't export implement class while building dll,
 *                         so i choose to disable this warning.
 */
#pragma warning(disable: 4251)

namespace EB
{
    template <typename T>
    using Scoped = std::unique_ptr<T>;

    template <typename T>
    using Shared = std::shared_ptr<T>;

    /*
     * @breif     create unique pointer.
     * @template    T      class type.
     * @param[in]  args    parameters for constructor.
     * @return    unique pointer of created instance.
     */
    template <typename T, typename ... Args>
    constexpr Scoped<T> createScoped(Args&& ...args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    /*
     * @breif     create shared pointer.
     * @template    T      class type.
     * @param[in]  args    parameters for constructor.
     * @return    shared pointer of created instance.
     */
    template <typename T, typename ... Args>
    constexpr Shared<T> createShared(Args&& ...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}