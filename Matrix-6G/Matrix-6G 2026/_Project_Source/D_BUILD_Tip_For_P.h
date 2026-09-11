#pragma once

#include "D_BUILD_Tip_For_A.h"

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
		static std::string exp_env_amp(const unsigned int env_num);
		static std::string exp_env_lfo_1_trig(const unsigned int env_num);
		static std::string exp_env_mode(const unsigned int env_num);
		static std::string exp_env_stage(const unsigned int env_num, const unsigned int stage_num);
		static std::string exp_env_trig_mode(const unsigned int env_num);
		static std::string exp_env_velo_amt(const unsigned int env_num);

		static std::string exp_lfo_amp(const unsigned int lfo_num);
		static std::string exp_lfo_lag(const unsigned int lfo_num);
		static std::string exp_lfo_ramp_amt(const unsigned int lfo_num);
		static std::string exp_lfo_retrig_point(const unsigned int lfo_num);
		static std::string exp_lfo_sample_source(const unsigned int lfo_num);
		static std::string exp_lfo_speed(const unsigned int lfo_num);
		static std::string exp_lfo_trig_mode(const unsigned int lfo_num);
		static std::string exp_lfo_wave_type(const unsigned int lfo_num);

		static std::string exp_osc_key_track(const unsigned int osc_num);
		static std::string exp_osc_lever_control(const unsigned int osc_num);
		static std::string exp_osc_lfo_1_fm(const unsigned int osc_num);
		static std::string exp_osc_lfo_2_pwm(const unsigned int osc_num);
		static std::string exp_osc_pitch(const unsigned int osc_num);
		static std::string exp_osc_pulse_w(const unsigned int osc_num);
		static std::string exp_osc_saw_tri(const unsigned int osc_num);
		static std::string exp_osc_type(const unsigned int osc_num);

		static std::string exp_ramp_rate(const unsigned int ramp_num);
		static std::string exp_ramp_trig(const unsigned int ramp_num);

		static std::string exp_track_point(const int point_num, int init_choice);
	};

}
