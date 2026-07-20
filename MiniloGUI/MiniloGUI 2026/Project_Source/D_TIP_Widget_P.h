#pragma once

#include <JuceHeader.h>

#include "C_Enum_P.h"
#include "D_TIP_G.h"
#include "D_TREE_Additional_Voice_P.h"

using namespace ENUM;

struct Tip_Widget_P :
	public Tip_G
{
	static String knob_text_editor(const Slider_Display_Type display_type, Tree_Additional_Voice_P& avp);
};
