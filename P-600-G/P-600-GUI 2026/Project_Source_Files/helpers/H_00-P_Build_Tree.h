#pragma once

#include <JuceHeader.h>

#include "c_ID_p.h"
#include "c_ENUM_p.h"
#include "c_EXP_p.h"
#include "H_00-B_Build_Tree.h"

using namespace ENUM;

struct Build_Tree :
	public Base_Build_Tree
{
	static ValueTree exposed_parameter(Identifier id, String name, Ctrl_Type ctrl, 
									   int first_nybble_index, int first_bit_index,
									   int bit_count, int choice_count, 
									   int init_choice,int ctrl_center_x, int ctrl_center_y, 
									   int ctrl_w, int ctrl_h, String tip,
									   ValueTree curt_choice_names, ValueTree choice_names);

	static ValueTree choice_names_filter_key_track(const bool curt = false);
	static ValueTree choice_names_lfo_shape(const bool curt = false);
};
