#include "G_WIDGET_Sli_Wheel_Mod_P.h"

#include "C_ENUM_P.h"
#include "C_GET_P.h"
#include "C_NAME_P.h"

using namespace ENUM;
using namespace NAME;
using namespace WIDGET;

Slider_Wheel_Mod::Slider_Wheel_Mod(const String& param_id, UndoManager* u_m) :
	Slider_Wheel_Mod_A{ param_id, u_m },
	for_lpf_eg_int{ GET::ctrl_name_for(param_id) == knob_lpf_eg_int },
	for_osc_2_pitch_eg_int{ GET::ctrl_name_for(param_id) == knob_osc_2_pitch_eg_int },
	for_osc_pitch_fine{ GET::ctrl_name_for(param_id) == knob_osc_pitch_fine },
	for_tempo{ GET::ctrl_name_for(param_id) == knob_tempo },
	for_voice_mode{ (int)Voice_Mode::none },
	for_non_standard_knob{ GET::ctrl_name_for(param_id).startsWith("knob_")}
{
	if (getName().startsWith("switch_"))
		setSliderStyle(SliderStyle::LinearVertical);
	if (for_non_standard_knob) {
		for (int i = 0; i < 1024; ++i) 
			display_values.add(choices_curt[i].getIntValue());
	}
}

void Slider_Wheel_Mod::update_for_voice_mode(int new_mode) {
	for_voice_mode = new_mode;
	display_values.clear();
	for (int i = 0; i < 1024; ++i) {
		if (new_mode == (int)Voice_Mode::poly) {
			display_values.add(i / 114);
			continue;
		}
		if (new_mode == (int)Voice_Mode::duo || new_mode == (int)Voice_Mode::unison) {
			display_values.add(std::clamp(i / 20, 0, 50));
			continue;
		}
		if (new_mode == (int)Voice_Mode::mono || new_mode == (int)Voice_Mode::sidechain) {
			display_values.add(i);
			continue;
		}
		if (new_mode == (int)Voice_Mode::chord) {
			if (i < 74) display_values.add(0);
			if (i >= 74 && i < 147) display_values.add(1);
			if (i >= 147 && i < 220) display_values.add(2);
			if (i >= 220 && i < 293) display_values.add(3);
			if (i >= 293 && i < 366) display_values.add(4);
			if (i >= 366 && i < 439) display_values.add(5);
			if (i >= 439 && i < 512) display_values.add(6);
			if (i >= 512 && i < 586) display_values.add(7);
			if (i >= 586 && i < 659) display_values.add(8);
			if (i >= 659 && i < 732) display_values.add(9);
			if (i >= 732 && i < 805) display_values.add(10);
			if (i >= 805 && i < 878) display_values.add(11);
			if (i >= 878 && i < 951) display_values.add(12);
			if (i >= 951 && i < 1024) display_values.add(13);
		}
		if (new_mode == (int)Voice_Mode::delay) {
			if (i < 86) display_values.add(0);
			if (i >= 86 && i < 171) display_values.add(1);
			if (i >= 171 && i < 256) display_values.add(2);
			if (i >= 256 && i < 342) display_values.add(3);
			if (i >= 342 && i < 427) display_values.add(4);
			if (i >= 427 && i < 512) display_values.add(5);
			if (i >= 512 && i < 598) display_values.add(6);
			if (i >= 598 && i < 683) display_values.add(7);
			if (i >= 683 && i < 768) display_values.add(8);
			if (i >= 768 && i < 854) display_values.add(9);
			if (i >= 854 && i < 939) display_values.add(10);
			if (i >= 939 && i < 1024) display_values.add(11);
		}
		if (new_mode == (int)Voice_Mode::arp) {
			if (i < 79) display_values.add(0);
			if (i >= 79 && i < 158) display_values.add(1);
			if (i >= 158 && i < 237) display_values.add(2);
			if (i >= 237 && i < 316) display_values.add(3);
			if (i >= 316 && i < 394) display_values.add(4);
			if (i >= 394 && i < 473) display_values.add(5);
			if (i >= 473 && i < 552) display_values.add(6);
			if (i >= 552 && i < 631) display_values.add(7);
			if (i >= 631 && i < 709) display_values.add(8);
			if (i >= 709 && i < 788) display_values.add(9);
			if (i >= 788 && i < 867) display_values.add(10);
			if (i >= 867 && i < 946) display_values.add(11);
			if (i >= 946 && i < 1024) display_values.add(12);
		}
	}
}

