#pragma once

#include "G_WIDGET_Sli_Wheel_Mod_A.h"

namespace WIDGET
{

	class Slider_Wheel_Mod :
		public Slider_Wheel_Mod_A
	{
	public: const bool for_lpf_eg_int;
	public: const bool for_osc_2_pitch_eg_int;
	public: const bool for_osc_pitch_fine;
	public: const bool for_tempo;
	private: int for_voice_mode;
	public: const bool for_non_standard_knob;
	private: Array<int> display_values;

	//==============================================================================
	public: explicit Slider_Wheel_Mod(const String& param_id, UndoManager* u_m);

	public: void update_for_voice_mode(int new_mode);
	private: void mod_value(double increment, double& current_value) override;
	private: void alt_mod_value(double increment, double& current_value) override;
	private: void ctrl_mod_value(double increment, double& current_value) override;
	private: void shift_mod_value(double increment, double& current_value) override;
	private: int get_best_display_value_match(int value, int increment, int min, int max);
	public: int get_best_display_value_match(int target_value);
	private: int get_next_multiple_of_100(int increment, int value);
	};

}
