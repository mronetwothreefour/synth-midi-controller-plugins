#pragma once

#include "C_ID_GUI_A.h"
#include "C_XYWH_Main_P.h"

namespace XYWH
{

	static const std::map<String, Rectangle<int>> map_bounds{
		{ ID::gui_editor, {0, 0, editor_init_w, editor_init_h}}
	};

}
