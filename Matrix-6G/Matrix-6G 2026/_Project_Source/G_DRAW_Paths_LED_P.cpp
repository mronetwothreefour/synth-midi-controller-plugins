#include "G_DRAW_Paths_LED_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_LED_P.h"
#include "C_XYWH_P.h"

using namespace DRAW;
using namespace PATH;
using namespace XYWH;

Path Paths_LED::build_char_path(const uint8 char_num) {
	auto char_num_space{ (uint8)32 };
	if (char_num <= char_num_space)
		return {};
	if (char_num > 95) {
		Path path_bar;
		path_bar.addPath(load_path(led_segment_b, sizeof(led_segment_b)));
		path_bar.addPath(load_path(led_segment_c, sizeof(led_segment_c)));
		return path_bar;
	}
	switch (char_num)
	{
	case 33: {
		Path path_exclamation;
		path_exclamation.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_exclamation.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_exclamation.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_exclamation.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		return path_exclamation;
	}
	case 34: {
		Path path_double_quote;
		path_double_quote.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_double_quote.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		return path_double_quote;
	}
	case 35: {
		Path path_hash;
		path_hash.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_hash.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_hash.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_hash.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_hash.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_hash.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		path_hash.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_hash;
	}
	case 36: {
		Path path_$;
		path_$.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_$.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_$.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_$.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_$.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_$.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_$.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		path_$.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_$;
	}
	case 37: {
		Path path_percent;
		path_percent.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_percent.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_percent.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_percent.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_percent.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_percent.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_percent.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		path_percent.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		path_percent.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_percent;
	}
	case 38: {
		Path path_ampersand;
		path_ampersand.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_ampersand.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_ampersand.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_ampersand.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_ampersand.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_ampersand.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_ampersand.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		path_ampersand.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_ampersand;
	}
	case 39: {
		Path path_single_quote;
		path_single_quote.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		return path_single_quote;
	}
	case 40: {
		Path path_open_parenthesis;
		path_open_parenthesis.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_open_parenthesis.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		return path_open_parenthesis;
	}
	case 41: {
		Path path_close_parenthesis;
		path_close_parenthesis.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_close_parenthesis.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_close_parenthesis;
	}
	case 42: {
		Path path_asterisk;
		path_asterisk.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_asterisk.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_asterisk.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_asterisk.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_asterisk.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		path_asterisk.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		path_asterisk.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		path_asterisk.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_asterisk;
	}
	case 43: {
		Path path_plus;
		path_plus.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_plus.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_plus.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		path_plus.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_plus;
	}
	case 44: {
		Path path_comma;
		path_comma.addPath(load_path(PATH::led_segment_o, sizeof(PATH::led_segment_o)));
		path_comma.addPath(load_path(PATH::led_segment_p, sizeof(PATH::led_segment_p)));
		return path_comma;
	}
	case 45: {
		Path path_hyphen;
		path_hyphen.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_hyphen.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_hyphen;
	}
	case 46: {
		Path path_period;
		path_period.addPath(load_path(PATH::led_segment_o, sizeof(PATH::led_segment_o)));
		return path_period;
	}
	case 47: {
		Path path_slash;
		path_slash.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_slash.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_slash;
	}
	case 48: {
		Path path_0;
		path_0.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_0.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_0.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_0.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_0.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_0.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_0.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_0.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_0;
	}
	case 49: {
		Path path_1;
		path_1.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_1.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		return path_1;
	}
	case 50: {
		Path path_2;
		path_2.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_2.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_2.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_2.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_2.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_2.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_2;
	}
	case 51: {
		Path path_3;
		path_3.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_3.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_3.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_3.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_3.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_3.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_3;
	}
	case 52: {
		Path path_4;
		path_4.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_4.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_4.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_4.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_4.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_4;
	}
	case 53: {
		Path path_5;
		path_5.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_5.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_5.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_5.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_5.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_5.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_5;
	}
	case 54: {
		Path path_6;
		path_6.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_6.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_6.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_6.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_6.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_6.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_6.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_6;
	}
	case 55: {
		Path path_7;
		path_7.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_7.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_7.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		return path_7;
	}
	case 56: {
		Path path_8;
		path_8.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_8.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_8.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_8.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_8.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_8.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_8.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_8.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_8;
	}
	case 57: {
		Path path_9;
		path_9.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_9.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_9.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_9.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_9.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_9.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_9.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_9;
	}
	case 58: {
		Path path_colon;
		path_colon.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_colon.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		return path_colon;
	}
	case 59: {
		Path path_semicolon;
		path_semicolon.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_semicolon.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_semicolon;
	}
	case 60: {
		Path path_open_angle_bracket;
		path_open_angle_bracket.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_open_angle_bracket.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_open_angle_bracket.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_open_angle_bracket;
	}
	case 61: {
		Path path_equal;
		path_equal.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_equal.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_equal.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_equal;
	}
	case 62: {
		Path path_close_angle_bracket;
		path_close_angle_bracket.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_close_angle_bracket.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_close_angle_bracket.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		return path_close_angle_bracket;
	}
	case 63: {
		Path path_question;
		path_question.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_question.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_question.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_question.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		return path_question;
	}
	case 65: {
		Path path_A;
		path_A.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_A.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_A.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_A.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_A.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_A.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_A.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_A;
	}
	case 66: {
		Path path_B;
		path_B.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_B.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_B.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_B.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_B.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_B.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_B.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		return path_B;
	}
	case 67: {
		Path path_C;
		path_C.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_C.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_C.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_C.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		return path_C;
	}
	case 68: {
		Path path_D;
		path_D.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_D.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_D.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_D.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_D.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_D.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		return path_D;
	}
	case 69: {
		Path path_E;
		path_E.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_E.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_E.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_E.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_E.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_E;
	}
	case 70: {
		Path path_F;
		path_F.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_F.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_F.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_F.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_F;
	}
	case 71: {
		Path path_G;
		path_G.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_G.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_G.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_G.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_G.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_G.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		return path_G;
	}
	case 72: {
		Path path_H;
		path_H.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_H.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_H.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_H.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_H.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_H.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_H;
	}
	case 73: {
		Path path_I;
		path_I.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_I.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_I.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_I.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		return path_I;
	}
	case 74: {
		Path path_J;
		path_J.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_J.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_J.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_J.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		return path_J;
	}
	case 75: {
		Path path_K;
		path_K.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_K.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_K.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_K.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		path_K.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_K;
	}
	case 76: {
		Path path_L;
		path_L.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_L.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_L.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		return path_L;
	}
	case 77: {
		Path path_M;
		path_M.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_M.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_M.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_M.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_M.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_M.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		return path_M;
	}
	case 78: {
		Path path_N;
		path_N.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_N.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_N.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_N.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_N.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_N.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		return path_N;
	}
	case 79: {
		Path path_O;
		path_O.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_O.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_O.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_O.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_O.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_O.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		return path_O;
	}
	case 80: {
		Path path_P;
		path_P.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_P.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_P.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_P.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_P.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_P.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_P;
	}
	case 81: {
		Path path_Q;
		path_Q.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_Q.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_Q.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_Q.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_Q.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_Q.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_Q.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		return path_Q;
	}
	case 82: {
		Path path_R;
		path_R.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_R.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_R.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_R.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_R.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_R.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		path_R.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_R;
	}
	case 83: {
		Path path_S;
		path_S.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_S.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_S.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_S.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_S.addPath(load_path(PATH::led_segment_j, sizeof(PATH::led_segment_j)));
		path_S.addPath(load_path(PATH::led_segment_n, sizeof(PATH::led_segment_n)));
		return path_S;
	}
	case 84: {
		Path path_T;
		path_T.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_T.addPath(load_path(PATH::led_segment_h, sizeof(PATH::led_segment_h)));
		path_T.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		return path_T;
	}
	case 85: {
		Path path_U;
		path_U.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_U.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_U.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_U.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_U.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		return path_U;
	}
	case 86: {
		Path path_V;
		path_V.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_V.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_V.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_V.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_V;
	}
	case 87: {
		Path path_W;
		path_W.addPath(load_path(PATH::led_segment_b, sizeof(PATH::led_segment_b)));
		path_W.addPath(load_path(PATH::led_segment_c, sizeof(PATH::led_segment_c)));
		path_W.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_W.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		path_W.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		path_W.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_W;
	}
	case 88: {
		Path path_X;
		path_X.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_X.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_X.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		path_X.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_X;
	}
	case 89: {
		Path path_Y;
		path_Y.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_Y.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_Y.addPath(load_path(PATH::led_segment_l, sizeof(PATH::led_segment_l)));
		return path_Y;
	}
	case 90: {
		Path path_Z;
		path_Z.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_Z.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_Z.addPath(load_path(PATH::led_segment_i, sizeof(PATH::led_segment_i)));
		path_Z.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_Z;
	}
	case 91: {
		Path path_open_bracket;
		path_open_bracket.addPath(load_path(PATH::led_segment_a, sizeof(PATH::led_segment_a)));
		path_open_bracket.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		path_open_bracket.addPath(load_path(PATH::led_segment_e, sizeof(PATH::led_segment_e)));
		path_open_bracket.addPath(load_path(PATH::led_segment_f, sizeof(PATH::led_segment_f)));
		return path_open_bracket;
	}
	case 92: {
		Path path_backslash;
		path_backslash.addPath(load_path(PATH::led_segment_g, sizeof(PATH::led_segment_g)));
		path_backslash.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		return path_backslash;
	}
	case 94: {
		Path path_caret;
		path_caret.addPath(load_path(PATH::led_segment_k, sizeof(PATH::led_segment_k)));
		path_caret.addPath(load_path(PATH::led_segment_m, sizeof(PATH::led_segment_m)));
		return path_caret;
	}
	case 95: {
		Path path_underscore;
		path_underscore.addPath(load_path(PATH::led_segment_d, sizeof(PATH::led_segment_d)));
		return path_underscore;
	}
	default:
		return {};
	}
}

