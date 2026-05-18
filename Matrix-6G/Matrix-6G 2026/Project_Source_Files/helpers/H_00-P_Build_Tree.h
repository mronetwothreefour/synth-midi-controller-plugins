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
	static ValueTree exposed_parameter(Identifier id, uint8 number, String name, 
									   Ctrl_Type ctrl, uint8 byte_index, Range_Type range,
									   Slider_Display_Type display, uint8 choice_count,
									   uint8 init_choice, int ctrl_center_x, int ctrl_center_y,
									   int ctrl_w, String description, 
									   ValueTree curt_choice_names,ValueTree choice_names);

	static ValueTree choice_names_env_mode(const bool curt = false);
	static ValueTree choice_names_env_trig_mode(const bool curt = false);
	static ValueTree choice_names_env_lfo_1_trig(const bool curt = false);

	static ValueTree choice_names_keyboard_mode(const bool curt = false);

	static ValueTree choice_names_lever_ctrl(const bool curt = false);
	static ValueTree choice_names_lfo_trig_mode(const bool curt = false);
	static ValueTree choice_names_lfo_wave_type(const bool curt = false);

	static ValueTree choice_names_input_source(Input_Choice_Type type, const bool curt = false);

	static ValueTree choice_names_off_on_matrix(const bool curt = false);
	static ValueTree choice_names_osc_1_key_track(const bool curt = false);
	static ValueTree choice_names_osc_2_and_vcf_key_track(const bool curt = false);
	static ValueTree choice_names_osc_lever_control(const bool curt = false);
	static ValueTree choice_names_osc_type(const int osc_num, const bool curt = false);

	static ValueTree choice_names_porta_mode(const bool curt = false);

	static ValueTree choice_names_ramp_trig(const bool curt = false);

	static ValueTree choice_names_signed_6_bit_int(const bool curt = false);
};
