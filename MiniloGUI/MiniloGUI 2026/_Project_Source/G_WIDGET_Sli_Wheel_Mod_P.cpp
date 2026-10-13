#include "G_WIDGET_Sli_Wheel_Mod_P.h"

#include "C_ENUM_P.h"
#include "C_ID_Main_P.h"

using namespace ENUM;
using namespace WIDGET;

Slider_Wheel_Mod::Slider_Wheel_Mod(const std::string& param_id, Value param_value, Data_Hub* hub) :
	Slider_Wheel_Mod_A{ param_id, param_value, hub },
	for_lpf_eg_int{ param_id == ID::exp_lpf_eg_int },
	for_osc_2_pitch_eg_int{ param_id == ID::exp_osc_2_pitch_eg_int },
	for_osc_pitch_fine{  param_id.ends_with("_pitch_fine") },
	for_voice_mode{ param_id == ID::exp_voice_mode_depth },
	for_signed_range{ for_lpf_eg_int || for_osc_2_pitch_eg_int || for_osc_pitch_fine }
{
	if (getName().startsWith("ctr_sli_sw_"))
		setSliderStyle(SliderStyle::LinearVertical);
	if (for_signed_range) {
		for (int i = 0; i < 1024; ++i)
			int_choices.add(choices_curt[i].getIntValue());
	}
	if (for_voice_mode)
		update_for_voice_mode(avp.voice_mode());
}

void Slider_Wheel_Mod::update_for_voice_mode(int new_mode) {
	int_choices.clear();
	for (int i = 0; i < 1024; ++i) {
		if (new_mode == (int)Voice_Mode::poly) {
			int_choices.add(i / 114);
			continue;
		}
		if (new_mode == (int)Voice_Mode::duo || new_mode == (int)Voice_Mode::unison) {
			int_choices.add(std::clamp(i / 20, 0, 50));
			continue;
		}
		if (new_mode == (int)Voice_Mode::mono || new_mode == (int)Voice_Mode::sidechain) {
			int_choices.add(i);
			continue;
		}
		if (new_mode == (int)Voice_Mode::chord) {
			if (i < 74) int_choices.add(0);
			if (i >= 74 && i < 147) int_choices.add(1);
			if (i >= 147 && i < 220) int_choices.add(2);
			if (i >= 220 && i < 293) int_choices.add(3);
			if (i >= 293 && i < 366) int_choices.add(4);
			if (i >= 366 && i < 439) int_choices.add(5);
			if (i >= 439 && i < 512) int_choices.add(6);
			if (i >= 512 && i < 586) int_choices.add(7);
			if (i >= 586 && i < 659) int_choices.add(8);
			if (i >= 659 && i < 732) int_choices.add(9);
			if (i >= 732 && i < 805) int_choices.add(10);
			if (i >= 805 && i < 878) int_choices.add(11);
			if (i >= 878 && i < 951) int_choices.add(12);
			if (i >= 951 && i < 1024) int_choices.add(13);
		}
		if (new_mode == (int)Voice_Mode::delay) {
			if (i < 86) int_choices.add(0);
			if (i >= 86 && i < 171) int_choices.add(1);
			if (i >= 171 && i < 256) int_choices.add(2);
			if (i >= 256 && i < 342) int_choices.add(3);
			if (i >= 342 && i < 427) int_choices.add(4);
			if (i >= 427 && i < 512) int_choices.add(5);
			if (i >= 512 && i < 598) int_choices.add(6);
			if (i >= 598 && i < 683) int_choices.add(7);
			if (i >= 683 && i < 768) int_choices.add(8);
			if (i >= 768 && i < 854) int_choices.add(9);
			if (i >= 854 && i < 939) int_choices.add(10);
			if (i >= 939 && i < 1024) int_choices.add(11);
		}
		if (new_mode == (int)Voice_Mode::arp) {
			if (i < 79) int_choices.add(0);
			if (i >= 79 && i < 158) int_choices.add(1);
			if (i >= 158 && i < 237) int_choices.add(2);
			if (i >= 237 && i < 316) int_choices.add(3);
			if (i >= 316 && i < 394) int_choices.add(4);
			if (i >= 394 && i < 473) int_choices.add(5);
			if (i >= 473 && i < 552) int_choices.add(6);
			if (i >= 552 && i < 631) int_choices.add(7);
			if (i >= 631 && i < 709) int_choices.add(8);
			if (i >= 709 && i < 788) int_choices.add(9);
			if (i >= 788 && i < 867) int_choices.add(10);
			if (i >= 867 && i < 946) int_choices.add(11);
			if (i >= 946 && i < 1024) int_choices.add(12);
		}
	}
}

