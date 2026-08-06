#pragma once

#include <JuceHeader.h>

#include "C_ENUM_P.h"

using namespace ENUM;

struct Subtree_Exposed_Info_P
{
	static ValueTree build(Exp_Param id, int number, String name, Ctrl_Type ctrl,
						   int byte_index, Range_Type range, Slider_Display_Type display,
						   int choice_count, int init_choice, int ctrl_cntr_x, int ctrl_cntr_y,
						   int ctrl_w, String tip, ValueTree choices_curt, ValueTree choices);
};