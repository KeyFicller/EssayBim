group "modules"

include "essaybim_basic"
include "essaybim_gui"
include "essaybim_geometry"

group "modules/essaybim_graphics"
include "essaybim_renderer"
group ""

group "modules/essaybim_appcore"
include "essaybim_event"
include "essaybim_window"
include "essaybim_document"
group ""

group ""