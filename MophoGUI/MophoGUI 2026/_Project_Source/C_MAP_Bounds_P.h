#pragma once

#include "C_ID_A.h"
#include "C_XYWH_P.h"

using namespace XYWH;

namespace MAP
{

	static const std::unordered_map<String, Rectangle<int>> bounds{
		{ ID::gui_editor, {0, 0, editor_init_w, editor_init_h}}
	};

}
