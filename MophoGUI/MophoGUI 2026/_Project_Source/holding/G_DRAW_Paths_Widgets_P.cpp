#include "G_DRAW_Paths_Widgets_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_Widgets_P.h"

using namespace DRAW;

Path Paths_Widgets::build_char_path(const uint8 char_num) {
	auto char_num_space{ (uint8)32 };
	if (char_num <= char_num_space)
		return {};
	switch (char_num) {
	case (uint8)33: {
		Path path_exclamation;
		path_exclamation.addPath(PATH::lcd_pixel_1_3);
		path_exclamation.addPath(PATH::lcd_pixel_2_3);
		path_exclamation.addPath(PATH::lcd_pixel_3_3);
		path_exclamation.addPath(PATH::lcd_pixel_4_3);
		path_exclamation.addPath(PATH::lcd_pixel_7_3);
		return path_exclamation;
	}
	case (uint8)34: {
		Path path_double_quote;
		path_double_quote.addPath(PATH::lcd_pixel_1_2);
		path_double_quote.addPath(PATH::lcd_pixel_1_4);
		path_double_quote.addPath(PATH::lcd_pixel_2_2);
		path_double_quote.addPath(PATH::lcd_pixel_2_4);
		path_double_quote.addPath(PATH::lcd_pixel_3_2);
		path_double_quote.addPath(PATH::lcd_pixel_3_4);
		return path_double_quote;
	}
	case (uint8)35: {
		Path path_hash;
		path_hash.addPath(PATH::lcd_pixel_1_2);
		path_hash.addPath(PATH::lcd_pixel_1_4);
		path_hash.addPath(PATH::lcd_pixel_2_2);
		path_hash.addPath(PATH::lcd_pixel_2_4);
		path_hash.addPath(PATH::lcd_pixel_3_1);
		path_hash.addPath(PATH::lcd_pixel_3_2);
		path_hash.addPath(PATH::lcd_pixel_3_3);
		path_hash.addPath(PATH::lcd_pixel_3_4);
		path_hash.addPath(PATH::lcd_pixel_3_5);
		path_hash.addPath(PATH::lcd_pixel_4_2);
		path_hash.addPath(PATH::lcd_pixel_4_4);
		path_hash.addPath(PATH::lcd_pixel_5_1);
		path_hash.addPath(PATH::lcd_pixel_5_2);
		path_hash.addPath(PATH::lcd_pixel_5_3);
		path_hash.addPath(PATH::lcd_pixel_5_4);
		path_hash.addPath(PATH::lcd_pixel_5_5);
		path_hash.addPath(PATH::lcd_pixel_6_2);
		path_hash.addPath(PATH::lcd_pixel_6_4);
		path_hash.addPath(PATH::lcd_pixel_7_2);
		path_hash.addPath(PATH::lcd_pixel_7_4);
		return path_hash;
	}
	case (uint8)36: {
		Path path_$;
		path_$.addPath(PATH::lcd_pixel_1_3);
		path_$.addPath(PATH::lcd_pixel_2_2);
		path_$.addPath(PATH::lcd_pixel_2_3);
		path_$.addPath(PATH::lcd_pixel_2_4);
		path_$.addPath(PATH::lcd_pixel_2_5);
		path_$.addPath(PATH::lcd_pixel_3_1);
		path_$.addPath(PATH::lcd_pixel_3_3);
		path_$.addPath(PATH::lcd_pixel_4_2);
		path_$.addPath(PATH::lcd_pixel_4_3);
		path_$.addPath(PATH::lcd_pixel_4_4);
		path_$.addPath(PATH::lcd_pixel_5_3);
		path_$.addPath(PATH::lcd_pixel_5_5);
		path_$.addPath(PATH::lcd_pixel_6_1);
		path_$.addPath(PATH::lcd_pixel_6_2);
		path_$.addPath(PATH::lcd_pixel_6_3);
		path_$.addPath(PATH::lcd_pixel_6_4);
		path_$.addPath(PATH::lcd_pixel_7_3);
		return path_$;
	}
	case (uint8)37: {
		Path path_percent;
		path_percent.addPath(PATH::lcd_pixel_1_1);
		path_percent.addPath(PATH::lcd_pixel_1_2);
		path_percent.addPath(PATH::lcd_pixel_2_1);
		path_percent.addPath(PATH::lcd_pixel_2_2);
		path_percent.addPath(PATH::lcd_pixel_2_5);
		path_percent.addPath(PATH::lcd_pixel_3_4);
		path_percent.addPath(PATH::lcd_pixel_4_3);
		path_percent.addPath(PATH::lcd_pixel_5_2);
		path_percent.addPath(PATH::lcd_pixel_6_1);
		path_percent.addPath(PATH::lcd_pixel_6_4);
		path_percent.addPath(PATH::lcd_pixel_6_5);
		path_percent.addPath(PATH::lcd_pixel_7_4);
		path_percent.addPath(PATH::lcd_pixel_7_5);
		return path_percent;
	}
	case (uint8)38: {
		Path path_ampersand;
		path_ampersand.addPath(PATH::lcd_pixel_1_2);
		path_ampersand.addPath(PATH::lcd_pixel_1_3);
		path_ampersand.addPath(PATH::lcd_pixel_2_1);
		path_ampersand.addPath(PATH::lcd_pixel_2_4);
		path_ampersand.addPath(PATH::lcd_pixel_3_1);
		path_ampersand.addPath(PATH::lcd_pixel_3_3);
		path_ampersand.addPath(PATH::lcd_pixel_4_2);
		path_ampersand.addPath(PATH::lcd_pixel_5_1);
		path_ampersand.addPath(PATH::lcd_pixel_5_3);
		path_ampersand.addPath(PATH::lcd_pixel_5_5);
		path_ampersand.addPath(PATH::lcd_pixel_6_1);
		path_ampersand.addPath(PATH::lcd_pixel_6_4);
		path_ampersand.addPath(PATH::lcd_pixel_6_5);
		path_ampersand.addPath(PATH::lcd_pixel_7_2);
		path_ampersand.addPath(PATH::lcd_pixel_7_3);
		path_ampersand.addPath(PATH::lcd_pixel_7_5);
		return path_ampersand;
	}
	case (uint8)39: {
		Path path_single_quote;
		path_single_quote.addPath(PATH::lcd_pixel_1_2);
		path_single_quote.addPath(PATH::lcd_pixel_1_3);
		path_single_quote.addPath(PATH::lcd_pixel_2_3);
		path_single_quote.addPath(PATH::lcd_pixel_3_2);
		return path_single_quote;
	}
	case (uint8)40: {
		Path path_open_parenthesis;
		path_open_parenthesis.addPath(PATH::lcd_pixel_1_4);
		path_open_parenthesis.addPath(PATH::lcd_pixel_2_3);
		path_open_parenthesis.addPath(PATH::lcd_pixel_3_2);
		path_open_parenthesis.addPath(PATH::lcd_pixel_4_2);
		path_open_parenthesis.addPath(PATH::lcd_pixel_5_2);
		path_open_parenthesis.addPath(PATH::lcd_pixel_6_3);
		path_open_parenthesis.addPath(PATH::lcd_pixel_7_4);
		return path_open_parenthesis;
	}
	case (uint8)41: {
		Path path_close_parenthesis;
		path_close_parenthesis.addPath(PATH::lcd_pixel_1_2);
		path_close_parenthesis.addPath(PATH::lcd_pixel_2_3);
		path_close_parenthesis.addPath(PATH::lcd_pixel_3_4);
		path_close_parenthesis.addPath(PATH::lcd_pixel_4_4);
		path_close_parenthesis.addPath(PATH::lcd_pixel_5_4);
		path_close_parenthesis.addPath(PATH::lcd_pixel_6_3);
		path_close_parenthesis.addPath(PATH::lcd_pixel_7_2);
		return path_close_parenthesis;
	}
	case (uint8)42: {
		Path path_asterisk;
		path_asterisk.addPath(PATH::lcd_pixel_2_3);
		path_asterisk.addPath(PATH::lcd_pixel_3_1);
		path_asterisk.addPath(PATH::lcd_pixel_3_3);
		path_asterisk.addPath(PATH::lcd_pixel_3_5);
		path_asterisk.addPath(PATH::lcd_pixel_4_2);
		path_asterisk.addPath(PATH::lcd_pixel_4_3);
		path_asterisk.addPath(PATH::lcd_pixel_4_4);
		path_asterisk.addPath(PATH::lcd_pixel_5_1);
		path_asterisk.addPath(PATH::lcd_pixel_5_3);
		path_asterisk.addPath(PATH::lcd_pixel_5_5);
		path_asterisk.addPath(PATH::lcd_pixel_6_3);
		return path_asterisk;
	}
	case (uint8)43: {
		Path path_plus;
		path_plus.addPath(PATH::lcd_pixel_2_3);
		path_plus.addPath(PATH::lcd_pixel_3_3);
		path_plus.addPath(PATH::lcd_pixel_4_1);
		path_plus.addPath(PATH::lcd_pixel_4_2);
		path_plus.addPath(PATH::lcd_pixel_4_3);
		path_plus.addPath(PATH::lcd_pixel_4_4);
		path_plus.addPath(PATH::lcd_pixel_4_5);
		path_plus.addPath(PATH::lcd_pixel_5_3);
		path_plus.addPath(PATH::lcd_pixel_6_3);
		return path_plus;
	}
	case (uint8)44: {
		Path path_comma;
		path_comma.addPath(PATH::lcd_pixel_5_2);
		path_comma.addPath(PATH::lcd_pixel_5_3);
		path_comma.addPath(PATH::lcd_pixel_6_3);
		path_comma.addPath(PATH::lcd_pixel_7_2);
		return path_comma;
	}
	case (uint8)45: {
		Path path_hyphen;
		path_hyphen.addPath(PATH::lcd_pixel_4_1);
		path_hyphen.addPath(PATH::lcd_pixel_4_2);
		path_hyphen.addPath(PATH::lcd_pixel_4_3);
		path_hyphen.addPath(PATH::lcd_pixel_4_4);
		path_hyphen.addPath(PATH::lcd_pixel_4_5);
		return path_hyphen;
	}
	case (uint8)46: {
		Path path_period;
		path_period.addPath(PATH::lcd_pixel_6_2);
		path_period.addPath(PATH::lcd_pixel_6_3);
		path_period.addPath(PATH::lcd_pixel_7_2);
		path_period.addPath(PATH::lcd_pixel_7_3);
		return path_period;
	}
	case (uint8)47: {
		Path path_slash;
		path_slash.addPath(PATH::lcd_pixel_2_5);
		path_slash.addPath(PATH::lcd_pixel_3_4);
		path_slash.addPath(PATH::lcd_pixel_4_3);
		path_slash.addPath(PATH::lcd_pixel_5_2);
		path_slash.addPath(PATH::lcd_pixel_6_1);
		return path_slash;
	}
	case (uint8)48: {
		Path path_0;
		path_0.addPath(PATH::lcd_pixel_1_2);
		path_0.addPath(PATH::lcd_pixel_1_3);
		path_0.addPath(PATH::lcd_pixel_1_4);
		path_0.addPath(PATH::lcd_pixel_2_1);
		path_0.addPath(PATH::lcd_pixel_2_5);
		path_0.addPath(PATH::lcd_pixel_3_1);
		path_0.addPath(PATH::lcd_pixel_3_4);
		path_0.addPath(PATH::lcd_pixel_3_5);
		path_0.addPath(PATH::lcd_pixel_4_1);
		path_0.addPath(PATH::lcd_pixel_4_3);
		path_0.addPath(PATH::lcd_pixel_4_5);
		path_0.addPath(PATH::lcd_pixel_5_1);
		path_0.addPath(PATH::lcd_pixel_5_2);
		path_0.addPath(PATH::lcd_pixel_5_5);
		path_0.addPath(PATH::lcd_pixel_6_1);
		path_0.addPath(PATH::lcd_pixel_6_5);
		path_0.addPath(PATH::lcd_pixel_7_2);
		path_0.addPath(PATH::lcd_pixel_7_3);
		path_0.addPath(PATH::lcd_pixel_7_4);
		return path_0;
	}
	case (uint8)49: {
		Path path_1;
		path_1.addPath(PATH::lcd_pixel_1_3);
		path_1.addPath(PATH::lcd_pixel_2_2);
		path_1.addPath(PATH::lcd_pixel_2_3);
		path_1.addPath(PATH::lcd_pixel_3_3);
		path_1.addPath(PATH::lcd_pixel_4_3);
		path_1.addPath(PATH::lcd_pixel_5_3);
		path_1.addPath(PATH::lcd_pixel_6_3);
		path_1.addPath(PATH::lcd_pixel_7_2);
		path_1.addPath(PATH::lcd_pixel_7_3);
		path_1.addPath(PATH::lcd_pixel_7_4);
		return path_1;
	}
	case (uint8)50: {
		Path path_2;
		path_2.addPath(PATH::lcd_pixel_1_2);
		path_2.addPath(PATH::lcd_pixel_1_3);
		path_2.addPath(PATH::lcd_pixel_1_4);
		path_2.addPath(PATH::lcd_pixel_2_1);
		path_2.addPath(PATH::lcd_pixel_2_5);
		path_2.addPath(PATH::lcd_pixel_3_5);
		path_2.addPath(PATH::lcd_pixel_4_4);
		path_2.addPath(PATH::lcd_pixel_5_3);
		path_2.addPath(PATH::lcd_pixel_6_2);
		path_2.addPath(PATH::lcd_pixel_7_1);
		path_2.addPath(PATH::lcd_pixel_7_2);
		path_2.addPath(PATH::lcd_pixel_7_3);
		path_2.addPath(PATH::lcd_pixel_7_4);
		path_2.addPath(PATH::lcd_pixel_7_5);
		return path_2;
	}
	case (uint8)51: {
		Path path_3;
		path_3.addPath(PATH::lcd_pixel_1_1);
		path_3.addPath(PATH::lcd_pixel_1_2);
		path_3.addPath(PATH::lcd_pixel_1_3);
		path_3.addPath(PATH::lcd_pixel_1_4);
		path_3.addPath(PATH::lcd_pixel_1_5);
		path_3.addPath(PATH::lcd_pixel_2_4);
		path_3.addPath(PATH::lcd_pixel_3_3);
		path_3.addPath(PATH::lcd_pixel_4_4);
		path_3.addPath(PATH::lcd_pixel_5_5);
		path_3.addPath(PATH::lcd_pixel_6_1);
		path_3.addPath(PATH::lcd_pixel_6_5);
		path_3.addPath(PATH::lcd_pixel_7_2);
		path_3.addPath(PATH::lcd_pixel_7_3);
		path_3.addPath(PATH::lcd_pixel_7_4);
		return path_3;
	}
	case (uint8)52: {
		Path path_4;
		path_4.addPath(PATH::lcd_pixel_1_4);
		path_4.addPath(PATH::lcd_pixel_2_3);
		path_4.addPath(PATH::lcd_pixel_2_4);
		path_4.addPath(PATH::lcd_pixel_3_2);
		path_4.addPath(PATH::lcd_pixel_3_4);
		path_4.addPath(PATH::lcd_pixel_4_1);
		path_4.addPath(PATH::lcd_pixel_4_4);
		path_4.addPath(PATH::lcd_pixel_5_1);
		path_4.addPath(PATH::lcd_pixel_5_2);
		path_4.addPath(PATH::lcd_pixel_5_3);
		path_4.addPath(PATH::lcd_pixel_5_4);
		path_4.addPath(PATH::lcd_pixel_5_5);
		path_4.addPath(PATH::lcd_pixel_6_4);
		path_4.addPath(PATH::lcd_pixel_7_4);
		return path_4;
	}
	case (uint8)53: {
		Path path_5;
		path_5.addPath(PATH::lcd_pixel_1_1);
		path_5.addPath(PATH::lcd_pixel_1_2);
		path_5.addPath(PATH::lcd_pixel_1_3);
		path_5.addPath(PATH::lcd_pixel_1_4);
		path_5.addPath(PATH::lcd_pixel_1_5);
		path_5.addPath(PATH::lcd_pixel_2_1);
		path_5.addPath(PATH::lcd_pixel_3_1);
		path_5.addPath(PATH::lcd_pixel_3_2);
		path_5.addPath(PATH::lcd_pixel_3_3);
		path_5.addPath(PATH::lcd_pixel_3_4);
		path_5.addPath(PATH::lcd_pixel_4_5);
		path_5.addPath(PATH::lcd_pixel_5_5);
		path_5.addPath(PATH::lcd_pixel_6_1);
		path_5.addPath(PATH::lcd_pixel_6_5);
		path_5.addPath(PATH::lcd_pixel_7_2);
		path_5.addPath(PATH::lcd_pixel_7_3);
		path_5.addPath(PATH::lcd_pixel_7_4);
		return path_5;
	}
	case (uint8)54: {
		Path path_6;
		path_6.addPath(PATH::lcd_pixel_1_3);
		path_6.addPath(PATH::lcd_pixel_1_4);
		path_6.addPath(PATH::lcd_pixel_2_2);
		path_6.addPath(PATH::lcd_pixel_3_1);
		path_6.addPath(PATH::lcd_pixel_4_1);
		path_6.addPath(PATH::lcd_pixel_4_2);
		path_6.addPath(PATH::lcd_pixel_4_3);
		path_6.addPath(PATH::lcd_pixel_4_4);
		path_6.addPath(PATH::lcd_pixel_5_1);
		path_6.addPath(PATH::lcd_pixel_5_5);
		path_6.addPath(PATH::lcd_pixel_6_1);
		path_6.addPath(PATH::lcd_pixel_6_5);
		path_6.addPath(PATH::lcd_pixel_7_2);
		path_6.addPath(PATH::lcd_pixel_7_3);
		path_6.addPath(PATH::lcd_pixel_7_4);
		return path_6;
	}
	case (uint8)55: {
		Path path_7;
		path_7.addPath(PATH::lcd_pixel_1_1);
		path_7.addPath(PATH::lcd_pixel_1_2);
		path_7.addPath(PATH::lcd_pixel_1_3);
		path_7.addPath(PATH::lcd_pixel_1_4);
		path_7.addPath(PATH::lcd_pixel_1_5);
		path_7.addPath(PATH::lcd_pixel_2_5);
		path_7.addPath(PATH::lcd_pixel_3_4);
		path_7.addPath(PATH::lcd_pixel_4_3);
		path_7.addPath(PATH::lcd_pixel_5_2);
		path_7.addPath(PATH::lcd_pixel_6_2);
		path_7.addPath(PATH::lcd_pixel_7_2);
		return path_7;
	}
	case (uint8)56: {
		Path path_8;
		path_8.addPath(PATH::lcd_pixel_1_2);
		path_8.addPath(PATH::lcd_pixel_1_3);
		path_8.addPath(PATH::lcd_pixel_1_4);
		path_8.addPath(PATH::lcd_pixel_2_1);
		path_8.addPath(PATH::lcd_pixel_2_5);
		path_8.addPath(PATH::lcd_pixel_3_1);
		path_8.addPath(PATH::lcd_pixel_3_5);
		path_8.addPath(PATH::lcd_pixel_4_2);
		path_8.addPath(PATH::lcd_pixel_4_3);
		path_8.addPath(PATH::lcd_pixel_4_4);
		path_8.addPath(PATH::lcd_pixel_5_1);
		path_8.addPath(PATH::lcd_pixel_5_5);
		path_8.addPath(PATH::lcd_pixel_6_1);
		path_8.addPath(PATH::lcd_pixel_6_5);
		path_8.addPath(PATH::lcd_pixel_7_2);
		path_8.addPath(PATH::lcd_pixel_7_3);
		path_8.addPath(PATH::lcd_pixel_7_4);
		return path_8;
	}
	case (uint8)57: {
		Path path_9;
		path_9.addPath(PATH::lcd_pixel_1_2);
		path_9.addPath(PATH::lcd_pixel_1_3);
		path_9.addPath(PATH::lcd_pixel_1_4);
		path_9.addPath(PATH::lcd_pixel_2_1);
		path_9.addPath(PATH::lcd_pixel_2_5);
		path_9.addPath(PATH::lcd_pixel_3_1);
		path_9.addPath(PATH::lcd_pixel_3_5);
		path_9.addPath(PATH::lcd_pixel_4_2);
		path_9.addPath(PATH::lcd_pixel_4_3);
		path_9.addPath(PATH::lcd_pixel_4_4);
		path_9.addPath(PATH::lcd_pixel_4_5);
		path_9.addPath(PATH::lcd_pixel_5_5);
		path_9.addPath(PATH::lcd_pixel_6_4);
		path_9.addPath(PATH::lcd_pixel_7_2);
		path_9.addPath(PATH::lcd_pixel_7_3);
		return path_9;
	}
	case (uint8)58: {
		Path path_colon;
		path_colon.addPath(PATH::lcd_pixel_2_2);
		path_colon.addPath(PATH::lcd_pixel_2_3);
		path_colon.addPath(PATH::lcd_pixel_3_2);
		path_colon.addPath(PATH::lcd_pixel_3_3);
		path_colon.addPath(PATH::lcd_pixel_5_2);
		path_colon.addPath(PATH::lcd_pixel_5_3);
		path_colon.addPath(PATH::lcd_pixel_6_2);
		path_colon.addPath(PATH::lcd_pixel_6_3);
		return path_colon;
	}
	case (uint8)59: {
		Path path_semicolon;
		path_semicolon.addPath(PATH::lcd_pixel_2_2);
		path_semicolon.addPath(PATH::lcd_pixel_2_3);
		path_semicolon.addPath(PATH::lcd_pixel_3_2);
		path_semicolon.addPath(PATH::lcd_pixel_3_3);
		path_semicolon.addPath(PATH::lcd_pixel_5_2);
		path_semicolon.addPath(PATH::lcd_pixel_5_3);
		path_semicolon.addPath(PATH::lcd_pixel_6_3);
		path_semicolon.addPath(PATH::lcd_pixel_7_2);
		return path_semicolon;
	}
	case (uint8)60: {
		Path path_open_angle_bracket;
		path_open_angle_bracket.addPath(PATH::lcd_pixel_1_4);
		path_open_angle_bracket.addPath(PATH::lcd_pixel_2_3);
		path_open_angle_bracket.addPath(PATH::lcd_pixel_3_2);
		path_open_angle_bracket.addPath(PATH::lcd_pixel_4_1);
		path_open_angle_bracket.addPath(PATH::lcd_pixel_5_2);
		path_open_angle_bracket.addPath(PATH::lcd_pixel_6_3);
		path_open_angle_bracket.addPath(PATH::lcd_pixel_7_4);
		return path_open_angle_bracket;
	}
	case (uint8)61: {
		Path path_equal;
		path_equal.addPath(PATH::lcd_pixel_3_1);
		path_equal.addPath(PATH::lcd_pixel_3_2);
		path_equal.addPath(PATH::lcd_pixel_3_3);
		path_equal.addPath(PATH::lcd_pixel_3_4);
		path_equal.addPath(PATH::lcd_pixel_3_5);
		path_equal.addPath(PATH::lcd_pixel_5_1);
		path_equal.addPath(PATH::lcd_pixel_5_2);
		path_equal.addPath(PATH::lcd_pixel_5_3);
		path_equal.addPath(PATH::lcd_pixel_5_4);
		path_equal.addPath(PATH::lcd_pixel_5_5);
		return path_equal;
	}
	case (uint8)62: {
		Path path_close_angle_bracket;
		path_close_angle_bracket.addPath(PATH::lcd_pixel_1_2);
		path_close_angle_bracket.addPath(PATH::lcd_pixel_2_3);
		path_close_angle_bracket.addPath(PATH::lcd_pixel_3_4);
		path_close_angle_bracket.addPath(PATH::lcd_pixel_4_5);
		path_close_angle_bracket.addPath(PATH::lcd_pixel_5_4);
		path_close_angle_bracket.addPath(PATH::lcd_pixel_6_3);
		path_close_angle_bracket.addPath(PATH::lcd_pixel_7_2);
		return path_close_angle_bracket;
	}
	case (uint8)63: {
		Path path_question;
		path_question.addPath(PATH::lcd_pixel_1_2);
		path_question.addPath(PATH::lcd_pixel_1_3);
		path_question.addPath(PATH::lcd_pixel_1_4);
		path_question.addPath(PATH::lcd_pixel_2_1);
		path_question.addPath(PATH::lcd_pixel_2_5);
		path_question.addPath(PATH::lcd_pixel_3_5);
		path_question.addPath(PATH::lcd_pixel_4_4);
		path_question.addPath(PATH::lcd_pixel_5_3);
		path_question.addPath(PATH::lcd_pixel_7_3);
		return path_question;
	}
	case (uint8)64: {
		Path path_at;
		path_at.addPath(PATH::lcd_pixel_1_2);
		path_at.addPath(PATH::lcd_pixel_1_3);
		path_at.addPath(PATH::lcd_pixel_1_4);
		path_at.addPath(PATH::lcd_pixel_2_1);
		path_at.addPath(PATH::lcd_pixel_2_5);
		path_at.addPath(PATH::lcd_pixel_3_5);
		path_at.addPath(PATH::lcd_pixel_4_2);
		path_at.addPath(PATH::lcd_pixel_4_3);
		path_at.addPath(PATH::lcd_pixel_4_5);
		path_at.addPath(PATH::lcd_pixel_5_1);
		path_at.addPath(PATH::lcd_pixel_5_3);
		path_at.addPath(PATH::lcd_pixel_5_5);
		path_at.addPath(PATH::lcd_pixel_6_1);
		path_at.addPath(PATH::lcd_pixel_6_3);
		path_at.addPath(PATH::lcd_pixel_6_5);
		path_at.addPath(PATH::lcd_pixel_7_2);
		path_at.addPath(PATH::lcd_pixel_7_3);
		path_at.addPath(PATH::lcd_pixel_7_4);
		return path_at;
	}
	case (uint8)65: {
		Path path_A;
		path_A.addPath(PATH::lcd_pixel_1_2);
		path_A.addPath(PATH::lcd_pixel_1_3);
		path_A.addPath(PATH::lcd_pixel_1_4);
		path_A.addPath(PATH::lcd_pixel_2_1);
		path_A.addPath(PATH::lcd_pixel_2_5);
		path_A.addPath(PATH::lcd_pixel_3_1);
		path_A.addPath(PATH::lcd_pixel_3_5);
		path_A.addPath(PATH::lcd_pixel_4_1);
		path_A.addPath(PATH::lcd_pixel_4_5);
		path_A.addPath(PATH::lcd_pixel_5_1);
		path_A.addPath(PATH::lcd_pixel_5_2);
		path_A.addPath(PATH::lcd_pixel_5_3);
		path_A.addPath(PATH::lcd_pixel_5_4);
		path_A.addPath(PATH::lcd_pixel_5_5);
		path_A.addPath(PATH::lcd_pixel_6_1);
		path_A.addPath(PATH::lcd_pixel_6_5);
		path_A.addPath(PATH::lcd_pixel_7_1);
		path_A.addPath(PATH::lcd_pixel_7_5);
		return path_A;
	}
	case (uint8)66: {
		Path path_B;
		path_B.addPath(PATH::lcd_pixel_1_1);
		path_B.addPath(PATH::lcd_pixel_1_2);
		path_B.addPath(PATH::lcd_pixel_1_3);
		path_B.addPath(PATH::lcd_pixel_1_4);
		path_B.addPath(PATH::lcd_pixel_2_1);
		path_B.addPath(PATH::lcd_pixel_2_5);
		path_B.addPath(PATH::lcd_pixel_3_1);
		path_B.addPath(PATH::lcd_pixel_3_5);
		path_B.addPath(PATH::lcd_pixel_4_1);
		path_B.addPath(PATH::lcd_pixel_4_2);
		path_B.addPath(PATH::lcd_pixel_4_3);
		path_B.addPath(PATH::lcd_pixel_4_4);
		path_B.addPath(PATH::lcd_pixel_5_1);
		path_B.addPath(PATH::lcd_pixel_5_5);
		path_B.addPath(PATH::lcd_pixel_6_1);
		path_B.addPath(PATH::lcd_pixel_6_5);
		path_B.addPath(PATH::lcd_pixel_7_1);
		path_B.addPath(PATH::lcd_pixel_7_2);
		path_B.addPath(PATH::lcd_pixel_7_3);
		path_B.addPath(PATH::lcd_pixel_7_4);
		return path_B;
	}
	case (uint8)67: {
		Path path_C;
		path_C.addPath(PATH::lcd_pixel_1_2);
		path_C.addPath(PATH::lcd_pixel_1_3);
		path_C.addPath(PATH::lcd_pixel_1_4);
		path_C.addPath(PATH::lcd_pixel_2_1);
		path_C.addPath(PATH::lcd_pixel_2_5);
		path_C.addPath(PATH::lcd_pixel_3_1);
		path_C.addPath(PATH::lcd_pixel_4_1);
		path_C.addPath(PATH::lcd_pixel_5_1);
		path_C.addPath(PATH::lcd_pixel_6_1);
		path_C.addPath(PATH::lcd_pixel_6_5);
		path_C.addPath(PATH::lcd_pixel_7_2);
		path_C.addPath(PATH::lcd_pixel_7_3);
		path_C.addPath(PATH::lcd_pixel_7_4);
		return path_C;
	}
	case (uint8)68: {
		Path path_D;
		path_D.addPath(PATH::lcd_pixel_1_1);
		path_D.addPath(PATH::lcd_pixel_1_2);
		path_D.addPath(PATH::lcd_pixel_1_3);
		path_D.addPath(PATH::lcd_pixel_2_1);
		path_D.addPath(PATH::lcd_pixel_2_4);
		path_D.addPath(PATH::lcd_pixel_3_1);
		path_D.addPath(PATH::lcd_pixel_3_5);
		path_D.addPath(PATH::lcd_pixel_4_1);
		path_D.addPath(PATH::lcd_pixel_4_5);
		path_D.addPath(PATH::lcd_pixel_5_1);
		path_D.addPath(PATH::lcd_pixel_5_5);
		path_D.addPath(PATH::lcd_pixel_6_1);
		path_D.addPath(PATH::lcd_pixel_6_4);
		path_D.addPath(PATH::lcd_pixel_7_1);
		path_D.addPath(PATH::lcd_pixel_7_2);
		path_D.addPath(PATH::lcd_pixel_7_3);
		return path_D;
	}
	case (uint8)69: {
		Path path_E;
		path_E.addPath(PATH::lcd_pixel_1_1);
		path_E.addPath(PATH::lcd_pixel_1_2);
		path_E.addPath(PATH::lcd_pixel_1_3);
		path_E.addPath(PATH::lcd_pixel_1_4);
		path_E.addPath(PATH::lcd_pixel_1_5);
		path_E.addPath(PATH::lcd_pixel_2_1);
		path_E.addPath(PATH::lcd_pixel_3_1);
		path_E.addPath(PATH::lcd_pixel_4_1);
		path_E.addPath(PATH::lcd_pixel_4_2);
		path_E.addPath(PATH::lcd_pixel_4_3);
		path_E.addPath(PATH::lcd_pixel_4_4);
		path_E.addPath(PATH::lcd_pixel_5_1);
		path_E.addPath(PATH::lcd_pixel_6_1);
		path_E.addPath(PATH::lcd_pixel_7_1);
		path_E.addPath(PATH::lcd_pixel_7_2);
		path_E.addPath(PATH::lcd_pixel_7_3);
		path_E.addPath(PATH::lcd_pixel_7_4);
		path_E.addPath(PATH::lcd_pixel_7_5);
		return path_E;
	}
	case (uint8)70: {
		Path path_F;
		path_F.addPath(PATH::lcd_pixel_1_1);
		path_F.addPath(PATH::lcd_pixel_1_2);
		path_F.addPath(PATH::lcd_pixel_1_3);
		path_F.addPath(PATH::lcd_pixel_1_4);
		path_F.addPath(PATH::lcd_pixel_1_5);
		path_F.addPath(PATH::lcd_pixel_2_1);
		path_F.addPath(PATH::lcd_pixel_3_1);
		path_F.addPath(PATH::lcd_pixel_4_1);
		path_F.addPath(PATH::lcd_pixel_4_2);
		path_F.addPath(PATH::lcd_pixel_4_3);
		path_F.addPath(PATH::lcd_pixel_4_4);
		path_F.addPath(PATH::lcd_pixel_5_1);
		path_F.addPath(PATH::lcd_pixel_6_1);
		path_F.addPath(PATH::lcd_pixel_7_1);
		return path_F;
	}
	case (uint8)71: {
		Path path_G;
		path_G.addPath(PATH::lcd_pixel_1_2);
		path_G.addPath(PATH::lcd_pixel_1_3);
		path_G.addPath(PATH::lcd_pixel_1_4);
		path_G.addPath(PATH::lcd_pixel_2_1);
		path_G.addPath(PATH::lcd_pixel_2_5);
		path_G.addPath(PATH::lcd_pixel_3_1);
		path_G.addPath(PATH::lcd_pixel_4_1);
		path_G.addPath(PATH::lcd_pixel_4_3);
		path_G.addPath(PATH::lcd_pixel_4_4);
		path_G.addPath(PATH::lcd_pixel_4_5);
		path_G.addPath(PATH::lcd_pixel_5_1);
		path_G.addPath(PATH::lcd_pixel_5_5);
		path_G.addPath(PATH::lcd_pixel_6_1);
		path_G.addPath(PATH::lcd_pixel_6_5);
		path_G.addPath(PATH::lcd_pixel_7_2);
		path_G.addPath(PATH::lcd_pixel_7_3);
		path_G.addPath(PATH::lcd_pixel_7_4);
		path_G.addPath(PATH::lcd_pixel_7_5);
		return path_G;
	}
	case (uint8)72: {
		Path path_H;
		path_H.addPath(PATH::lcd_pixel_1_1);
		path_H.addPath(PATH::lcd_pixel_1_5);
		path_H.addPath(PATH::lcd_pixel_2_1);
		path_H.addPath(PATH::lcd_pixel_2_5);
		path_H.addPath(PATH::lcd_pixel_3_1);
		path_H.addPath(PATH::lcd_pixel_3_5);
		path_H.addPath(PATH::lcd_pixel_4_1);
		path_H.addPath(PATH::lcd_pixel_4_2);
		path_H.addPath(PATH::lcd_pixel_4_3);
		path_H.addPath(PATH::lcd_pixel_4_4);
		path_H.addPath(PATH::lcd_pixel_4_5);
		path_H.addPath(PATH::lcd_pixel_5_1);
		path_H.addPath(PATH::lcd_pixel_5_5);
		path_H.addPath(PATH::lcd_pixel_6_1);
		path_H.addPath(PATH::lcd_pixel_6_5);
		path_H.addPath(PATH::lcd_pixel_7_1);
		path_H.addPath(PATH::lcd_pixel_7_5);
		return path_H;
	}
	case (uint8)73: {
		Path path_I;
		path_I.addPath(PATH::lcd_pixel_1_2);
		path_I.addPath(PATH::lcd_pixel_1_3);
		path_I.addPath(PATH::lcd_pixel_1_4);
		path_I.addPath(PATH::lcd_pixel_2_3);
		path_I.addPath(PATH::lcd_pixel_3_3);
		path_I.addPath(PATH::lcd_pixel_4_3);
		path_I.addPath(PATH::lcd_pixel_5_3);
		path_I.addPath(PATH::lcd_pixel_6_3);
		path_I.addPath(PATH::lcd_pixel_7_2);
		path_I.addPath(PATH::lcd_pixel_7_3);
		path_I.addPath(PATH::lcd_pixel_7_4);
		return path_I;
	}
	case (uint8)74: {
		Path path_J;
		path_J.addPath(PATH::lcd_pixel_1_3);
		path_J.addPath(PATH::lcd_pixel_1_4);
		path_J.addPath(PATH::lcd_pixel_1_5);
		path_J.addPath(PATH::lcd_pixel_2_4);
		path_J.addPath(PATH::lcd_pixel_3_4);
		path_J.addPath(PATH::lcd_pixel_4_4);
		path_J.addPath(PATH::lcd_pixel_5_4);
		path_J.addPath(PATH::lcd_pixel_6_1);
		path_J.addPath(PATH::lcd_pixel_6_4);
		path_J.addPath(PATH::lcd_pixel_7_2);
		path_J.addPath(PATH::lcd_pixel_7_3);
		return path_J;
	}
	case (uint8)75: {
		Path path_K;
		path_K.addPath(PATH::lcd_pixel_1_1);
		path_K.addPath(PATH::lcd_pixel_1_5);
		path_K.addPath(PATH::lcd_pixel_2_1);
		path_K.addPath(PATH::lcd_pixel_2_4);
		path_K.addPath(PATH::lcd_pixel_3_1);
		path_K.addPath(PATH::lcd_pixel_3_3);
		path_K.addPath(PATH::lcd_pixel_4_1);
		path_K.addPath(PATH::lcd_pixel_4_2);
		path_K.addPath(PATH::lcd_pixel_5_1);
		path_K.addPath(PATH::lcd_pixel_5_3);
		path_K.addPath(PATH::lcd_pixel_6_1);
		path_K.addPath(PATH::lcd_pixel_6_4);
		path_K.addPath(PATH::lcd_pixel_7_1);
		path_K.addPath(PATH::lcd_pixel_7_5);
		return path_K;
	}
	case (uint8)76: {
		Path path_L;
		path_L.addPath(PATH::lcd_pixel_1_1);
		path_L.addPath(PATH::lcd_pixel_2_1);
		path_L.addPath(PATH::lcd_pixel_3_1);
		path_L.addPath(PATH::lcd_pixel_4_1);
		path_L.addPath(PATH::lcd_pixel_5_1);
		path_L.addPath(PATH::lcd_pixel_6_1);
		path_L.addPath(PATH::lcd_pixel_7_1);
		path_L.addPath(PATH::lcd_pixel_7_2);
		path_L.addPath(PATH::lcd_pixel_7_3);
		path_L.addPath(PATH::lcd_pixel_7_4);
		path_L.addPath(PATH::lcd_pixel_7_5);
		return path_L;
	}
	case (uint8)77: {
		Path path_M;
		path_M.addPath(PATH::lcd_pixel_1_1);
		path_M.addPath(PATH::lcd_pixel_1_5);
		path_M.addPath(PATH::lcd_pixel_2_1);
		path_M.addPath(PATH::lcd_pixel_2_2);
		path_M.addPath(PATH::lcd_pixel_2_4);
		path_M.addPath(PATH::lcd_pixel_2_5);
		path_M.addPath(PATH::lcd_pixel_3_1);
		path_M.addPath(PATH::lcd_pixel_3_3);
		path_M.addPath(PATH::lcd_pixel_3_5);
		path_M.addPath(PATH::lcd_pixel_4_1);
		path_M.addPath(PATH::lcd_pixel_4_3);
		path_M.addPath(PATH::lcd_pixel_4_5);
		path_M.addPath(PATH::lcd_pixel_5_1);
		path_M.addPath(PATH::lcd_pixel_5_5);
		path_M.addPath(PATH::lcd_pixel_6_1);
		path_M.addPath(PATH::lcd_pixel_6_5);
		path_M.addPath(PATH::lcd_pixel_7_1);
		path_M.addPath(PATH::lcd_pixel_7_5);
		return path_M;
	}
	case (uint8)78: {
		Path path_N;
		path_N.addPath(PATH::lcd_pixel_1_1);
		path_N.addPath(PATH::lcd_pixel_1_5);
		path_N.addPath(PATH::lcd_pixel_2_1);
		path_N.addPath(PATH::lcd_pixel_2_5);
		path_N.addPath(PATH::lcd_pixel_3_1);
		path_N.addPath(PATH::lcd_pixel_3_2);
		path_N.addPath(PATH::lcd_pixel_3_5);
		path_N.addPath(PATH::lcd_pixel_4_1);
		path_N.addPath(PATH::lcd_pixel_4_3);
		path_N.addPath(PATH::lcd_pixel_4_5);
		path_N.addPath(PATH::lcd_pixel_5_1);
		path_N.addPath(PATH::lcd_pixel_5_4);
		path_N.addPath(PATH::lcd_pixel_5_5);
		path_N.addPath(PATH::lcd_pixel_6_1);
		path_N.addPath(PATH::lcd_pixel_6_5);
		path_N.addPath(PATH::lcd_pixel_7_1);
		path_N.addPath(PATH::lcd_pixel_7_5);
		return path_N;
	}
	case (uint8)79: {
		Path path_O;
		path_O.addPath(PATH::lcd_pixel_1_2);
		path_O.addPath(PATH::lcd_pixel_1_3);
		path_O.addPath(PATH::lcd_pixel_1_4);
		path_O.addPath(PATH::lcd_pixel_2_1);
		path_O.addPath(PATH::lcd_pixel_2_5);
		path_O.addPath(PATH::lcd_pixel_3_1);
		path_O.addPath(PATH::lcd_pixel_3_5);
		path_O.addPath(PATH::lcd_pixel_4_1);
		path_O.addPath(PATH::lcd_pixel_4_5);
		path_O.addPath(PATH::lcd_pixel_5_1);
		path_O.addPath(PATH::lcd_pixel_5_5);
		path_O.addPath(PATH::lcd_pixel_6_1);
		path_O.addPath(PATH::lcd_pixel_6_5);
		path_O.addPath(PATH::lcd_pixel_7_2);
		path_O.addPath(PATH::lcd_pixel_7_3);
		path_O.addPath(PATH::lcd_pixel_7_4);
		return path_O;
	}
	case (uint8)80: {
		Path path_P;
		path_P.addPath(PATH::lcd_pixel_1_1);
		path_P.addPath(PATH::lcd_pixel_1_2);
		path_P.addPath(PATH::lcd_pixel_1_3);
		path_P.addPath(PATH::lcd_pixel_1_4);
		path_P.addPath(PATH::lcd_pixel_2_1);
		path_P.addPath(PATH::lcd_pixel_2_5);
		path_P.addPath(PATH::lcd_pixel_3_1);
		path_P.addPath(PATH::lcd_pixel_3_5);
		path_P.addPath(PATH::lcd_pixel_4_1);
		path_P.addPath(PATH::lcd_pixel_4_2);
		path_P.addPath(PATH::lcd_pixel_4_3);
		path_P.addPath(PATH::lcd_pixel_4_4);
		path_P.addPath(PATH::lcd_pixel_5_1);
		path_P.addPath(PATH::lcd_pixel_6_1);
		path_P.addPath(PATH::lcd_pixel_7_1);
		return path_P;
	}
	case (uint8)81: {
		Path path_Q;
		path_Q.addPath(PATH::lcd_pixel_1_2);
		path_Q.addPath(PATH::lcd_pixel_1_3);
		path_Q.addPath(PATH::lcd_pixel_1_4);
		path_Q.addPath(PATH::lcd_pixel_2_1);
		path_Q.addPath(PATH::lcd_pixel_2_5);
		path_Q.addPath(PATH::lcd_pixel_3_1);
		path_Q.addPath(PATH::lcd_pixel_3_5);
		path_Q.addPath(PATH::lcd_pixel_4_1);
		path_Q.addPath(PATH::lcd_pixel_4_5);
		path_Q.addPath(PATH::lcd_pixel_5_1);
		path_Q.addPath(PATH::lcd_pixel_5_3);
		path_Q.addPath(PATH::lcd_pixel_5_5);
		path_Q.addPath(PATH::lcd_pixel_6_1);
		path_Q.addPath(PATH::lcd_pixel_6_4);
		path_Q.addPath(PATH::lcd_pixel_7_2);
		path_Q.addPath(PATH::lcd_pixel_7_3);
		path_Q.addPath(PATH::lcd_pixel_7_5);
		return path_Q;
	}
	case (uint8)82: {
		Path path_R;
		path_R.addPath(PATH::lcd_pixel_1_1);
		path_R.addPath(PATH::lcd_pixel_1_2);
		path_R.addPath(PATH::lcd_pixel_1_3);
		path_R.addPath(PATH::lcd_pixel_1_4);
		path_R.addPath(PATH::lcd_pixel_2_1);
		path_R.addPath(PATH::lcd_pixel_2_5);
		path_R.addPath(PATH::lcd_pixel_3_1);
		path_R.addPath(PATH::lcd_pixel_3_5);
		path_R.addPath(PATH::lcd_pixel_4_1);
		path_R.addPath(PATH::lcd_pixel_4_2);
		path_R.addPath(PATH::lcd_pixel_4_3);
		path_R.addPath(PATH::lcd_pixel_4_4);
		path_R.addPath(PATH::lcd_pixel_5_1);
		path_R.addPath(PATH::lcd_pixel_5_3);
		path_R.addPath(PATH::lcd_pixel_6_1);
		path_R.addPath(PATH::lcd_pixel_6_4);
		path_R.addPath(PATH::lcd_pixel_7_1);
		path_R.addPath(PATH::lcd_pixel_7_5);
		return path_R;
	}
	case (uint8)83: {
		Path path_S;
		path_S.addPath(PATH::lcd_pixel_1_2);
		path_S.addPath(PATH::lcd_pixel_1_3);
		path_S.addPath(PATH::lcd_pixel_1_4);
		path_S.addPath(PATH::lcd_pixel_1_5);
		path_S.addPath(PATH::lcd_pixel_2_1);
		path_S.addPath(PATH::lcd_pixel_3_1);
		path_S.addPath(PATH::lcd_pixel_4_2);
		path_S.addPath(PATH::lcd_pixel_4_3);
		path_S.addPath(PATH::lcd_pixel_4_4);
		path_S.addPath(PATH::lcd_pixel_5_5);
		path_S.addPath(PATH::lcd_pixel_6_5);
		path_S.addPath(PATH::lcd_pixel_7_1);
		path_S.addPath(PATH::lcd_pixel_7_2);
		path_S.addPath(PATH::lcd_pixel_7_3);
		path_S.addPath(PATH::lcd_pixel_7_4);
		return path_S;
	}
	case (uint8)84: {
		Path path_T;
		path_T.addPath(PATH::lcd_pixel_1_1);
		path_T.addPath(PATH::lcd_pixel_1_2);
		path_T.addPath(PATH::lcd_pixel_1_3);
		path_T.addPath(PATH::lcd_pixel_1_4);
		path_T.addPath(PATH::lcd_pixel_1_5);
		path_T.addPath(PATH::lcd_pixel_2_3);
		path_T.addPath(PATH::lcd_pixel_3_3);
		path_T.addPath(PATH::lcd_pixel_4_3);
		path_T.addPath(PATH::lcd_pixel_5_3);
		path_T.addPath(PATH::lcd_pixel_6_3);
		path_T.addPath(PATH::lcd_pixel_7_3);
		return path_T;
	}
	case (uint8)85: {
		Path path_U;
		path_U.addPath(PATH::lcd_pixel_1_1);
		path_U.addPath(PATH::lcd_pixel_1_5);
		path_U.addPath(PATH::lcd_pixel_2_1);
		path_U.addPath(PATH::lcd_pixel_2_5);
		path_U.addPath(PATH::lcd_pixel_3_1);
		path_U.addPath(PATH::lcd_pixel_3_5);
		path_U.addPath(PATH::lcd_pixel_4_1);
		path_U.addPath(PATH::lcd_pixel_4_5);
		path_U.addPath(PATH::lcd_pixel_5_1);
		path_U.addPath(PATH::lcd_pixel_5_5);
		path_U.addPath(PATH::lcd_pixel_6_1);
		path_U.addPath(PATH::lcd_pixel_6_5);
		path_U.addPath(PATH::lcd_pixel_7_2);
		path_U.addPath(PATH::lcd_pixel_7_3);
		path_U.addPath(PATH::lcd_pixel_7_4);
		return path_U;
	}
	case (uint8)86: {
		Path path_V;
		path_V.addPath(PATH::lcd_pixel_1_1);
		path_V.addPath(PATH::lcd_pixel_1_5);
		path_V.addPath(PATH::lcd_pixel_2_1);
		path_V.addPath(PATH::lcd_pixel_2_5);
		path_V.addPath(PATH::lcd_pixel_3_1);
		path_V.addPath(PATH::lcd_pixel_3_5);
		path_V.addPath(PATH::lcd_pixel_4_1);
		path_V.addPath(PATH::lcd_pixel_4_5);
		path_V.addPath(PATH::lcd_pixel_5_1);
		path_V.addPath(PATH::lcd_pixel_5_5);
		path_V.addPath(PATH::lcd_pixel_6_2);
		path_V.addPath(PATH::lcd_pixel_6_4);
		path_V.addPath(PATH::lcd_pixel_7_3);
		return path_V;
	}
	case (uint8)87: {
		Path path_W;
		path_W.addPath(PATH::lcd_pixel_1_1);
		path_W.addPath(PATH::lcd_pixel_1_5);
		path_W.addPath(PATH::lcd_pixel_2_1);
		path_W.addPath(PATH::lcd_pixel_2_5);
		path_W.addPath(PATH::lcd_pixel_3_1);
		path_W.addPath(PATH::lcd_pixel_3_5);
		path_W.addPath(PATH::lcd_pixel_4_1);
		path_W.addPath(PATH::lcd_pixel_4_3);
		path_W.addPath(PATH::lcd_pixel_4_5);
		path_W.addPath(PATH::lcd_pixel_5_1);
		path_W.addPath(PATH::lcd_pixel_5_3);
		path_W.addPath(PATH::lcd_pixel_5_5);
		path_W.addPath(PATH::lcd_pixel_6_1);
		path_W.addPath(PATH::lcd_pixel_6_3);
		path_W.addPath(PATH::lcd_pixel_6_5);
		path_W.addPath(PATH::lcd_pixel_7_2);
		path_W.addPath(PATH::lcd_pixel_7_4);
		return path_W;
	}
	case (uint8)88: {
		Path path_X;
		path_X.addPath(PATH::lcd_pixel_1_1);
		path_X.addPath(PATH::lcd_pixel_1_5);
		path_X.addPath(PATH::lcd_pixel_2_1);
		path_X.addPath(PATH::lcd_pixel_2_5);
		path_X.addPath(PATH::lcd_pixel_3_2);
		path_X.addPath(PATH::lcd_pixel_3_4);
		path_X.addPath(PATH::lcd_pixel_4_3);
		path_X.addPath(PATH::lcd_pixel_5_2);
		path_X.addPath(PATH::lcd_pixel_5_4);
		path_X.addPath(PATH::lcd_pixel_6_1);
		path_X.addPath(PATH::lcd_pixel_6_5);
		path_X.addPath(PATH::lcd_pixel_7_1);
		path_X.addPath(PATH::lcd_pixel_7_5);
		return path_X;
	}
	case (uint8)89: {
		Path path_Y;
		path_Y.addPath(PATH::lcd_pixel_1_1);
		path_Y.addPath(PATH::lcd_pixel_1_5);
		path_Y.addPath(PATH::lcd_pixel_2_1);
		path_Y.addPath(PATH::lcd_pixel_2_5);
		path_Y.addPath(PATH::lcd_pixel_3_1);
		path_Y.addPath(PATH::lcd_pixel_3_5);
		path_Y.addPath(PATH::lcd_pixel_4_2);
		path_Y.addPath(PATH::lcd_pixel_4_4);
		path_Y.addPath(PATH::lcd_pixel_5_3);
		path_Y.addPath(PATH::lcd_pixel_6_3);
		path_Y.addPath(PATH::lcd_pixel_7_3);
		return path_Y;
	}
	case (uint8)90: {
		Path path_Z;
		path_Z.addPath(PATH::lcd_pixel_1_1);
		path_Z.addPath(PATH::lcd_pixel_1_2);
		path_Z.addPath(PATH::lcd_pixel_1_3);
		path_Z.addPath(PATH::lcd_pixel_1_4);
		path_Z.addPath(PATH::lcd_pixel_1_5);
		path_Z.addPath(PATH::lcd_pixel_2_5);
		path_Z.addPath(PATH::lcd_pixel_3_4);
		path_Z.addPath(PATH::lcd_pixel_4_3);
		path_Z.addPath(PATH::lcd_pixel_5_2);
		path_Z.addPath(PATH::lcd_pixel_6_1);
		path_Z.addPath(PATH::lcd_pixel_7_1);
		path_Z.addPath(PATH::lcd_pixel_7_2);
		path_Z.addPath(PATH::lcd_pixel_7_3);
		path_Z.addPath(PATH::lcd_pixel_7_4);
		path_Z.addPath(PATH::lcd_pixel_7_5);
		return path_Z;
	}
	case (uint8)91: {
		Path path_open_bracket;
		path_open_bracket.addPath(PATH::lcd_pixel_1_2);
		path_open_bracket.addPath(PATH::lcd_pixel_1_3);
		path_open_bracket.addPath(PATH::lcd_pixel_1_4);
		path_open_bracket.addPath(PATH::lcd_pixel_2_2);
		path_open_bracket.addPath(PATH::lcd_pixel_3_2);
		path_open_bracket.addPath(PATH::lcd_pixel_4_2);
		path_open_bracket.addPath(PATH::lcd_pixel_5_2);
		path_open_bracket.addPath(PATH::lcd_pixel_6_2);
		path_open_bracket.addPath(PATH::lcd_pixel_7_2);
		path_open_bracket.addPath(PATH::lcd_pixel_7_3);
		path_open_bracket.addPath(PATH::lcd_pixel_7_4);
		return path_open_bracket;
	}
	case (uint8)92: {
		Path path_yen;
		path_yen.addPath(PATH::lcd_pixel_1_1);
		path_yen.addPath(PATH::lcd_pixel_1_5);
		path_yen.addPath(PATH::lcd_pixel_2_2);
		path_yen.addPath(PATH::lcd_pixel_2_4);
		path_yen.addPath(PATH::lcd_pixel_3_1);
		path_yen.addPath(PATH::lcd_pixel_3_2);
		path_yen.addPath(PATH::lcd_pixel_3_3);
		path_yen.addPath(PATH::lcd_pixel_3_4);
		path_yen.addPath(PATH::lcd_pixel_3_5);
		path_yen.addPath(PATH::lcd_pixel_4_3);
		path_yen.addPath(PATH::lcd_pixel_5_1);
		path_yen.addPath(PATH::lcd_pixel_5_2);
		path_yen.addPath(PATH::lcd_pixel_5_3);
		path_yen.addPath(PATH::lcd_pixel_5_4);
		path_yen.addPath(PATH::lcd_pixel_5_5);
		path_yen.addPath(PATH::lcd_pixel_6_3);
		path_yen.addPath(PATH::lcd_pixel_7_3);
		return path_yen;
	}
	case (uint8)93: {
		Path path_close_bracket;
		path_close_bracket.addPath(PATH::lcd_pixel_1_2);
		path_close_bracket.addPath(PATH::lcd_pixel_1_3);
		path_close_bracket.addPath(PATH::lcd_pixel_1_4);
		path_close_bracket.addPath(PATH::lcd_pixel_2_4);
		path_close_bracket.addPath(PATH::lcd_pixel_3_4);
		path_close_bracket.addPath(PATH::lcd_pixel_4_4);
		path_close_bracket.addPath(PATH::lcd_pixel_5_4);
		path_close_bracket.addPath(PATH::lcd_pixel_6_4);
		path_close_bracket.addPath(PATH::lcd_pixel_7_2);
		path_close_bracket.addPath(PATH::lcd_pixel_7_3);
		path_close_bracket.addPath(PATH::lcd_pixel_7_4);
		return path_close_bracket;
	}
	case (uint8)94: {
		Path path_caret;
		path_caret.addPath(PATH::lcd_pixel_1_3);
		path_caret.addPath(PATH::lcd_pixel_2_2);
		path_caret.addPath(PATH::lcd_pixel_2_4);
		path_caret.addPath(PATH::lcd_pixel_3_1);
		path_caret.addPath(PATH::lcd_pixel_3_5);
		return path_caret;
	}
	case (uint8)95: {
		Path path_underscore;
		path_underscore.addPath(PATH::lcd_pixel_7_1);
		path_underscore.addPath(PATH::lcd_pixel_7_2);
		path_underscore.addPath(PATH::lcd_pixel_7_3);
		path_underscore.addPath(PATH::lcd_pixel_7_4);
		path_underscore.addPath(PATH::lcd_pixel_7_5);
		return path_underscore;
	}
	case (uint8)96: {
		Path path_grave_accent;
		path_grave_accent.addPath(PATH::lcd_pixel_1_2);
		path_grave_accent.addPath(PATH::lcd_pixel_2_3);
		path_grave_accent.addPath(PATH::lcd_pixel_3_4);
		return path_grave_accent;
	}
	case (uint8)97: {
		Path path_a;
		path_a.addPath(PATH::lcd_pixel_3_2);
		path_a.addPath(PATH::lcd_pixel_3_3);
		path_a.addPath(PATH::lcd_pixel_3_4);
		path_a.addPath(PATH::lcd_pixel_4_5);
		path_a.addPath(PATH::lcd_pixel_5_2);
		path_a.addPath(PATH::lcd_pixel_5_3);
		path_a.addPath(PATH::lcd_pixel_5_4);
		path_a.addPath(PATH::lcd_pixel_5_5);
		path_a.addPath(PATH::lcd_pixel_6_1);
		path_a.addPath(PATH::lcd_pixel_6_5);
		path_a.addPath(PATH::lcd_pixel_7_2);
		path_a.addPath(PATH::lcd_pixel_7_3);
		path_a.addPath(PATH::lcd_pixel_7_4);
		path_a.addPath(PATH::lcd_pixel_7_5);
		return path_a;
	}
	case (uint8)98: {
		Path path_b;
		path_b.addPath(PATH::lcd_pixel_1_1);
		path_b.addPath(PATH::lcd_pixel_2_1);
		path_b.addPath(PATH::lcd_pixel_3_1);
		path_b.addPath(PATH::lcd_pixel_3_3);
		path_b.addPath(PATH::lcd_pixel_3_4);
		path_b.addPath(PATH::lcd_pixel_4_1);
		path_b.addPath(PATH::lcd_pixel_4_2);
		path_b.addPath(PATH::lcd_pixel_4_5);
		path_b.addPath(PATH::lcd_pixel_5_1);
		path_b.addPath(PATH::lcd_pixel_5_5);
		path_b.addPath(PATH::lcd_pixel_6_1);
		path_b.addPath(PATH::lcd_pixel_6_5);
		path_b.addPath(PATH::lcd_pixel_7_1);
		path_b.addPath(PATH::lcd_pixel_7_2);
		path_b.addPath(PATH::lcd_pixel_7_3);
		path_b.addPath(PATH::lcd_pixel_7_4);
		return path_b;
	}
	case (uint8)99: {
		Path path_c;
		path_c.addPath(PATH::lcd_pixel_3_2);
		path_c.addPath(PATH::lcd_pixel_3_3);
		path_c.addPath(PATH::lcd_pixel_3_4);
		path_c.addPath(PATH::lcd_pixel_4_1);
		path_c.addPath(PATH::lcd_pixel_5_1);
		path_c.addPath(PATH::lcd_pixel_6_1);
		path_c.addPath(PATH::lcd_pixel_6_5);
		path_c.addPath(PATH::lcd_pixel_7_2);
		path_c.addPath(PATH::lcd_pixel_7_3);
		path_c.addPath(PATH::lcd_pixel_7_4);
		return path_c;
	}
	case (uint8)100: {
		Path path_d;
		path_d.addPath(PATH::lcd_pixel_1_5);
		path_d.addPath(PATH::lcd_pixel_2_5);
		path_d.addPath(PATH::lcd_pixel_3_2);
		path_d.addPath(PATH::lcd_pixel_3_3);
		path_d.addPath(PATH::lcd_pixel_3_5);
		path_d.addPath(PATH::lcd_pixel_4_1);
		path_d.addPath(PATH::lcd_pixel_4_4);
		path_d.addPath(PATH::lcd_pixel_4_5);
		path_d.addPath(PATH::lcd_pixel_5_1);
		path_d.addPath(PATH::lcd_pixel_5_5);
		path_d.addPath(PATH::lcd_pixel_6_1);
		path_d.addPath(PATH::lcd_pixel_6_5);
		path_d.addPath(PATH::lcd_pixel_7_2);
		path_d.addPath(PATH::lcd_pixel_7_3);
		path_d.addPath(PATH::lcd_pixel_7_4);
		path_d.addPath(PATH::lcd_pixel_7_5);
		return path_d;
	}
	case (uint8)101: {
		Path path_e;
		path_e.addPath(PATH::lcd_pixel_3_2);
		path_e.addPath(PATH::lcd_pixel_3_3);
		path_e.addPath(PATH::lcd_pixel_3_4);
		path_e.addPath(PATH::lcd_pixel_4_1);
		path_e.addPath(PATH::lcd_pixel_4_5);
		path_e.addPath(PATH::lcd_pixel_5_1);
		path_e.addPath(PATH::lcd_pixel_5_2);
		path_e.addPath(PATH::lcd_pixel_5_3);
		path_e.addPath(PATH::lcd_pixel_5_4);
		path_e.addPath(PATH::lcd_pixel_5_5);
		path_e.addPath(PATH::lcd_pixel_6_1);
		path_e.addPath(PATH::lcd_pixel_7_2);
		path_e.addPath(PATH::lcd_pixel_7_3);
		path_e.addPath(PATH::lcd_pixel_7_4);
		return path_e;
	}
	case (uint8)102: {
		Path path_f;
		path_f.addPath(PATH::lcd_pixel_1_3);
		path_f.addPath(PATH::lcd_pixel_1_4);
		path_f.addPath(PATH::lcd_pixel_2_2);
		path_f.addPath(PATH::lcd_pixel_2_5);
		path_f.addPath(PATH::lcd_pixel_3_2);
		path_f.addPath(PATH::lcd_pixel_4_1);
		path_f.addPath(PATH::lcd_pixel_4_2);
		path_f.addPath(PATH::lcd_pixel_4_3);
		path_f.addPath(PATH::lcd_pixel_5_2);
		path_f.addPath(PATH::lcd_pixel_6_2);
		path_f.addPath(PATH::lcd_pixel_7_2);
		return path_f;
	}
	case (uint8)103: {
		Path path_g;
		path_g.addPath(PATH::lcd_pixel_2_2);
		path_g.addPath(PATH::lcd_pixel_2_3);
		path_g.addPath(PATH::lcd_pixel_2_4);
		path_g.addPath(PATH::lcd_pixel_2_5);
		path_g.addPath(PATH::lcd_pixel_3_1);
		path_g.addPath(PATH::lcd_pixel_3_5);
		path_g.addPath(PATH::lcd_pixel_4_1);
		path_g.addPath(PATH::lcd_pixel_4_5);
		path_g.addPath(PATH::lcd_pixel_5_2);
		path_g.addPath(PATH::lcd_pixel_5_3);
		path_g.addPath(PATH::lcd_pixel_5_4);
		path_g.addPath(PATH::lcd_pixel_5_5);
		path_g.addPath(PATH::lcd_pixel_6_5);
		path_g.addPath(PATH::lcd_pixel_7_2);
		path_g.addPath(PATH::lcd_pixel_7_3);
		path_g.addPath(PATH::lcd_pixel_7_4);
		return path_g;
	}
	case (uint8)104: {
		Path path_h;
		path_h.addPath(PATH::lcd_pixel_1_1);
		path_h.addPath(PATH::lcd_pixel_2_1);
		path_h.addPath(PATH::lcd_pixel_3_1);
		path_h.addPath(PATH::lcd_pixel_3_3);
		path_h.addPath(PATH::lcd_pixel_3_4);
		path_h.addPath(PATH::lcd_pixel_4_1);
		path_h.addPath(PATH::lcd_pixel_4_2);
		path_h.addPath(PATH::lcd_pixel_4_5);
		path_h.addPath(PATH::lcd_pixel_5_1);
		path_h.addPath(PATH::lcd_pixel_5_5);
		path_h.addPath(PATH::lcd_pixel_6_1);
		path_h.addPath(PATH::lcd_pixel_6_5);
		path_h.addPath(PATH::lcd_pixel_7_1);
		path_h.addPath(PATH::lcd_pixel_7_5);
		return path_h;
	}
	case (uint8)105: {
		Path path_i;
		path_i.addPath(PATH::lcd_pixel_1_3);
		path_i.addPath(PATH::lcd_pixel_3_2);
		path_i.addPath(PATH::lcd_pixel_3_3);
		path_i.addPath(PATH::lcd_pixel_4_3);
		path_i.addPath(PATH::lcd_pixel_5_3);
		path_i.addPath(PATH::lcd_pixel_6_3);
		path_i.addPath(PATH::lcd_pixel_7_3);
		return path_i;
	}
	case (uint8)106: {
		Path path_j;
		path_j.addPath(PATH::lcd_pixel_1_4);
		path_j.addPath(PATH::lcd_pixel_3_3);
		path_j.addPath(PATH::lcd_pixel_3_4);
		path_j.addPath(PATH::lcd_pixel_4_4);
		path_j.addPath(PATH::lcd_pixel_5_4);
		path_j.addPath(PATH::lcd_pixel_6_1);
		path_j.addPath(PATH::lcd_pixel_6_4);
		path_j.addPath(PATH::lcd_pixel_7_2);
		path_j.addPath(PATH::lcd_pixel_7_3);
		return path_j;
	}
	case (uint8)107: {
		Path path_k;
		path_k.addPath(PATH::lcd_pixel_1_1);
		path_k.addPath(PATH::lcd_pixel_2_1);
		path_k.addPath(PATH::lcd_pixel_3_1);
		path_k.addPath(PATH::lcd_pixel_3_4);
		path_k.addPath(PATH::lcd_pixel_4_1);
		path_k.addPath(PATH::lcd_pixel_4_3);
		path_k.addPath(PATH::lcd_pixel_5_1);
		path_k.addPath(PATH::lcd_pixel_5_2);
		path_k.addPath(PATH::lcd_pixel_6_1);
		path_k.addPath(PATH::lcd_pixel_6_3);
		path_k.addPath(PATH::lcd_pixel_7_1);
		path_k.addPath(PATH::lcd_pixel_7_4);
		return path_k;
	}
	case (uint8)108: {
		Path path_l;
		path_l.addPath(PATH::lcd_pixel_1_2);
		path_l.addPath(PATH::lcd_pixel_1_3);
		path_l.addPath(PATH::lcd_pixel_2_3);
		path_l.addPath(PATH::lcd_pixel_3_3);
		path_l.addPath(PATH::lcd_pixel_4_3);
		path_l.addPath(PATH::lcd_pixel_5_3);
		path_l.addPath(PATH::lcd_pixel_6_3);
		path_l.addPath(PATH::lcd_pixel_7_2);
		path_l.addPath(PATH::lcd_pixel_7_3);
		path_l.addPath(PATH::lcd_pixel_7_4);
		return path_l;
	}
	case (uint8)109: {
		Path path_m;
		path_m.addPath(PATH::lcd_pixel_3_1);
		path_m.addPath(PATH::lcd_pixel_3_2);
		path_m.addPath(PATH::lcd_pixel_3_4);
		path_m.addPath(PATH::lcd_pixel_4_1);
		path_m.addPath(PATH::lcd_pixel_4_3);
		path_m.addPath(PATH::lcd_pixel_4_5);
		path_m.addPath(PATH::lcd_pixel_5_1);
		path_m.addPath(PATH::lcd_pixel_5_3);
		path_m.addPath(PATH::lcd_pixel_5_5);
		path_m.addPath(PATH::lcd_pixel_6_1);
		path_m.addPath(PATH::lcd_pixel_6_5);
		path_m.addPath(PATH::lcd_pixel_7_1);
		path_m.addPath(PATH::lcd_pixel_7_5);
		return path_m;
	}
	case (uint8)110: {
		Path path_n;
		path_n.addPath(PATH::lcd_pixel_3_1);
		path_n.addPath(PATH::lcd_pixel_3_3);
		path_n.addPath(PATH::lcd_pixel_3_4);
		path_n.addPath(PATH::lcd_pixel_4_1);
		path_n.addPath(PATH::lcd_pixel_4_2);
		path_n.addPath(PATH::lcd_pixel_4_5);
		path_n.addPath(PATH::lcd_pixel_5_1);
		path_n.addPath(PATH::lcd_pixel_5_5);
		path_n.addPath(PATH::lcd_pixel_6_1);
		path_n.addPath(PATH::lcd_pixel_6_5);
		path_n.addPath(PATH::lcd_pixel_7_1);
		path_n.addPath(PATH::lcd_pixel_7_5);
		return path_n;
	}
	case (uint8)111: {
		Path path_o;
		path_o.addPath(PATH::lcd_pixel_3_2);
		path_o.addPath(PATH::lcd_pixel_3_3);
		path_o.addPath(PATH::lcd_pixel_3_4);
		path_o.addPath(PATH::lcd_pixel_4_1);
		path_o.addPath(PATH::lcd_pixel_4_5);
		path_o.addPath(PATH::lcd_pixel_5_1);
		path_o.addPath(PATH::lcd_pixel_5_5);
		path_o.addPath(PATH::lcd_pixel_6_1);
		path_o.addPath(PATH::lcd_pixel_6_5);
		path_o.addPath(PATH::lcd_pixel_7_2);
		path_o.addPath(PATH::lcd_pixel_7_3);
		path_o.addPath(PATH::lcd_pixel_7_4);
		return path_o;
	}
	case (uint8)112: {
		Path path_p;
		path_p.addPath(PATH::lcd_pixel_3_1);
		path_p.addPath(PATH::lcd_pixel_3_2);
		path_p.addPath(PATH::lcd_pixel_3_3);
		path_p.addPath(PATH::lcd_pixel_3_4);
		path_p.addPath(PATH::lcd_pixel_4_1);
		path_p.addPath(PATH::lcd_pixel_4_5);
		path_p.addPath(PATH::lcd_pixel_5_1);
		path_p.addPath(PATH::lcd_pixel_5_2);
		path_p.addPath(PATH::lcd_pixel_5_3);
		path_p.addPath(PATH::lcd_pixel_5_4);
		path_p.addPath(PATH::lcd_pixel_6_1);
		path_p.addPath(PATH::lcd_pixel_7_1);
		return path_p;
	}
	case (uint8)113: {
		Path path_q;
		path_q.addPath(PATH::lcd_pixel_3_2);
		path_q.addPath(PATH::lcd_pixel_3_3);
		path_q.addPath(PATH::lcd_pixel_3_5);
		path_q.addPath(PATH::lcd_pixel_4_1);
		path_q.addPath(PATH::lcd_pixel_4_4);
		path_q.addPath(PATH::lcd_pixel_4_5);
		path_q.addPath(PATH::lcd_pixel_5_2);
		path_q.addPath(PATH::lcd_pixel_5_3);
		path_q.addPath(PATH::lcd_pixel_5_4);
		path_q.addPath(PATH::lcd_pixel_5_5);
		path_q.addPath(PATH::lcd_pixel_6_5);
		path_q.addPath(PATH::lcd_pixel_7_5);
		return path_q;
	}
	case (uint8)114: {
		Path path_r;
		path_r.addPath(PATH::lcd_pixel_3_1);
		path_r.addPath(PATH::lcd_pixel_3_3);
		path_r.addPath(PATH::lcd_pixel_3_4);
		path_r.addPath(PATH::lcd_pixel_4_1);
		path_r.addPath(PATH::lcd_pixel_4_2);
		path_r.addPath(PATH::lcd_pixel_4_5);
		path_r.addPath(PATH::lcd_pixel_5_1);
		path_r.addPath(PATH::lcd_pixel_6_1);
		path_r.addPath(PATH::lcd_pixel_7_1);
		return path_r;
	}
	case (uint8)115: {
		Path path_s;
		path_s.addPath(PATH::lcd_pixel_3_2);
		path_s.addPath(PATH::lcd_pixel_3_3);
		path_s.addPath(PATH::lcd_pixel_3_4);
		path_s.addPath(PATH::lcd_pixel_4_1);
		path_s.addPath(PATH::lcd_pixel_5_2);
		path_s.addPath(PATH::lcd_pixel_5_3);
		path_s.addPath(PATH::lcd_pixel_5_4);
		path_s.addPath(PATH::lcd_pixel_6_5);
		path_s.addPath(PATH::lcd_pixel_7_1);
		path_s.addPath(PATH::lcd_pixel_7_2);
		path_s.addPath(PATH::lcd_pixel_7_3);
		path_s.addPath(PATH::lcd_pixel_7_4);
		return path_s;
	}
	case (uint8)116: {
		Path path_t;
		path_t.addPath(PATH::lcd_pixel_1_2);
		path_t.addPath(PATH::lcd_pixel_2_2);
		path_t.addPath(PATH::lcd_pixel_3_1);
		path_t.addPath(PATH::lcd_pixel_3_2);
		path_t.addPath(PATH::lcd_pixel_3_3);
		path_t.addPath(PATH::lcd_pixel_4_2);
		path_t.addPath(PATH::lcd_pixel_5_2);
		path_t.addPath(PATH::lcd_pixel_6_2);
		path_t.addPath(PATH::lcd_pixel_6_5);
		path_t.addPath(PATH::lcd_pixel_7_3);
		path_t.addPath(PATH::lcd_pixel_7_4);
		return path_t;
	}
	case (uint8)117: {
		Path path_u;
		path_u.addPath(PATH::lcd_pixel_3_1);
		path_u.addPath(PATH::lcd_pixel_3_5);
		path_u.addPath(PATH::lcd_pixel_4_1);
		path_u.addPath(PATH::lcd_pixel_4_5);
		path_u.addPath(PATH::lcd_pixel_5_1);
		path_u.addPath(PATH::lcd_pixel_5_5);
		path_u.addPath(PATH::lcd_pixel_6_1);
		path_u.addPath(PATH::lcd_pixel_6_4);
		path_u.addPath(PATH::lcd_pixel_6_5);
		path_u.addPath(PATH::lcd_pixel_7_2);
		path_u.addPath(PATH::lcd_pixel_7_3);
		path_u.addPath(PATH::lcd_pixel_7_5);
		return path_u;
	}
	case (uint8)118: {
		Path path_v;
		path_v.addPath(PATH::lcd_pixel_3_1);
		path_v.addPath(PATH::lcd_pixel_3_5);
		path_v.addPath(PATH::lcd_pixel_4_1);
		path_v.addPath(PATH::lcd_pixel_4_5);
		path_v.addPath(PATH::lcd_pixel_5_1);
		path_v.addPath(PATH::lcd_pixel_5_5);
		path_v.addPath(PATH::lcd_pixel_6_2);
		path_v.addPath(PATH::lcd_pixel_6_4);
		path_v.addPath(PATH::lcd_pixel_7_3);
		return path_v;
	}
	case (uint8)119: {
		Path path_w;
		path_w.addPath(PATH::lcd_pixel_3_1);
		path_w.addPath(PATH::lcd_pixel_3_5);
		path_w.addPath(PATH::lcd_pixel_4_1);
		path_w.addPath(PATH::lcd_pixel_4_5);
		path_w.addPath(PATH::lcd_pixel_5_1);
		path_w.addPath(PATH::lcd_pixel_5_3);
		path_w.addPath(PATH::lcd_pixel_5_5);
		path_w.addPath(PATH::lcd_pixel_6_1);
		path_w.addPath(PATH::lcd_pixel_6_3);
		path_w.addPath(PATH::lcd_pixel_6_5);
		path_w.addPath(PATH::lcd_pixel_7_2);
		path_w.addPath(PATH::lcd_pixel_7_4);
		return path_w;
	}
	case (uint8)120: {
		Path path_x;
		path_x.addPath(PATH::lcd_pixel_3_1);
		path_x.addPath(PATH::lcd_pixel_3_5);
		path_x.addPath(PATH::lcd_pixel_4_2);
		path_x.addPath(PATH::lcd_pixel_4_4);
		path_x.addPath(PATH::lcd_pixel_5_3);
		path_x.addPath(PATH::lcd_pixel_6_2);
		path_x.addPath(PATH::lcd_pixel_6_4);
		path_x.addPath(PATH::lcd_pixel_7_1);
		path_x.addPath(PATH::lcd_pixel_7_5);
		return path_x;
	}
	case (uint8)121: {
		Path path_y;
		path_y.addPath(PATH::lcd_pixel_3_1);
		path_y.addPath(PATH::lcd_pixel_3_5);
		path_y.addPath(PATH::lcd_pixel_4_1);
		path_y.addPath(PATH::lcd_pixel_4_5);
		path_y.addPath(PATH::lcd_pixel_5_2);
		path_y.addPath(PATH::lcd_pixel_5_3);
		path_y.addPath(PATH::lcd_pixel_5_4);
		path_y.addPath(PATH::lcd_pixel_5_5);
		path_y.addPath(PATH::lcd_pixel_6_5);
		path_y.addPath(PATH::lcd_pixel_7_2);
		path_y.addPath(PATH::lcd_pixel_7_3);
		path_y.addPath(PATH::lcd_pixel_7_4);
		return path_y;
	}
	case (uint8)122: {
		Path path_z;
		path_z.addPath(PATH::lcd_pixel_3_1);
		path_z.addPath(PATH::lcd_pixel_3_2);
		path_z.addPath(PATH::lcd_pixel_3_3);
		path_z.addPath(PATH::lcd_pixel_3_4);
		path_z.addPath(PATH::lcd_pixel_3_5);
		path_z.addPath(PATH::lcd_pixel_4_4);
		path_z.addPath(PATH::lcd_pixel_5_3);
		path_z.addPath(PATH::lcd_pixel_6_2);
		path_z.addPath(PATH::lcd_pixel_7_1);
		path_z.addPath(PATH::lcd_pixel_7_2);
		path_z.addPath(PATH::lcd_pixel_7_3);
		path_z.addPath(PATH::lcd_pixel_7_4);
		path_z.addPath(PATH::lcd_pixel_7_5);
		return path_z;
	}
	case (uint8)123: {
		Path path_open_brace;
		path_open_brace.addPath(PATH::lcd_pixel_1_4);
		path_open_brace.addPath(PATH::lcd_pixel_2_3);
		path_open_brace.addPath(PATH::lcd_pixel_3_3);
		path_open_brace.addPath(PATH::lcd_pixel_4_2);
		path_open_brace.addPath(PATH::lcd_pixel_5_3);
		path_open_brace.addPath(PATH::lcd_pixel_6_3);
		path_open_brace.addPath(PATH::lcd_pixel_7_4);
		return path_open_brace;
	}
	case (uint8)124: {
		Path path_bar;
		path_bar.addPath(PATH::lcd_pixel_1_3);
		path_bar.addPath(PATH::lcd_pixel_2_3);
		path_bar.addPath(PATH::lcd_pixel_3_3);
		path_bar.addPath(PATH::lcd_pixel_4_3);
		path_bar.addPath(PATH::lcd_pixel_5_3);
		path_bar.addPath(PATH::lcd_pixel_6_3);
		path_bar.addPath(PATH::lcd_pixel_7_3);
		return path_bar;
	}
	case (uint8)125: {
		Path path_close_brace;
		path_close_brace.addPath(PATH::lcd_pixel_1_2);
		path_close_brace.addPath(PATH::lcd_pixel_2_3);
		path_close_brace.addPath(PATH::lcd_pixel_3_3);
		path_close_brace.addPath(PATH::lcd_pixel_4_4);
		path_close_brace.addPath(PATH::lcd_pixel_5_3);
		path_close_brace.addPath(PATH::lcd_pixel_6_3);
		path_close_brace.addPath(PATH::lcd_pixel_7_2);
		return path_close_brace;
	}
	case (uint8)126: {
		Path path_right_arrow;
		path_right_arrow.addPath(PATH::lcd_pixel_2_3);
		path_right_arrow.addPath(PATH::lcd_pixel_3_4);
		path_right_arrow.addPath(PATH::lcd_pixel_4_1);
		path_right_arrow.addPath(PATH::lcd_pixel_4_2);
		path_right_arrow.addPath(PATH::lcd_pixel_4_3);
		path_right_arrow.addPath(PATH::lcd_pixel_4_4);
		path_right_arrow.addPath(PATH::lcd_pixel_4_5);
		path_right_arrow.addPath(PATH::lcd_pixel_5_4);
		path_right_arrow.addPath(PATH::lcd_pixel_6_3);
		return path_right_arrow;
	}
	case (uint8)127: {
		Path path_left_arrow;
		path_left_arrow.addPath(PATH::lcd_pixel_2_3);
		path_left_arrow.addPath(PATH::lcd_pixel_3_2);
		path_left_arrow.addPath(PATH::lcd_pixel_4_1);
		path_left_arrow.addPath(PATH::lcd_pixel_4_2);
		path_left_arrow.addPath(PATH::lcd_pixel_4_3);
		path_left_arrow.addPath(PATH::lcd_pixel_4_4);
		path_left_arrow.addPath(PATH::lcd_pixel_4_5);
		path_left_arrow.addPath(PATH::lcd_pixel_5_2);
		path_left_arrow.addPath(PATH::lcd_pixel_6_3);
		return path_left_arrow;
	}
	default:
		return Path{};
	}
}

