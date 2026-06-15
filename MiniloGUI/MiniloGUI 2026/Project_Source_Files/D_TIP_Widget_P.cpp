#include "D_TIP_Widget_P.h"

#include "C_SL_Tip_Widget_P.h"

String Tip_Widget_P::knob_text_editor(const Knob_Display_Type display, Tree_Additional_Voice_P& avp) {
	switch (display)
	{
	case Knob_Display_Type::lfo_rate:
		auto synced = avp.lfo_sync_bpm_on();
		return from_string_literal(synced ? SL::knob_txt_edit_lfo_synced_tip : SL::knob_txt_edit_lfo_unsynced_tip);
	case Knob_Display_Type::lpf_eg_int:
		return from_string_literal(SL::knob_txt_lpf_eg_int_tip);
	case Knob_Display_Type::osc_2_pitch_eg_int:
		return from_string_literal(SL::knob_txt_edit_osc_2_pitch_eg_int_tip);
	case Knob_Display_Type::osc_pitch_fine:
		return from_string_literal(SL::knob_txt_edit_osc_pitch_fine_tip);
	case Knob_Display_Type::unsigned_10_bit:
		return from_string_literal(SL::knob_txt_edit_unsigned_10_bit_tip);
	case Knob_Display_Type::voice_mode_depth:
		switch (avp.voice_mode())
		{
		case ENUM::Voice_Mode::poly:
			return from_string_literal(SL::knob_txt_edit_voice_mode_0_tip);
		case ENUM::Voice_Mode::duo:
			return from_string_literal(SL::knob_txt_edit_voice_mode_1_2_tip);
		case ENUM::Voice_Mode::unison:
			return from_string_literal(SL::knob_txt_edit_voice_mode_1_2_tip);
		case ENUM::Voice_Mode::mono:
			return from_string_literal(SL::knob_txt_edit_voice_mode_3_tip);
		case ENUM::Voice_Mode::chord:
			return from_string_literal(SL::knob_txt_edit_voice_mode_4_tip);
		case ENUM::Voice_Mode::delay:
			return from_string_literal(SL::knob_txt_edit_voice_mode_5_tip);
		case ENUM::Voice_Mode::arp:
			return from_string_literal(SL::knob_txt_edit_voice_mode_6_tip);
		case ENUM::Voice_Mode::sidechain:
			return from_string_literal(SL::knob_txt_edit_voice_mode_7_tip);
		default:
			return "error";
		}
	default:
		return "error";
	}
}
