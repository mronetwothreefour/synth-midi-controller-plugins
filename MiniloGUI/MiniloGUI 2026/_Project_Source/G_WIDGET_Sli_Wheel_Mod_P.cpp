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
	//for_tempo{ param_id == ID::seq_tempo },
	for_voice_mode{ param_id == ID::exp_voice_mode_depth ? avp.voice_mode() : (int)Voice_Mode::none },
	for_non_standard_knob{ for_lpf_eg_int || for_osc_2_pitch_eg_int || for_osc_pitch_fine ||
						   /*for_tempo ||*/ for_voice_mode > (int)Voice_Mode::none }
{
	if (getName().startsWith("ctr_sli_sw_"))
		setSliderStyle(SliderStyle::LinearVertical);
	if (for_non_standard_knob) {
		if (for_voice_mode == (int)Voice_Mode::none) {
			for (int i = 0; i < 1024; ++i)
				choices_as_ints.add(choices_curt[i].getIntValue());
		}
		else
			update_for_voice_mode(avp.voice_mode());
	}
}

void Slider_Wheel_Mod::update_for_voice_mode(int new_mode) {
	for_voice_mode = new_mode;
	choices_as_ints.clear();
	for (int i = 0; i < 1024; ++i) {
		if (new_mode == (int)Voice_Mode::poly) {
			choices_as_ints.add(i / 114);
			continue;
		}
		if (new_mode == (int)Voice_Mode::duo || new_mode == (int)Voice_Mode::unison) {
			choices_as_ints.add(std::clamp(i / 20, 0, 50));
			continue;
		}
		if (new_mode == (int)Voice_Mode::mono || new_mode == (int)Voice_Mode::sidechain) {
			choices_as_ints.add(i);
			continue;
		}
		if (new_mode == (int)Voice_Mode::chord) {
			if (i < 74) choices_as_ints.add(0);
			if (i >= 74 && i < 147) choices_as_ints.add(1);
			if (i >= 147 && i < 220) choices_as_ints.add(2);
			if (i >= 220 && i < 293) choices_as_ints.add(3);
			if (i >= 293 && i < 366) choices_as_ints.add(4);
			if (i >= 366 && i < 439) choices_as_ints.add(5);
			if (i >= 439 && i < 512) choices_as_ints.add(6);
			if (i >= 512 && i < 586) choices_as_ints.add(7);
			if (i >= 586 && i < 659) choices_as_ints.add(8);
			if (i >= 659 && i < 732) choices_as_ints.add(9);
			if (i >= 732 && i < 805) choices_as_ints.add(10);
			if (i >= 805 && i < 878) choices_as_ints.add(11);
			if (i >= 878 && i < 951) choices_as_ints.add(12);
			if (i >= 951 && i < 1024) choices_as_ints.add(13);
		}
		if (new_mode == (int)Voice_Mode::delay) {
			if (i < 86) choices_as_ints.add(0);
			if (i >= 86 && i < 171) choices_as_ints.add(1);
			if (i >= 171 && i < 256) choices_as_ints.add(2);
			if (i >= 256 && i < 342) choices_as_ints.add(3);
			if (i >= 342 && i < 427) choices_as_ints.add(4);
			if (i >= 427 && i < 512) choices_as_ints.add(5);
			if (i >= 512 && i < 598) choices_as_ints.add(6);
			if (i >= 598 && i < 683) choices_as_ints.add(7);
			if (i >= 683 && i < 768) choices_as_ints.add(8);
			if (i >= 768 && i < 854) choices_as_ints.add(9);
			if (i >= 854 && i < 939) choices_as_ints.add(10);
			if (i >= 939 && i < 1024) choices_as_ints.add(11);
		}
		if (new_mode == (int)Voice_Mode::arp) {
			if (i < 79) choices_as_ints.add(0);
			if (i >= 79 && i < 158) choices_as_ints.add(1);
			if (i >= 158 && i < 237) choices_as_ints.add(2);
			if (i >= 237 && i < 316) choices_as_ints.add(3);
			if (i >= 316 && i < 394) choices_as_ints.add(4);
			if (i >= 394 && i < 473) choices_as_ints.add(5);
			if (i >= 473 && i < 552) choices_as_ints.add(6);
			if (i >= 552 && i < 631) choices_as_ints.add(7);
			if (i >= 631 && i < 709) choices_as_ints.add(8);
			if (i >= 709 && i < 788) choices_as_ints.add(9);
			if (i >= 788 && i < 867) choices_as_ints.add(10);
			if (i >= 867 && i < 946) choices_as_ints.add(11);
			if (i >= 946 && i < 1024) choices_as_ints.add(12);
		}
	}
}