void Paths_Widgets::knob(Graphics& g, float& rotation, float& scale) {
	auto knob = load_path(PATH::knob, sizeof(PATH::knob));
	knob.applyTransform(AffineTransform::rotation(rotation, 19, 19));
	g.setColour(COLOR::black);
	g.fillPath(knob, AffineTransform::scale(scale));
}

void Paths_Widgets::lcd_char(Graphics& g, uint8 char_num, float& scale) {
	auto p = build_char_path(char_num);
	g.setColour(COLOR::white);
	g.fillPath(p, AffineTransform::scale(scale));
}

void Paths_Widgets::wave_pulse(Graphics& g, const int w, float& scale_factor) {
	Path p;
	auto crossover_x{ wave_x() + 1.0f + (18.0f * (w * .01f)) };
	p.addLineSegment({ wave_x() + 1.0f, wave_y() + 9.0f, wave_x() + 1.0f, wave_y() }, 0.5f);
	p.addLineSegment({ wave_x() + 1.0f, wave_y(), crossover_x, wave_y() }, 0.5f);
	p.addLineSegment({ crossover_x, wave_y(), crossover_x, wave_y() + 9.0f }, 0.5f);
	p.addLineSegment({ crossover_x, wave_y() + 9.0f, wave_x() + 19.0f, wave_y() + 9.0f }, 0.5f);
	p.applyTransform(AffineTransform::scale(scale_factor));
	g.strokePath(p, wave_stroke());
}

