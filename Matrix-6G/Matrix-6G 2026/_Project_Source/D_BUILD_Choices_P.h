#pragma once

#include "D_BUILD_Choices_A.h"

struct Build_Choices :
	public Build_Choices_A
{
	static StringArray env_mode();
	static StringArray env_trig_mode();
	static StringArray env_lfo_1_trig();
	static StringArray keyboard_mode();
	static StringArray lever_ctrl();
	static StringArray lfo_trig_mode();
	static StringArray lfo_wave_type();
	static StringArray input_source(bool for_lfo);
	static StringArray off_on_matrix();
	static StringArray osc_1_key_track();
	static StringArray osc_1_sync();
	static StringArray osc_2_and_vcf_key_track();
	static StringArray osc_lever_control();
	static StringArray osc_type(const int osc_num);
	static StringArray porta_mode();
	static StringArray ramp_trig();
};