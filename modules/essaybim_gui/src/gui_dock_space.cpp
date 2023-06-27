#include "gui_dock_space.h"

#include "gui_dock_space_impl.h"

namespace EB
{

    void DockSpace::begin(const std::string& name, bool& dockEnabled, bool fullScreen)
    {
        DockSpaceImpl::begin(name, dockEnabled, fullScreen);
    }

    void DockSpace::end()
    {
        DockSpaceImpl::end();
    }

}