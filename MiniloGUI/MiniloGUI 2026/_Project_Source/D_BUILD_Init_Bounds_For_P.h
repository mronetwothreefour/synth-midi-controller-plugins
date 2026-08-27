#pragma once

#include "D_BUILD_Init_Bounds_For_A.h"

namespace BUILD
{

	struct Init_Bounds_For :
		Init_Bounds_For_A
	{
	private: static const Rectangle<int> ctrl_bounds(const int cntr_x, const int cntr_y,
													 const bool knob = false);

	public: static const Rectangle<int> avp_ctrl_amp_mod_and_level(const bool amp_mod = false);
	public: static const Rectangle<int> avp_ctrl_flex_sli_knob(const int knob_num);
	public: static const Rectangle<int> avp_ctrl_flex_sli_target();
	public: static const Rectangle<int> avp_ctrl_keyboard_octave();
	public: static const Rectangle<int> avp_ctrl_lfo_switch(const int switch_num);
	public: static const Rectangle<int> avp_ctrl_microtune_scale();
	public: static const Rectangle<int> avp_ctrl_porta_switch(const bool mode = false);
	public: static const Rectangle<int> avp_ctrl_porta_time();
	public: static const Rectangle<int> avp_ctrl_tuning_knob(const int knob_num);
	public: static const Rectangle<int> avp_ctrl_voice_mode_btn(const int btn_num);

	public: static const Rectangle<int> exp_ctrl_delay_knob(const int knob_num);
	public: static const Rectangle<int> exp_ctrl_delay_routing();
	public: static const Rectangle<int> exp_ctrl_env_stage(const int stage, const bool vca = false);
	public: static const Rectangle<int> exp_ctrl_lfo_knob(const bool rate = false);
	public: static const Rectangle<int> exp_ctrl_lfo_switch(const bool wave = false);
	public: static const Rectangle<int> exp_ctrl_lfo_target();
	public: static const Rectangle<int> exp_ctrl_lpf_freq();
	public: static const Rectangle<int> exp_ctrl_lpf_knob(const bool reso = false);
	public: static const Rectangle<int> exp_ctrl_lpf_switch(const bool key_track = false);
	public: static const Rectangle<int> exp_ctrl_lpf_type();
	public: static const Rectangle<int> exp_ctrl_mixer_knob(const int knob_num);
	public: static const Rectangle<int> exp_ctrl_osc_2_mod_knob(const bool x_mod = false);
	public: static const Rectangle<int> exp_ctrl_osc_2_mod_switch(const bool sync = false);
	public: static const Rectangle<int> exp_ctrl_osc_knob(const bool osc_1, const bool pitch_fine);
	public: static const Rectangle<int> exp_ctrl_osc_switch(const bool osc_1, const bool octave);
	public: static const Rectangle<int> exp_ctrl_voice_mode_depth();
	};

}