#include "D_TIP_Widget_P.h"

#include "C_SL_Tip_Widget_P.h"

String Tip_Widget_P::knob_text_editor(const Slider_Display_Type display_type) {
	switch (display_type)
	{
	case ENUM::Slider_Display_Type::bend_range:
		return from_string_literal(SL::knob_txt_edit_bend_range_tip);
	case ENUM::Slider_Display_Type::clock_tempo:
		return from_string_literal(SL::knob_txt_edit_clock_tempo_tip);
	case ENUM::Slider_Display_Type::lfo_freq:
		return from_string_literal(SL::knob_txt_edit_lfo_freq_tip);
	case ENUM::Slider_Display_Type::lpf_freq:
		return from_string_literal(SL::knob_txt_edit_lpf_freq_tip);
	case ENUM::Slider_Display_Type::osc_fine:
		return from_string_literal(SL::knob_txt_edit_osc_fine_tip);
	case ENUM::Slider_Display_Type::osc_pitch:
		return from_string_literal(SL::knob_txt_edit_osc_pitch_tip);
	case ENUM::Slider_Display_Type::osc_shape:
		return from_string_literal(SL::knob_txt_edit_osc_shape_tip);
	case ENUM::Slider_Display_Type::osc_slop:
		return from_string_literal(SL::knob_txt_edit_osc_slop_tip);
	case ENUM::Slider_Display_Type::seq_step:
		return from_string_literal(SL::knob_txt_edit_seq_step_tip);
	case ENUM::Slider_Display_Type::seq_step_trk_1:
		return from_string_literal(SL::knob_txt_edit_seq_step_tip) + "\n" +
			   from_string_literal(SL::knob_txt_edit_seq_step_track_1_tip);
	case ENUM::Slider_Display_Type::s_8_bit_int:
		return from_string_literal(SL::knob_txt_edit_s_8_bit_int_tip);
	case ENUM::Slider_Display_Type::u_7_bit_int:
		return from_string_literal(SL::knob_txt_edit_u_7_bit_int_tip);
	default:
		return "error";
	}
}
