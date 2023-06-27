#pragma once

#include "gui_dock_space.h"

#include <string>

namespace EB
{
    class DockSpaceImpl
    {
    public:
        static DockSpaceImpl& instance();

        static void begin(const std::string& name ,bool& dockEnabled, bool fullScreen);
        static void end();

    protected:
        std::string m_DockName;
        bool* m_pDockEnabled;
    };
}