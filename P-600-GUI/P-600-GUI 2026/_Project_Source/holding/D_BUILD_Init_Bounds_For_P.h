#pragma once

#include "D_BUILD_Init_Bounds_For_A.h"

namespace BUILD
{

	struct Init_Bounds_For :
		Init_Bounds_For_A
	{
	private: static const Rectangle<int> exp_ctrl(const int cntr_x, const int cntr_y);
	public: static const Rectangle<int> exp_ctrl_env_stage(const int stage, const bool filter = false);
	public: static const Rectangle<int> exp_ctrl_filter_key_track();
	public: static const Rectangle<int> exp_ctrl_filter_knob(const int col_num);
	public: static const Rectangle<int> exp_ctrl_lfo_knob(const bool freq = false);
	public: static const Rectangle<int> exp_ctrl_lfo_switch(const int switch_num);
	public: static const Rectangle<int> exp_ctrl_osc_a_sync();
	public: static const Rectangle<int> exp_ctrl_osc_b_fine();
	public: static const Rectangle<int> exp_ctrl_poly_mod(const int col_num);
	public: static const Rectangle<int> exp_ctrl_mixer_glide(const bool mixer = false);
	public: static const Rectangle<int> exp_ctrl_osc_pitch(const bool osc_a = false);
	public: static const Rectangle<int> exp_ctrl_osc_pulse_w(const bool osc_a = false);
	public: static const Rectangle<int> exp_ctrl_osc_shape(const int shape, const bool osc_a = false);
	public: static const Rectangle<int> exp_ctrl_unison_track();
	};

}