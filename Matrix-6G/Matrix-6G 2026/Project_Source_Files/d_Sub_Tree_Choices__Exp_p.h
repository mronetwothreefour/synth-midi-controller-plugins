#pragma once

#include <JuceHeader.h>

#include "c_ID_p.h"
#include "c_ENUM_p.h"
#include "c_EXP_p.h"
#include "d_Sub_Tree_Choices_b.h"

using namespace ENUM;

struct Build_Tree :
	public Sub_Tree_Choices_Base
{
	static ValueTree exposed_parameter(Identifier id, int number, String name, 
									   Ctrl_Type ctrl, int byte_index, Range_Type range,
									   Slider_Display_Type display, int choice_count,
									   int init_choice, int ctrl_center_x, int ctrl_center_y,
									   int ctrl_w, String tip, 
									   ValueTree curt_choice_names,ValueTree choice_names);

	static ValueTree choice_names_env_mode(const bool curt = false);
	static ValueTree choice_names_env_trig_mode(const bool curt = false);
	static ValueTree choice_names_env_lfo_1_trig(const bool curt = false);

	static ValueTree choice_names_keyboard_mode(const bool curt = false);

	static ValueTree choice_names_lever_ctrl(const bool curt = false);
	static ValueTree choice_names_lfo_trig_mode(const bool curt = false);
	static ValueTree choice_names_lfo_wave_type(const bool curt = false);

	static ValueTree choice_names_input_source(Input_Choice_Type type, const bool curt = false);

	static ValueTree off_on_matrix(const bool curt = false);
	static ValueTree choice_names_osc_1_key_track(const bool curt = false);
	static ValueTree choice_names_osc_2_and_vcf_key_track(const bool curt = false);
	static ValueTree choice_names_osc_lever_control(const bool curt = false);
	static ValueTree choice_names_osc_type(const int osc_num, const bool curt = false);

	static ValueTree choice_names_porta_mode(const bool curt = false);

	static ValueTree choice_names_ramp_trig(const bool curt = false);

	static ValueTree choice_names_signed_6_bit_int(const bool curt = false);
};
