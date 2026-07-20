#pragma once

#include <JuceHeader.h>

#include "C_ENUM_p.h"
#include "D_SUBTREE_Choices_G.h"

using namespace ENUM;

struct Subtree_Choices_Exp_P :
	public Subtree_Choices_G
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
	static ValueTree osc_1_sync(const bool curt = false);
	static ValueTree osc_2_and_vcf_key_track(const bool curt = false);
	static ValueTree osc_lever_control(const bool curt = false);
	static ValueTree osc_type(const int osc_num, const bool curt = false);

	static ValueTree porta_mode(const bool curt = false);

	static ValueTree ramp_trig(const bool curt = false);

	static ValueTree signed_6_bit_int(const bool curt = false);
};