void Paths_Widgets::wave_saw(Graphics& g, float& scale_factor) {
	Path p;
	p.addLineSegment({ wave_x() + 1.0f, wave_y() + 12.0f, wave_x() + 16.0f, wave_y() }, 0.5f);
	p.addLineSegment({ wave_x() + 16.0f, wave_y(), wave_x() + 16.0f, wave_y() + 12.0f }, 0.5f);
	p.applyTransform(AffineTransform::scale(scale_factor));
	g.strokePath(p, wave_stroke());
}

void Paths_Widgets::wave_saw_tri(Graphics& g, float& scale_factor) {
	Path p;
	p.addLineSegment({ wave_x(), wave_y() + 7.0f, wave_x() + 5.0f, wave_y() }, 0.5f);
	p.addLineSegment({ wave_x() + 5.0f, wave_y(), wave_x() + 10.0f, wave_y() + 7.0f }, 0.5f);
	p.addLineSegment({ wave_x() + 10.0f, wave_y() + 7.0f, wave_x() + 10.0f, wave_y() + 15.0f }, 0.5f);
	p.addLineSegment({ wave_x() + 10.0f, wave_y() + 15.0f, wave_x() + 20.0f, wave_y() + 7.0f }, 0.5f);
	p.applyTransform(AffineTransform::scale(scale_factor));
	g.strokePath(p, wave_stroke());
}

PathStrokeType Paths_Widgets::wave_stroke() {
	return { 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
}

void Paths_Widgets::wave_tri(Graphics& g, float& scale_factor) {
	Path p;
	p.addLineSegment({ wave_x() + 2.0f, wave_y() + 12.0f, wave_x() + 10.0f, wave_y() + 1.0f }, 0.5f);
	p.addLineSegment({ wave_x() + 10.0f, wave_y() + 1.0f, wave_x() + 18.0f, wave_y() + 12.0f }, 0.5f);
	p.applyTransform(AffineTransform::scale(scale_factor));
	g.strokePath(p, wave_stroke());
}
