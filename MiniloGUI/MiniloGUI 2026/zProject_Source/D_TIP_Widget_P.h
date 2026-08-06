#pragma once

#include "C_Enum_P.h"
#include "D_TIP_G.h"

using namespace ENUM;

class Tree_Aux_Voice_P;

struct Tip_Widget_P :
	public Tip_G
{
	static String knob_text_editor(const Slider_Display_Type display_type, Tree_Aux_Voice_P& avp);
};
