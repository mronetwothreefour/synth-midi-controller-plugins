#pragma once

#include <JuceHeader.h>

#include "C_00-P_ID.h"
#include "C_01-P_ENUM.h"
#include "C_50-P_EP.h"
#include "H_00-B_Build_Tree.h"

using namespace ENUM;

struct Build_Tree :
	public Base_Build_Tree
{
	static ValueTree exposed_parameter(Identifier id, String name, Ctrl_Type ctrl,
									   Knob_Display_Type display, uint8 nrpn, uint8 choice_count, 
									   uint8 init_choice, int ctrl_center_x, int ctrl_center_y,
									   int ctrl_w, int ctrl_h, String description,
									   Choice_Menu_Type choice_menu, int choice_menu_col_count, 
									   int choice_menu_col_w, int choice_menu_row_count,
									   int choice_menu_first_row, int choice_menu_x,
									   int choice_menu_y, ValueTree curt_choice_names, 
									   ValueTree choice_names);
};
