#include "G_WIDG_Knob_Display_Exposed_P.h"

Knob_Display_Exposed_P::Knob_Display_Exposed_P(const int param_index, Data_Hub_P* hub) :
	Knob_Display_Exposed_B{ param_index, hub }
{}

void Knob_Display_Exposed_P::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setJustification(Justification::centred);
	switch (display_type)
	{
	case Knob_Display_Type::lfo_rate:
		edit->setInputRestrictions(avp.lfo_sync_bpm_on() ? 2 : 4, "0123456789");
		break;
	case Knob_Display_Type::osc_2_pitch_eg_int:
		edit->setInputRestrictions(5, "-0123456789");
		break;
	case Knob_Display_Type::osc_pitch_fine:
		edit->setInputRestrictions(5, "-0123456789");
		break;
	case Knob_Display_Type::unsigned_10_bit:
		edit->setInputRestrictions(4, "0123456789");
		break;
	case Knob_Display_Type::voice_mode_depth:
		switch (avp.voice_mode())
		{
		case Voice_Mode::poly:
			edit->setInputRestrictions(1, "012345678");
			break;
		case Voice_Mode::duo:
			edit->setInputRestrictions(2, "0123456789");
			break;
		case Voice_Mode::unison:
			edit->setInputRestrictions(2, "0123456789");
			break;
		case Voice_Mode::mono:
			edit->setInputRestrictions(4, "0123456789");
			break;
		case Voice_Mode::chord:
			edit->setInputRestrictions(2, "0123456789");
			break;
		case Voice_Mode::delay:
			edit->setInputRestrictions(4, "0123456789");
			break;
		case Voice_Mode::arp:
			edit->setInputRestrictions(2, "0123456789");
			break;
		case Voice_Mode::sidechain:
			edit->setInputRestrictions(4, "0123456789");
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	edit->setTooltip(Tip_W::knob_text_editor(display_type, avp));
	edit->selectAll();
}

void Knob_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(param->convertFrom0to1(param->getValue())) };
	auto name = exp_info.choice_for(choice_num, param_index, true);
	auto ctrl_type = exp_info.ctrl_type_for(param_index);
	if (ctrl_type == Ctrl_Type::knob_lfo_rate) {
		if (avp.lfo_sync_bpm_on())
			name = name.fromFirstOccurrenceOf("|", false, false).upToFirstOccurrenceOf("(", false, false);
		else
			name = name.upToFirstOccurrenceOf("|", false, false);
	}
	if (ctrl_type == Ctrl_Type::knob_voice_mode_depth) {
		switch (avp.voice_mode())
		{
		case Voice_Mode::poly:
			name = name.fromFirstOccurrenceOf("1:INV ", false, false).upToFirstOccurrenceOf("|", false, false);
			break;
		case Voice_Mode::duo:
			name = name.fromFirstOccurrenceOf("2&3:", false, false).upToFirstOccurrenceOf("|", false, false);
			break;
		case Voice_Mode::unison:
			name = name.fromFirstOccurrenceOf("2&3:", false, false).upToFirstOccurrenceOf("|", false, false);
			break;
		case Voice_Mode::mono:
			name = name.fromFirstOccurrenceOf("4:", false, false).upToFirstOccurrenceOf("|", false, false);
			break;
		case Voice_Mode::chord:
			name = name.fromFirstOccurrenceOf("5:", false, false).upToFirstOccurrenceOf("(", false, false);
			break;
		case Voice_Mode::delay:
			name = name.fromFirstOccurrenceOf("6:", false, false).upToFirstOccurrenceOf("(", false, false);
			break;
		case Voice_Mode::arp:
			name = name.fromFirstOccurrenceOf("7:", false, false).upToFirstOccurrenceOf("(", false, false);
			break;
		case Voice_Mode::sidechain:
			name = name.fromFirstOccurrenceOf("8:", false, false);
			break;
		default:
			break;
		}
	}
	setText(name, dontSendNotification);
}

void Knob_Display_Exposed_P::on_text_change() {
	switch (display_type)
	{
	case ENUM::Knob_Display_Type::lfo_rate:
		on_text_change_lfo_rate();
		break;
	case ENUM::Knob_Display_Type::osc_2_pitch_eg_int:
		on_text_change_osc_2_pitch_eg_int();
		break;
	case ENUM::Knob_Display_Type::osc_pitch_fine:
		on_text_change_osc_pitch_fine();
		break;
	case ENUM::Knob_Display_Type::unsigned_10_bit:
		on_text_change_unsigned_10_bit();
		break;
	case ENUM::Knob_Display_Type::voice_mode_depth:
		on_text_change_voice_mode_depth();
		break;
	default:
		setText("error", dontSendNotification);
		break;
	}
}

void Knob_Display_Exposed_P::on_text_change_lfo_rate() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		if (avp.lfo_sync_bpm_on())
			param->setValueNotifyingHost(param->convertTo0to1((new_val) * 64.0f));
		else
			param->setValueNotifyingHost(param->convertTo0to1(new_val));
	}
	else
		set_text_to_stored_choice();
}

