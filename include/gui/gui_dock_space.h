#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <string>

namespace EB
{
    /**
     * @brief  this class defines dock space.
     */
    class EB_EXPORT DockSpace
    {
    public:
        /**
         * @brief   begin dock space.
         * @param[in]   name              name of dock space.
         * @param[in]   dockEnabled       whether dock is enabled.
         * @param[in]   fullScreen        is dock space full screen.
         */
        static void begin(const std::string& name, bool& dockEnabled, bool fullScreen);

        /**
         * @brief  end dock space.
         */
        static void end();
    };
}