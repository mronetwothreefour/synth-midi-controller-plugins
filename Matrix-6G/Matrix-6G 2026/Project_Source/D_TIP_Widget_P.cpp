#include "D_TIP_Widget_P.h"

#include "C_SL_Tip_Widget_P.h"

String Tip_Widget_P::knob_text_editor(const Slider_Display_Type display_type, bool u_7_bit) {
	switch (display_type)
	{
	case ENUM::Slider_Display_Type::osc_pitch:
		return from_string_literal(SL::knob_txt_edit_osc_pitch_tip);
	case ENUM::Slider_Display_Type::s_6_bit_int:
		return from_string_literal(SL::knob_txt_edit_s_int_tip).replace("_", "31");
	case ENUM::Slider_Display_Type::s_7_bit_int:
		return from_string_literal(SL::knob_txt_edit_s_int_tip).replace("_", "63");
	case ENUM::Slider_Display_Type::u_int:
		return from_string_literal(SL::knob_txt_edit_u_int_tip).replace("_", u_7_bit ? "127" : "63");
	default:
		return "error";
	}
}
