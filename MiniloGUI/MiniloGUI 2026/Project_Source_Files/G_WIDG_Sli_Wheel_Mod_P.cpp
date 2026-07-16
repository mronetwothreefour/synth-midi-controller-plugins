#include "G_WIDG_Sli_Wheel_Mod_P.h"

#include "D_SUBTREE_Choices_Exp_P.h"

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
	if (ctrl_type == Ctrl_Type::knob_osc_pitch_fine) {
		auto choice_tree = Subtree_Choices_Exp_P::osc_pitch_fine(true);
		for (int i = 0; i < choice_tree.getNumProperties(); ++i) {
			auto choice_name = choice_tree.getProperty("choice_" + String{ i }).toString();
			auto choice_val = choice_name.getIntValue();
			available_values.add(choice_val);
		}
	}
}

void Slider_Wheel_Mod_P::increment_value(double incr, double& v) {
	auto display_val = available_values[roundToInt(v)];
	if (modifying_osc_pitch_fine && display_val > -10 && display_val < 10) {
		v = get_nearest_incremented_value(roundToInt(v), roundToInt(incr), -1200, 1200);
		return;
	}
	v += incr;
}

void Slider_Wheel_Mod_P::alt_increment_value(double incr, double& v) {
	if (modifying_osc_pitch_fine) {
		v = get_next_multiple_of_100(roundToInt(incr), roundToInt(v));
		return;
	}
	increment_value(incr, v);
}

void Slider_Wheel_Mod_P::ctrl_increment_value(double incr, double& v) {
	if (modifying_osc_pitch_fine) {
		v = get_nearest_incremented_value(roundToInt(v), roundToInt(incr) * 100, -1200, 1200);
		return;
	}
	v += incr * 100.0;
}

void Slider_Wheel_Mod_P::shift_increment_value(double incr, double& v) {
	if (modifying_osc_pitch_fine) {
		v = get_nearest_incremented_value(roundToInt(v), roundToInt(incr) * 25, -1200, 1200);
		return;
	}
	v += incr * 25.0;
}

int Slider_Wheel_Mod_P::get_nearest_incremented_value(int v, int incr, int min, int max) {
	auto decreasing = incr < 0;
	auto increasing = incr > 0;
	auto index = std::clamp(v, 0, 1023);
	if ((index == 0 && decreasing) || (index == 1023 && increasing))
		return index;
	auto current_val = available_values[index];
	auto target_val = std::clamp(current_val + incr, min, max);
	auto prev_i = index;
	for (int i = index; increasing ? i < 1024 : i > -1; increasing ? ++i : --i) {
		auto val = available_values[i];
		if (val == target_val) {
			index = i;
			break;
		}
		if ((decreasing && val < target_val) || (increasing && val > target_val)) {
			index = prev_i;
			break;
		}
		prev_i = i;
	}
	return index;
}

int Slider_Wheel_Mod_P::get_next_multiple_of_100(int incr, int v) {
	auto decreasing = incr < 0;
	auto increasing = incr > 0;
	incr *= 100;
	auto index = std::clamp(v, 0, 1023);
	if ((index == 0 && decreasing) || (index == 1023 && increasing))
		return index;
	auto target_val = available_values[index];
	if (target_val % 100 == 0)
		target_val += incr;
	else {
		if ((increasing && target_val > 0) || (decreasing && target_val < 0))
			target_val += incr;
		target_val -= target_val % 100;
		index += increasing ? 1 : -1;
	}
	for (int i = index; increasing ? i < 1024 : i > -1; increasing ? ++i : --i) {
		if (available_values[i] == target_val) {
			index = i;
			break;
		}
	}
	return index;
}

