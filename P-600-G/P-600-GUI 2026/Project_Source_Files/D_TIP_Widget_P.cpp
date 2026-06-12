#include "D_TIP_Widget_P.h"

#include "C_SL_Tip_Widget_P.h"

String Tip_Widget_P::knob_text_editor(const Knob_Display_Type display_type) {
	switch (display_type)
	{
	case Knob_Display_Type::int_4_bit:
		return from_string_literal(SL::knob_txt_edit_int_tip).replace("_", "15");
	case Knob_Display_Type::int_5_bit:
		return from_string_literal(SL::knob_txt_edit_int_tip).replace("_", "31");
	case Knob_Display_Type::int_6_bit:
		return from_string_literal(SL::knob_txt_edit_int_tip).replace("_", "63");
	case Knob_Display_Type::int_7_bit:
		return from_string_literal(SL::knob_txt_edit_int_tip).replace("_", "127");
	case Knob_Display_Type::osc_pitch:
		return from_string_literal(SL::knob_txt_edit_osc_pitch_tip);
	default:
		return "error";
	}
}
