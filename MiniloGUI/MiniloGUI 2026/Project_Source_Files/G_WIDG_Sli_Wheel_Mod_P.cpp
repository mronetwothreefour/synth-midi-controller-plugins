#include "G_WIDG_Sli_Wheel_Mod_P.h"

Slider_Wheel_Mod_P::Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type) :
	Slider_Wheel_Mod_B{ u_m },
	modifying_osc_pitch_fine{ ctrl_type == Ctrl_Type::knob_osc_pitch_fine },
	modifying_osc_2_pitch_eg_int{ ctrl_type == Ctrl_Type::knob_osc_2_pitch_eg_int },
	modifying_tempo{ ctrl_type == Ctrl_Type::knob_tempo }
{
	if (ctrl_type == Ctrl_Type::switch_2_pole ||
		ctrl_type == Ctrl_Type::switch_3_pole ||
		ctrl_type == Ctrl_Type::switch_lpf_type ||
		ctrl_type == Ctrl_Type::switch_osc_octave)
	{
		setSliderStyle(SliderStyle::LinearVertical);
	}
}

void Slider_Wheel_Mod_P::alt_increment_value(double increment, double& value) {
	if (modifying_osc_pitch_fine || modifying_osc_2_pitch_eg_int) {
		if (roundToInt(value) % 100 != 0) {
			value = increment < 0.0 ? floor(value / 100.0) : ceil(value / 100.0);
			value *= 100.0;
			increment += increment < 0.0 ? 1.0 : -1.0;
		}
		value += increment * 100.0;
		return;
	}
	increment_value(increment, value);
}

void Slider_Wheel_Mod_P::ctrl_increment_value(double increment, double& value) {
	if (modifying_osc_pitch_fine || modifying_osc_2_pitch_eg_int || modifying_tempo) {
		value += increment * 100.0;
		return;
	}
	increment_value(increment, value);
}