void Knob_Display_Exposed_P::on_text_change_osc_2_pitch_eg_int() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto input_val{ new_text.getIntValue() };
		auto new_val{ 0 };
		if (input_val >= -4787 && input_val <= -401) {
			new_val = input_val + 4787;
			new_val = 5 + ((new_val / 25) * 2) + (new_val % 25 > 11 ? 1 : 0);
		}
		if (input_val >= -400 && input_val <= -25) {
			new_val = input_val + 400;
			auto offset{ 1 };
			auto newSettingMod_25{ new_val % 25 };
			if (newSettingMod_25 >= 4 && newSettingMod_25 <= 6) offset = 2;
			if (newSettingMod_25 >= 7 && newSettingMod_25 <= 9) offset = 3;
			if (newSettingMod_25 >= 10 && newSettingMod_25 <= 12) offset = 4;
			if (newSettingMod_25 >= 13 && newSettingMod_25 <= 15) offset = 5;
			if (newSettingMod_25 >= 16 && newSettingMod_25 <= 18) offset = 6;
			if (newSettingMod_25 >= 19 && newSettingMod_25 <= 21) offset = 7;
			if (newSettingMod_25 >= 22 && newSettingMod_25 <= 24) offset = 8;
			new_val = 356 + ((new_val / 25) * 8) + offset;
		}
		if (input_val >= -24 && input_val <= 24) {
			if (input_val == -24 || input_val == -23) new_val = 477;
			if (input_val == -22 || input_val == -21) new_val = 478;
			if (input_val == -20) new_val = 479;
			if (input_val == -19 || input_val == -18) new_val = 480;
			if (input_val == -17) new_val = 481;
			if (input_val == -16 || input_val == -15) new_val = 482;
			if (input_val == -14) new_val = 483;
			if (input_val == -13 || input_val == -12) new_val = 484;
			if (input_val == -11 || input_val == -10) new_val = 485;
			if (input_val == -9) new_val = 486;
			if (input_val == -8 || input_val == -7) new_val = 487;
			if (input_val == -6 || input_val == -5) new_val = 488;
			if (input_val == -4) new_val = 489;
			if (input_val == -3) new_val = 490;
			if (input_val == -2) new_val = 491;
			if (input_val == -1) new_val = 492;
			if (input_val == 0) new_val = 512;
			if (input_val == 1) new_val = 531;
			if (input_val == 2) new_val = 532;
			if (input_val == 3) new_val = 533;
			if (input_val == 4) new_val = 534;
			if (input_val == 5 || input_val == 6) new_val = 535;
			if (input_val == 7) new_val = 536;
			if (input_val == 8 || input_val == 9) new_val = 537;
			if (input_val == 10) new_val = 538;
			if (input_val == 11 || input_val == 12) new_val = 539;
			if (input_val == 13 || input_val == 14) new_val = 540;
			if (input_val == 15) new_val = 541;
			if (input_val == 16 || input_val == 17) new_val = 542;
			if (input_val == 18) new_val = 543;
			if (input_val == 19 || input_val == 20) new_val = 544;
			if (input_val == 21) new_val = 545;
			if (input_val == 22 || input_val == 23) new_val = 546;
			if (input_val == 24) new_val = 547;
		}
		if (input_val >= 25 && input_val <= 400) {
			new_val = input_val - 25;
			auto offset{ 1 };
			auto newSettingMod_25{ new_val % 25 };
			if (newSettingMod_25 >= 4 && newSettingMod_25 <= 6) offset = 2;
			if (newSettingMod_25 >= 7 && newSettingMod_25 <= 9) offset = 3;
			if (newSettingMod_25 >= 10 && newSettingMod_25 <= 12) offset = 4;
			if (newSettingMod_25 >= 13 && newSettingMod_25 <= 15) offset = 5;
			if (newSettingMod_25 >= 16 && newSettingMod_25 <= 18) offset = 6;
			if (newSettingMod_25 >= 19 && newSettingMod_25 <= 21) offset = 7;
			if (newSettingMod_25 >= 22 && newSettingMod_25 <= 24) offset = 8;
			new_val = 547 + ((new_val / 25) * 8) + offset;
		}
		if (input_val >= 400 && input_val <= 4788) {
			new_val = input_val - 400;
			new_val = 669 + ((new_val / 25) * 2) + (new_val % 25 > 11 ? 1 : 0);
		}
		if (input_val >= 4789)
			new_val = 1023;
		param->setValueNotifyingHost(param->convertTo0to1((float)new_val));
	}
	else
		set_text_to_stored_choice();
}

void Knob_Display_Exposed_P::on_text_change_osc_pitch_fine()
{
}

void Knob_Display_Exposed_P::on_text_change_unsigned_10_bit() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		param->setValueNotifyingHost(param->convertTo0to1(new_val));
	}
		set_text_to_stored_choice();
}

void Knob_Display_Exposed_P::on_text_change_voice_mode_depth()
{
}