Path Paths_LED::build_vert_bar(float& scale_factor) {
	auto p = load_path(led_vert_bar, sizeof(led_vert_bar));
	p.applyTransform(AffineTransform::scale(scale_factor));
	return p;
}

void Paths_LED::display_text(Graphics& g, const String txt, const int display_w, 
									float& scale_factor, Justification j, float alpha)
{
	auto char_w = led_display_char_w * scale_factor;
	auto display_y = led_display_y * scale_factor;
	Path path;
	auto char_count{ txt.length() };
	if (j == Justification::right) {
		auto inset = led_display_right_inset * scale_factor;
		auto last_char_x = (float)display_w - char_w - inset;
		auto last_char_index = char_count - 1;
		for (int i = last_char_index; i > -1; --i) {
			auto char_num{ (uint8)txt[i] };
			auto char_x{ last_char_x - (char_w * (last_char_index - i)) };
			auto char_path{ build_char_path(char_num) };
			auto char_transform{ AffineTransform::scale(scale_factor) };
			char_transform = char_transform.translated(char_x, display_y);
			path.addPath(char_path, char_transform);
		}
	}
	else {
		for (int i = 0; i < char_count; ++i) {
			auto inset = led_display_left_inset * scale_factor;
			auto char_num{ (uint8)txt[i] };
			auto char_x{ inset + (char_w * i) };
			auto char_path{ build_char_path(char_num) };
			auto char_transform{ AffineTransform::scale(scale_factor) };
			char_transform = char_transform.translated(char_x, display_y);
			path.addPath(char_path, char_transform);
		}
	}
	g.setColour(COLOR::blue_led.withAlpha(alpha));
	g.fillPath(path);
}

void Paths_LED::slider_tab(Graphics& g, float pos, float& scale) {
	Path path_tab;
	for (int i = 0; i < 6; ++i)
		path_tab.addPath(build_vert_bar(scale), AffineTransform::translation(i * 3.0f * scale, 0.0f));
	g.setColour(COLOR::blue_led);
	g.fillPath(path_tab, AffineTransform::translation(pos - 8.0f * scale, 0.0f));
}
