#pragma once

#include "G_WIDGET_Sli_Wheel_Mod_A.h"

namespace WIDGET
{

	class Slider_Wheel_Mod :
		public Slider_Wheel_Mod_A
	{
	public: const bool for_lfo_rate;
	public: const bool for_lpf_eg_int;
	public: const bool for_osc_2_pitch_eg_int;
	public: const bool for_osc_pitch_fine;
	private: const bool for_voice_mode;
	public: const bool for_signed_range;
	private: Array<int> int_choices;

	//==============================================================================
	public: explicit Slider_Wheel_Mod(const std::string& param_id, Value param_value, Data_Hub* hub);

	public: void update_for_voice_mode(int new_mode);
	private: void mod_value(bool increasing, double& current_value) override;
	private: void alt_mod_value(bool increasing, double& current_value) override;
	private: void ctrl_mod_value(bool increasing, double& current_value) override;
	private: void shift_mod_value(bool increasing, double& current_value) override;
	public: int get_choice_that_best_matches(int target);
	private: int get_choice_that_best_matches(int current_choice_index, int increment, int min, int max);
	private: int get_next_multiple_of_100(bool increasing, int value);
	};

}