void Slider_Wheel_Mod::mod_value(bool increasing, double& curr_sli_val) {
	if (for_non_standard_knob) {
		auto curr_choice_index = roundToInt(curr_sli_val);
		auto curr_choice_as_int = choices_as_ints[curr_choice_index];
		if ((for_lpf_eg_int)) {
			if (curr_choice_index < 14 && increasing) {
				curr_sli_val = 14;
				return;
			}
			if (curr_choice_as_int == 0) {
				if (increasing)
					curr_sli_val = 541;
				else
					curr_sli_val = 485;
				return;
			}
			if (curr_choice_index > 1011 && !increasing) {
				curr_sli_val = 1011;
				return;
			}
			curr_sli_val = get_next_choice_that_matches_int(curr_choice_as_int + increasing ? 1 : -1);
			return;
		}
		if (for_osc_2_pitch_eg_int || for_osc_pitch_fine) {
			if (curr_choice_index < 5 && increasing) {
				curr_sli_val = 5;
				return;
			}
			if (curr_choice_as_int == 0) {
					if (increasing)
						curr_sli_val = for_osc_2_pitch_eg_int ? 531 : 533;
					else
						curr_sli_val = for_osc_2_pitch_eg_int ? 491 : 489;
					return;
			}
			if (curr_choice_index > 1019 && !increasing) {
				curr_sli_val = 1019;
				return;
			}
		}
		if (for_osc_2_pitch_eg_int) {
			curr_sli_val = get_choice_that_best_matches_int(curr_choice_index,
															increasing ? 1 : -1, -4800, 4800);
			return;
		}
	//	if (for_osc_pitch_fine && curr_choice_as_int > -100 && curr_choice_as_int < 100) {
	//		curr_sli_val = get_choice_that_best_matches_int(disp_val_index, roundToInt(incr), -1200, 1200);
	//		return;
	//	}
	//	if (for_voice_mode > (int)Voice_Mode::none) {
	//		curr_sli_val = get_choice_that_best_matches_int(disp_val_index, roundToInt(incr), 0, 1023);
	//		return;
	//	}
	}
	curr_sli_val += increasing ? 1.0 : -1.0;
}

void Slider_Wheel_Mod::alt_mod_value(bool increasing, double& curr_val) {
	//if (for_osc_2_pitch_eg_int || for_osc_pitch_fine) {
	//	curr_val = get_next_multiple_of_100(roundToInt(incr), roundToInt(curr_val));
	//	return;
	//}
	mod_value(increasing, curr_val);
}

void Slider_Wheel_Mod::ctrl_mod_value(bool increasing, double& curr_val) {
	//if (for_non_standard_knob) {
	//	auto v = roundToInt(curr_val);
	//	if (for_osc_2_pitch_eg_int) {
	//		curr_val = get_choice_that_best_matches_int(v, roundToInt(incr) * 100, -4800, 4800);
	//		return;
	//	}
	//	if (for_osc_pitch_fine) {
	//		curr_val = get_choice_that_best_matches_int(v, roundToInt(incr) * 100, -1200, 1200);
	//		return;
	//	}
	//}
	curr_val += increasing ? 100.0 : -100.0;
}