void Slider_Wheel_Mod::mod_value(bool increasing, double& curr_sli_val) {
	if (for_signed_range || for_voice_mode) {
		auto curr_index = roundToInt(curr_sli_val);
		auto curr_int = int_choices[curr_index];
		auto increment = increasing ? 1 : -1;
		if (for_signed_range && curr_int + increment == 0) {
			curr_sli_val = 512;
			return;
		}
		if ((for_lpf_eg_int)) {
			if (curr_index < 14 && increasing) {
				curr_sli_val = 14;
				return;
			}
			if (curr_int == 0) {
				if (increasing)
					curr_sli_val = 541;
				else
					curr_sli_val = 485;
				return;
			}
			if (curr_index > 1011 && !increasing) {
				curr_sli_val = 1011;
				return;
			}
			curr_sli_val = get_choice_that_best_matches(curr_int + increment);
			return;
		}
		if (for_osc_2_pitch_eg_int || for_osc_pitch_fine) {
			if (curr_index < 5 && increasing) {
				curr_sli_val = 5;
				return;
			}
			if (curr_int == 0) {
					if (increasing)
						curr_sli_val = for_osc_2_pitch_eg_int ? 531 : 533;
					else
						curr_sli_val = for_osc_2_pitch_eg_int ? 491 : 489;
					return;
			}
			if (curr_index > 1019 && !increasing) {
				curr_sli_val = 1019;
				return;
			}
		}
		if (for_osc_pitch_fine && curr_int > -100 && curr_int < 100) {
			curr_sli_val = get_choice_that_best_matches(curr_index, increment, -1200, 1200);
			return;
		}
		if (for_voice_mode) {
			curr_sli_val = get_choice_that_best_matches(curr_int + increment);
			return;
		}
	}
	curr_sli_val += increasing ? 1.0 : -1.0;
}

void Slider_Wheel_Mod::alt_mod_value(bool increasing, double& curr_sli_val) {
	if (for_osc_2_pitch_eg_int || for_osc_pitch_fine) {
		curr_sli_val = get_next_multiple_of_100(increasing, roundToInt(curr_sli_val));
		return;
	}
	mod_value(increasing, curr_sli_val);
}

void Slider_Wheel_Mod::ctrl_mod_value(bool increasing, double& curr_val) {
	auto increment = increasing ? 100 : -100;
	if (for_signed_range) {
		auto curr_index = roundToInt(curr_val);
		if (for_lpf_eg_int) {
			curr_val = get_choice_that_best_matches(curr_index, increment / 10, -100, 100);
			return;
		}
		if (for_osc_2_pitch_eg_int) {
			curr_val = get_choice_that_best_matches(curr_index, increment, -4800, 4800);
			return;
		}
		if (for_osc_pitch_fine) {
			curr_val = get_choice_that_best_matches(curr_index, increment, -1200, 1200);
			return;
		}
	}
	curr_val += increment;
}

void Slider_Wheel_Mod::shift_mod_value(bool increasing, double& curr_val) {
	if (for_signed_range || for_voice_mode) {
		auto increment = increasing ? 1 : -1;
		auto curr_index = roundToInt(curr_val);
		if (for_lpf_eg_int) {
			curr_val = get_choice_that_best_matches(curr_index, increment * 5, -100, 100);
			return;
		}
		if (for_osc_2_pitch_eg_int) {
			curr_val = get_choice_that_best_matches(curr_index, increment * 25, -4800, 4800);
			return;
		}
		if (for_osc_pitch_fine) {
			curr_val = get_choice_that_best_matches(curr_index, increment * 25, -1200, 1200);
			return;
		}
		if (for_voice_mode) {
			auto mode = avp.voice_mode();
			if (mode == (int)Voice_Mode::duo || mode == (int)Voice_Mode::unison) {
				curr_val = get_choice_that_best_matches(curr_index, increment * 5, 0, 1023);
				return;
			}
			if (mode == (int)Voice_Mode::mono || mode == (int)Voice_Mode::sidechain) {
				curr_val = get_choice_that_best_matches(curr_index, increment * 25, 0, 1023);
				return;
			}
			curr_val = get_choice_that_best_matches(curr_index, increment, 0, 1023);
			return;
		}
	}
	curr_val += increasing ? 25.0 : -25.0;
}

int Slider_Wheel_Mod::get_choice_that_best_matches(int target) {
	if (for_signed_range && target == 0) 
			return 512;
	auto l = 0;
	auto r = 1023;
	while (l < r) {
		if (abs(int_choices[l] - target) <= abs(int_choices[r] - target)) {
			r--;
		}
		else
			l++;
	}
	return l;
}

int Slider_Wheel_Mod::get_choice_that_best_matches(int curr_index, int increment, int min, int max) {
	auto decreasing = increment < 0;
	auto increasing = increment > 0;
	if ((curr_index == 0 && decreasing) || (curr_index == 1023 && increasing))
		return curr_index;
	auto current_int = int_choices[curr_index];
	auto target_int = std::clamp(current_int + increment, min, max);
	if (for_signed_range && target_int == 0)
		return 512;
	auto rtn_index = curr_index;
	auto prev_index = curr_index;
	for (int i = curr_index; increasing ? i < 1024 : i > -1; increasing ? ++i : --i) {
		auto try_int = int_choices[i];
		if (try_int == target_int) {
			rtn_index = i;
			break;
		}
		if ((decreasing && try_int < target_int) || (increasing && try_int > target_int)) {
			rtn_index = prev_index;
			break;
		}
		prev_index = i;
	}
	return rtn_index;
}

int Slider_Wheel_Mod::get_next_multiple_of_100(bool increasing, int curr_index) {
	auto increment = increasing ? 100 : -100;
	if ((curr_index == 0 && !increasing) || (curr_index == 1023 && increasing))
		return curr_index;
	auto target_int = int_choices[curr_index];
	auto rtn_index = curr_index;
	if (target_int % 100 == 0)
		target_int += increment;
	else {
		if ((increasing && target_int > 0) || (!increasing && target_int < 0))
			target_int += increment;
		target_int -= target_int % 100;
		rtn_index += increasing ? 1 : -1;
	}
	if (target_int == 0)
		return 512;
	for (int i = rtn_index; increasing ? i < 1024 : i > -1; increasing ? ++i : --i) {
		if (int_choices[i] == target_int) {
			rtn_index = i;
			break;
		}
	}
	return rtn_index;
}

