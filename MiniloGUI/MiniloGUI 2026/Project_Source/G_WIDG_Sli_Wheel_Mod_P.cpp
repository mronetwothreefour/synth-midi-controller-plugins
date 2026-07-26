#include "G_WIDG_Sli_Wheel_Mod_P.h"

#include "D_SUBTREE_Choices_Exp_P.h"

using Choices = Subtree_Choices_Exp_P;

Slider_Wheel_Mod_P::Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type) :
	Slider_Wheel_Mod_G{ u_m },
	modifying_lpf_eg_int{ ctrl_type == Ctrl_Type::knob_lpf_eg_int },
	modifying_osc_2_pitch_eg_int{ ctrl_type == Ctrl_Type::knob_osc_2_pitch_eg_int },
	modifying_osc_pitch_fine{ ctrl_type == Ctrl_Type::knob_osc_pitch_fine },
	modifying_tempo{ ctrl_type == Ctrl_Type::knob_tempo },
	non_standard_knob{ ctrl_type > Ctrl_Type::knob && ctrl_type < Ctrl_Type::switch_2_pole }
{
	if (ctrl_type >= Ctrl_Type::switch_2_pole)
	{
		setSliderStyle(SliderStyle::LinearVertical);
	}
	if (non_standard_knob) {
		ValueTree choice_tree{};
		if (modifying_osc_2_pitch_eg_int)
			choice_tree = Choices::osc_2_pitch_eg_int(true);
		if (modifying_osc_pitch_fine)
			choice_tree = Choices::osc_pitch_fine(true);
		if (choice_tree.isValid()) {
			for (int i = 0; i < choice_tree.getNumProperties(); ++i) {
				auto choice_name = choice_tree.getProperty("choice_" + String{ i }).toString();
				auto choice_val = choice_name.getIntValue();
				display_values.add(choice_val);
			}
		}
	}
}

void Slider_Wheel_Mod_P::mod_value(double incr, double& curr_sli_val) {
	if (non_standard_knob) {
		auto disp_val_index = roundToInt(curr_sli_val);
		auto curr_disp_val = display_values[disp_val_index];
		if ((modifying_osc_2_pitch_eg_int || modifying_osc_pitch_fine))
		{
			if (curr_sli_val < 5 && incr > 0) {
				curr_sli_val = 5;
				return;
			}
			if (curr_sli_val > 1019 && incr < 0) {
				curr_sli_val = 1019;
				return;
			}
		}
		if (modifying_osc_2_pitch_eg_int && curr_disp_val == 0) {
				if (incr < 0)
					curr_sli_val = 491;
				else
					curr_sli_val = 531;
				return;
		}
		if (modifying_osc_pitch_fine && curr_disp_val > -100 && curr_disp_val < 100) {
			curr_sli_val = get_best_display_value_match(disp_val_index, roundToInt(incr), -1200, 1200);
			return;
		}
	}
	curr_sli_val += incr;
}

void Slider_Wheel_Mod_P::alt_mod_value(double incr, double& curr_sli_val) {
	if (non_standard_knob) {
		if (modifying_osc_2_pitch_eg_int || modifying_osc_pitch_fine) {
			curr_sli_val = get_next_multiple_of_100(roundToInt(incr), roundToInt(curr_sli_val));
			return;
		}
	}
	mod_value(incr, curr_sli_val);
}

void Slider_Wheel_Mod_P::ctrl_mod_value(double incr, double& curr_sli_val) {
	if (non_standard_knob) {
		auto v = roundToInt(curr_sli_val);
		if (modifying_osc_2_pitch_eg_int) {
			curr_sli_val = get_best_display_value_match(v, roundToInt(incr) * 100, -4800, 4800);
			return;
		}
		if (modifying_osc_pitch_fine) {
			curr_sli_val = get_best_display_value_match(v, roundToInt(incr) * 100, -1200, 1200);
			return;
		}
	}
	curr_sli_val += incr * 100.0;
}

void Slider_Wheel_Mod_P::shift_increment_value(double incr, double& v) {
	if (non_standard_knob) {
		if (modifying_osc_2_pitch_eg_int) {
			v = get_best_display_value_match(roundToInt(v), roundToInt(incr) * 25, -4800, 4800);
			return;
		}
		if (modifying_osc_pitch_fine) {
			v = get_best_display_value_match(roundToInt(v), roundToInt(incr) * 25, -1200, 1200);
			return;
		}
	}
	v += incr * 25.0;
}

int Slider_Wheel_Mod_P::get_best_display_value_match(int v, int incr, int min, int max) {
	auto below = incr < 0;
	auto above = incr > 0;
	auto index = std::clamp(v, 0, 1023);
	if ((index == 0 && below) || (index == 1023 && above))
		return index;
	auto current_val = display_values[index];
	auto target_val = std::clamp(current_val + incr, min, max);
	auto prev_i = index;
	for (int i = index; above ? i < 1024 : i > -1; above ? ++i : --i) {
		auto val = display_values[i];
		if (val == target_val) {
			index = i;
			break;
		}
		if ((below && val < target_val) || (above && val > target_val)) {
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
	auto target_val = display_values[index];
	if (target_val % 100 == 0)
		target_val += incr;
	else {
		if ((increasing && target_val > 0) || (decreasing && target_val < 0))
			target_val += incr;
		target_val -= target_val % 100;
		index += increasing ? 1 : -1;
	}
	for (int i = index; increasing ? i < 1024 : i > -1; increasing ? ++i : --i) {
		if (display_values[i] == target_val) {
			index = i;
			break;
		}
	}
	return index;
}