void Slider_Wheel_Mod::shift_mod_value(bool increasing, double& curr_val) {
	//if (for_non_standard_knob) {
	//	auto v = roundToInt(curr_val);
	//	auto i = roundToInt(incr);
	//	if (for_lpf_eg_int) {
	//		curr_val = get_choice_that_best_matches_int(v, i * 5, -100, 100);
	//		return;
	//	}
	//	if (for_osc_2_pitch_eg_int) {
	//		curr_val = get_choice_that_best_matches_int(v, i * 25, -4800, 4800);
	//		return;
	//	}
	//	if (for_osc_pitch_fine) {
	//		curr_val = get_choice_that_best_matches_int(v, i * 25, -1200, 1200);
	//		return;
	//	}
	//	if (for_voice_mode > (int)Voice_Mode::none) {
	//		if (for_voice_mode == (int)Voice_Mode::duo || for_voice_mode == (int)Voice_Mode::unison) {
	//			curr_val = get_choice_that_best_matches_int(v, i * 5, 0, 1023);
	//			return;
	//		}
	//		if (for_voice_mode == (int)Voice_Mode::mono || for_voice_mode == (int)Voice_Mode::sidechain) {
	//			curr_val = get_choice_that_best_matches_int(v, i * 25, 0, 1023);
	//			return;
	//		}
	//		curr_val = get_choice_that_best_matches_int(v, i, 0, 1023);
	//		return;
	//	}
	//}
	curr_val += increasing ? 25.0 : -25.0;
}

int Slider_Wheel_Mod::get_choice_that_best_matches_int(int target, int incr, int min, int max) {
	auto below = incr < 0;
	auto above = incr > 0;
	auto index = std::clamp(target, 0, 1023);
	if ((index == 0 && below) || (index == 1023 && above))
		return index;
	auto current_disp_val = choices_as_ints[index];
	auto target_disp_val = std::clamp(current_disp_val + incr, min, max);
	auto id = getComponentID();
	if (target_disp_val == 0 && for_non_standard_knob && for_voice_mode == (int)Voice_Mode::none)
		return 512;
	auto prev_i = index;
	for (int i = index; above ? i < 1024 : i > -1; above ? ++i : --i) {
		auto val = choices_as_ints[i];
		if (val == target_disp_val) {
			index = i;
			break;
		}
		if ((below && val < target_disp_val) || (above && val > target_disp_val)) {
			index = prev_i;
			break;
		}
		prev_i = i;
	}
	return index;
}

int Slider_Wheel_Mod::get_next_choice_that_matches_int(int target) {
	if (for_non_standard_knob) {
		auto id = getComponentID();
		if (target == 0 && for_voice_mode == -1) 
			return 512;
	}
	auto l = 0;
	auto r = 1023;
	while (l < r) {
		if (abs(choices_as_ints[l] - target)
			<= abs(choices_as_ints[r] - target)) {
			r--;
		}
		else
			l++;
	}
	return l;
}

//int Slider_Wheel_Mod::get_next_multiple_of_100(int incr, int v) {
//	auto decreasing = incr < 0;
//	auto increasing = incr > 0;
//	incr *= 100;
//	auto index = std::clamp(v, 0, 1023);
//	if ((index == 0 && decreasing) || (index == 1023 && increasing))
//		return index;
//	auto target_val = display_values[index];
//	if (target_val % 100 == 0)
//		target_val += incr;
//	else {
//		if ((increasing && target_val > 0) || (decreasing && target_val < 0))
//			target_val += incr;
//		target_val -= target_val % 100;
//		index += increasing ? 1 : -1;
//	}
//	for (int i = index; increasing ? i < 1024 : i > -1; increasing ? ++i : --i) {
//		if (display_values[i] == target_val) {
//			index = i;
//			break;
//		}
//	}
//	return index;
//}

