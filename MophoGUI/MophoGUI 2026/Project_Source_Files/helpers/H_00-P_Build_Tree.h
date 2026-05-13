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
									   ValueTree curt_choice_names, ValueTree choice_names);
	static ValueTree choice_names_osc_fine(const bool curt = false);
	static ValueTree choice_names_osc_shape(const bool curt = false);
};
