#pragma once

#include "D_BUILD_Choices_For_A.h"

namespace BUILD
{

	struct Choices_For :
		public Choices_For_A
	{
		static const StringArray exp_env_mode();
		static const StringArray exp_env_trig_mode();
		static const StringArray exp_env_lfo_1_trig();
		static const StringArray exp_keyboard_mode();
		static const StringArray exp_lever_ctrl();
		static const StringArray exp_lfo_trig_mode();
		static const StringArray exp_lfo_wave_type();
		static const StringArray exp_osc_1_key_track();
		static const StringArray exp_osc_1_sync();
		static const StringArray exp_osc_2_and_vcf_key_track();
		static const StringArray exp_osc_lever_control();
		static const StringArray exp_osc_type(const int osc_num);
		static const StringArray exp_porta_mode();
		static const StringArray exp_ramp_trig();

		static const StringArray input_source(const bool for_lfo = false, const bool for_mmod = false);
	
		static const StringArray mmod_dest();
	
		static const StringArray off_on_p();
	};

}