void Slider_Wheel_Mod::mod_value(double incr, double& curr_sli_val) {
	if (for_non_standard_knob) {
		auto disp_val_index = roundToInt(curr_sli_val);
		auto curr_disp_val = display_values[disp_val_index];
		if ((for_lpf_eg_int))
		{
			if (curr_sli_val < 12 && incr > 0) {
				curr_sli_val = 12;
				return;
			}
			if (curr_sli_val > 1012 && incr < 0) {
				curr_sli_val = 1012;
				return;
			}
		}
		if (for_osc_2_pitch_eg_int || for_osc_pitch_fine)
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
		if (for_osc_2_pitch_eg_int && curr_disp_val == 0) {
				if (incr < 0)
					curr_sli_val = 491;
				else
					curr_sli_val = 531;
				return;
		}
		if (for_lpf_eg_int) {
			curr_sli_val = get_best_display_value_match(disp_val_index, roundToInt(incr), -100, 100);
			return;
		}
		if (for_osc_pitch_fine && curr_disp_val > -100 && curr_disp_val < 100) {
			curr_sli_val = get_best_display_value_match(disp_val_index, roundToInt(incr), -1200, 1200);
			return;
		}
		if (for_voice_mode > (int)Voice_Mode::none) {
			curr_sli_val = get_best_display_value_match(disp_val_index, roundToInt(incr), 0, 1023);
			return;
		}
	}
	curr_sli_val += incr;
}

void Slider_Wheel_Mod::alt_mod_value(double incr, double& curr_val) {
	if (for_osc_2_pitch_eg_int || for_osc_pitch_fine) {
		curr_val = get_next_multiple_of_100(roundToInt(incr), roundToInt(curr_val));
		return;
	}
	mod_value(incr, curr_val);
}

void Slider_Wheel_Mod::ctrl_mod_value(double incr, double& curr_val) {
	if (for_non_standard_knob) {
		auto v = roundToInt(curr_val);
		if (for_osc_2_pitch_eg_int) {
			curr_val = get_best_display_value_match(v, roundToInt(incr) * 100, -4800, 4800);
			return;
		}
		if (for_osc_pitch_fine) {
			curr_val = get_best_display_value_match(v, roundToInt(incr) * 100, -1200, 1200);
			return;
		}
	}
	curr_val += incr * 100.0;
}

void Slider_Wheel_Mod::shift_mod_value(double incr, double& curr_val) {
	if (for_non_standard_knob) {
		auto v = roundToInt(curr_val);
		auto i = roundToInt(incr);
		if (for_lpf_eg_int) {
			v = get_best_display_value_match(v, i * 5, -100, 100);
			return;
		}
		if (for_osc_2_pitch_eg_int) {
			v = get_best_display_value_match(v, i * 25, -4800, 4800);
			return;
		}
		if (for_osc_pitch_fine) {
			v = get_best_display_value_match(v, i * 25, -1200, 1200);
			return;
		}
		if (for_voice_mode > (int)Voice_Mode::none) {
			if (for_voice_mode == (int)Voice_Mode::duo || for_voice_mode == (int)Voice_Mode::unison) {
				v = get_best_display_value_match(v, i * 5, 0, 1023);
				return;
			}
			if (for_voice_mode == (int)Voice_Mode::mono || for_voice_mode == (int)Voice_Mode::sidechain) {
				v = get_best_display_value_match(v, i * 25, 0, 1023);
				return;
			}
			v = get_best_display_value_match(v, i, 0, 1023);
			return;
		}
	}
	curr_val += incr * 25.0;
}

int Slider_Wheel_Mod::get_best_display_value_match(int v, int incr, int min, int max) {
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

int Slider_Wheel_Mod::get_best_display_value_match(int target) {
	auto l = 0;
	auto r = 1023;
	while (l < r) {
		if (abs(display_values[l] - target)
			<= abs(display_values[r] - target)) {
			r--;
		}
		else
			l++;
	}
	return l;
}

int Slider_Wheel_Mod::get_next_multiple_of_100(int incr, int v) {
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

