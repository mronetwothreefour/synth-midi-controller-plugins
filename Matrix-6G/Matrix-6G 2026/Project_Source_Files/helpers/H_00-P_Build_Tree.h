#pragma once

#include <JuceHeader.h>

#include "C_00-P_ID.h"
#include "C_01-P_ENUM.h"
#include "C_50-P_EP.h"

using namespace ENUM;

struct Build_Tree
{
	static ValueTree exposed_parameter(Identifier id, uint8 number, String name, 
									   Ctrl_Type ctrl, uint8 byte_index, Range_Type range,
									   Slider_Display_Type display, uint8 choice_count,
									   uint8 default_choice, int ctrl_center_x, int ctrl_center_y,
									   int ctrl_w, String description, int choice_menu_col_count,
									   int choice_menu_col_w, int choice_menu_row_count,
									   int choice_menu_first_row, int choice_menu_x,
									   int choice_menu_y, ValueTree curt_choice_names,
									   ValueTree choice_names);

	static ValueTree choice_names_osc_pitch(const bool curt);
};