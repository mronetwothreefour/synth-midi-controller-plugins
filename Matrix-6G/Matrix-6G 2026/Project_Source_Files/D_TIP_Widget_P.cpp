#include "D_TIP_Widget_P.h"

#include "C_SL_Tip_Widget_P.h"

String Tip_Widget_P::knob_text_editor(const Knob_Display_Type display_type, bool u7_bit) {
	switch (display_type)
	{
	case ENUM::Knob_Display_Type::osc_pitch:
		return from_string_literal(SL::knob_txt_edit_osc_pitch_tip);
	case ENUM::Knob_Display_Type::signed_6_bit:
		return from_string_literal(SL::knob_txt_edit_signed_int_tip).replace("_", "31");
	case ENUM::Knob_Display_Type::signed_7_bit:
		return from_string_literal(SL::knob_txt_edit_signed_int_tip).replace("_", "63");
	case ENUM::Knob_Display_Type::unsigned_int:
		return from_string_literal(SL::knob_txt_edit_signed_int_tip).replace("_", u7_bit ? "127" : "63");
	default:
		return "error";
	}
}
