group "modules"

include "essaybim_basic"
include "essaybim_gui"

group "modules/essaybim_graphics"
include "essaybim_renderer"
group ""

group "modules/essaybim_appcore"
include "essaybim_command"
include "essaybim_editor"
include "essaybim_event"
include "essaybim_window"
include "essaybim_document"
group ""

group "modules/essaybim_modeling"
include "essaybim_geometry"
include "essaybim_topological"
include "essaybim_database"
group ""

group ""