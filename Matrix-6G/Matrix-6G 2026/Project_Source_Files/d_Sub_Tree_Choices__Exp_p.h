#pragma once

#include <JuceHeader.h>

#include "c_ENUM_p.h"
#include "c_ID_p.h"
#include "d_Sub_Tree_Choices_b.h"

using namespace ENUM;

struct Sub_Tree_Choices_Exposed :
	public Sub_Tree_Choices_Base
{
	static ValueTree env_mode(const bool curt = false);
	static ValueTree env_trig_mode(const bool curt = false);
	static ValueTree env_lfo_1_trig(const bool curt = false);

	static ValueTree keyboard_mode(const bool curt = false);

	static ValueTree lever_ctrl(const bool curt = false);
	static ValueTree lfo_trig_mode(const bool curt = false);
	static ValueTree lfo_wave_type(const bool curt = false);

	static ValueTree input_source(Input_Choice_Type type, const bool curt = false);

	static ValueTree off_on_matrix(const bool curt = false);
	static ValueTree osc_1_key_track(const bool curt = false);
	static ValueTree osc_2_and_vcf_key_track(const bool curt = false);
	static ValueTree osc_lever_control(const bool curt = false);
	static ValueTree osc_type(const int osc_num, const bool curt = false);

	static ValueTree porta_mode(const bool curt = false);

	static ValueTree ramp_trig(const bool curt = false);

	static ValueTree signed_6_bit_int(const bool curt = false);
};
