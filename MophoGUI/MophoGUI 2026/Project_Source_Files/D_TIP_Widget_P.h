#pragma once

#include <JuceHeader.h>

#include "C_Enum_P.h"
#include "D_TIP_B.h"

using namespace ENUM;

struct Tip_Widget_P :
	public Tip_B
{
	static String knob_text_editor(const Knob_Display_Type display_type);
};