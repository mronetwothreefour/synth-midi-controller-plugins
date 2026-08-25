#pragma once

#include "D_BUILD_Init_Bounds_For_A.h"

namespace BUILD
{

	struct Init_Bounds_For :
		Init_Bounds_For_A
	{
	private: static const int ctrl_row_y(const int row);
	public: static const Rectangle<int> exp_ctrl_env(const int env_num, const int row);
	public: static const Rectangle<int> exp_ctrl_env_stage(const int env_num, const int stage_num);
	public: static const Rectangle<int> exp_ctrl_lfo(const int lfo_num, const int row);
	public: static const Rectangle<int> exp_ctrl_osc(const int osc_num, const int row);
	public: static const Rectangle<int> exp_ctrl_ramp(const int ramp_num, const int row);
	public: static const Rectangle<int> exp_ctrl_osc_balance();
	public: static const Rectangle<int> exp_ctrl_porta_key_mode(const int row);
	public: static const Rectangle<int> exp_ctrl_track_input();
	public: static const Rectangle<int> exp_ctrl_track_pt(const int pt_num);
	public: static const Rectangle<int> exp_ctrl_vcf_fm(const int row);
	public: static const Rectangle<int> exp_ctrl_vcf_vca(const int row);

	public: static const Rectangle<int> mmod_ctrl_amt(const int mod_num);
	public: static const Rectangle<int> mmod_ctrl_dest(const int mod_num);
	public: static const Rectangle<int> mmod_ctrl_src(const int mod_num);
	};

}
