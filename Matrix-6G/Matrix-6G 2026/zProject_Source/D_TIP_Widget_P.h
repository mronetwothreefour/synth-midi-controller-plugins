#pragma once

#include "C_Enum_P.h"
#include "D_TIP_G.h"

using namespace ENUM;

struct Tip_Widget_P :
	public Tip_G
{
	static String knob_text_editor(const Slider_Display_Type display_type, bool u_7_bit);

	static String matrix_mod_cbox(bool for_source);
	static String matrix_mod_knob_amt();
};