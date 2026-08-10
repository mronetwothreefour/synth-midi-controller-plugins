#pragma once

#include "D_BUILD_Choices_A.h"

struct Build_Choices :
	public Build_Choices_A
{
	static const StringArray env_mode();
	static const StringArray env_trig_mode();
	static const StringArray env_lfo_1_trig();
	static const StringArray keyboard_mode();
	static const StringArray lever_ctrl();
	static const StringArray lfo_trig_mode();
	static const StringArray lfo_wave_type();
	static const StringArray input_source(bool for_lfo);
	static const StringArray off_on_matrix();
	static const StringArray osc_1_key_track();
	static const StringArray osc_1_sync();
	static const StringArray osc_2_and_vcf_key_track();
	static const StringArray osc_lever_control();
	static const StringArray osc_type(const int osc_num);
	static const StringArray porta_mode();
	static const StringArray ramp_trig();
};