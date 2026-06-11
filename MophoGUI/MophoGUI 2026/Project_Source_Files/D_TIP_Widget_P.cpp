#include "D_TIP_Widget_P.h"

#include "C_SL_Tip_Widget_P.h"

String Tip_Widget_P::knob_text_editor(const Knob_Display_Type display_type) {
	switch (display_type)
	{
	case ENUM::Knob_Display_Type::bend_range:
		return from_string_literal(SL::knob_txt_edit_bend_range_tip);
	case ENUM::Knob_Display_Type::clock_tempo:
		return from_string_literal(SL::knob_txt_edit_clock_tempo_tip);
	case ENUM::Knob_Display_Type::lfo_freq:
		return from_string_literal(SL::knob_txt_edit_lfo_freq_tip);
	case ENUM::Knob_Display_Type::lpf_freq:
		return from_string_literal(SL::knob_txt_edit_lpf_freq_tip);
	case ENUM::Knob_Display_Type::osc_fine:
		return from_string_literal(SL::knob_txt_edit_osc_fine_tip);
	case ENUM::Knob_Display_Type::osc_pitch:
		return from_string_literal(SL::knob_txt_edit_osc_pitch_tip);
	case ENUM::Knob_Display_Type::osc_shape:
		return from_string_literal(SL::knob_txt_edit_osc_shape_tip);
	case ENUM::Knob_Display_Type::osc_slop:
		return from_string_literal(SL::knob_txt_edit_osc_slop_tip);
	case ENUM::Knob_Display_Type::signed_8_bit:
		return from_string_literal(SL::knob_txt_edit_signed_8_bit_tip);
	case ENUM::Knob_Display_Type::unsigned_7_bit:
		return from_string_literal(SL::knob_txt_edit_unsigned_7_bit_tip);
	default:
		return "ERR";
	}
}
