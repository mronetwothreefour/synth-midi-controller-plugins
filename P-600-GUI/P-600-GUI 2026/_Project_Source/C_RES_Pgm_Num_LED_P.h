#pragma once

#include "G_DRAW_Paths_A.h"

using namespace DRAW;

namespace RES
{

	constexpr unsigned char led_segment_1_a_data[]{ 110,109,180,161,87,64,107,119,7,64,108,96,233,213,64,107,119,7,64,108,18,103,205,64,32,222,67,64,108,226,77,93,64,32,222,67,64,99,101,0,0 };
	constexpr unsigned char led_segment_1_b_data[]{ 
		110,109,197,170,221,64,14,58,8,64,108,92,82,210,64,217,158,76,64,108,106,152,198,64,68,88,192,64,108,74,143,209,64,241,77,208,64,108,29,142,223,64,241,77,208,64,98,29,142,223,64,241,77,208,64,70,66,232,64,42,216,201,64,207,163,232,64,249,10,198,64,108,
		6,126,245,64,123,232,40,64,98,24,65,246,64,192,171,22,64,61,198,233,64,14,58,8,64,197,170,221,64,14,58,8,64,101,0,0 
	};
	constexpr unsigned char led_segment_1_c_data[]{ 
		110,109,71,72,186,64,202,204,49,65,108,244,224,182,64,95,34,32,65,108,3,237,195,64,243,202,230,64,108,58,22,214,64,158,33,213,64,108,76,34,227,64,158,33,213,64,98,76,34,227,64,158,33,213,64,103,248,229,64,38,138,220,64,245,213,228,64,76,95,227,64,98,
		130,179,227,64,156,54,234,64,58,22,214,64,9,247,40,65,58,22,214,64,9,247,40,65,98,204,243,212,64,147,95,48,65,172,160,197,64,202,204,49,65,71,72,186,64,202,204,49,65,101,0,0
	};
	constexpr unsigned char led_segment_1_d_data[]{ 110,109,163,10,180,64,202,204,49,65,108,57,228,19,64,202,204,49,65,108,212,232,36,64,28,179,34,65,108,136,52,177,64,28,179,34,65,99,101,0,0 };
	constexpr unsigned char led_segment_1_e_data[]{ 
		110,109,112,97,4,64,33,156,49,65,108,58,18,27,64,238,130,32,65,108,30,134,50,64,3,253,230,64,108,95,152,28,64,87,7,215,64,108,185,154,0,64,87,7,215,64,98,185,154,0,64,87,7,215,64,222,100,222,63,30,125,221,64,185,222,220,63,79,74,225,64,108,222,117,169,
		63,133,112,41,65,98,144,105,166,63,180,255,45,65,241,84,216,63,32,156,49,65,112,97,4,64,32,156,49,65,101,0,0
	};
	constexpr unsigned char led_segment_1_f_data[]{ 
		110,109,108,38,75,64,107,119,7,64,108,17,245,81,64,24,33,78,64,108,236,220,55,64,86,138,192,64,108,126,138,19,64,171,51,210,64,108,178,228,242,63,171,51,210,64,98,178,228,242,63,171,51,210,64,86,140,231,63,35,203,202,64,15,22,236,63,254,245,195,64,98,
		214,159,240,63,174,30,189,64,126,138,19,64,109,206,42,64,126,138,19,64,109,206,42,64,98,98,207,21,64,74,44,13,64,154,117,52,64,107,119,7,64,108,38,75,64,107,119,7,64,101,0,0
	};
	constexpr unsigned char led_segment_1_g_data[]{ 110,109,122,249,39,64,82,52,210,64,108,237,126,62,64,30,111,227,64,108,159,149,188,64,30,111,227,64,108,54,102,205,64,38,234,211,64,108,60,94,193,64,46,88,196,64,108,134,104,65,64,46,88,196,64,99,101,0,0 };
	constexpr unsigned char led_segment_2_a_data[]{ 110,109,127,249,35,65,107,119,7,64,108,194,5,89,65,107,119,7,64,108,154,196,84,65,32,222,67,64,108,138,100,37,65,32,222,67,64,99,101,0,0 };
	constexpr unsigned char led_segment_2_b_data[]{ 
		110,109,116,230,92,65,14,58,8,64,108,64,58,87,65,218,158,76,64,108,70,93,81,65,68,88,192,64,108,182,216,86,65,241,77,208,64,108,32,216,93,65,241,77,208,64,98,32,216,93,65,241,77,208,64,52,50,98,65,42,216,201,64,249,98,98,65,249,10,198,64,108,21,208,104,
		65,123,232,40,64,98,157,49,105,65,192,171,22,64,48,244,98,65,14,58,8,64,116,230,92,65,14,58,8,64,101,0,0
	};
	constexpr unsigned char led_segment_2_c_data[]{ 
		110,109,53,53,75,65,202,204,49,65,108,140,129,73,65,95,34,32,65,108,147,7,80,65,243,202,230,64,108,46,28,89,65,158,33,213,64,108,56,162,95,65,158,33,213,64,98,56,162,95,65,158,33,213,64,74,13,97,65,38,138,220,64,11,124,96,65,76,95,227,64,98,215,234,95,
		65,156,54,234,64,45,28,89,65,9,247,40,65,45,28,89,65,9,247,40,65,98,249,138,88,65,147,95,48,65,102,225,80,65,202,204,49,65,52,53,75,65,202,204,49,65,101,0,0
	};
	constexpr unsigned char led_segment_2_d_data[]{ 110,109,100,22,72,65,202,204,49,65,108,32,10,19,65,202,204,49,65,108,71,75,23,65,28,179,34,65,108,86,171,70,65,28,179,34,65,99,101,0,0 };
	constexpr unsigned char led_segment_2_e_data[]{ 
		110,109,110,41,15,65,33,156,49,65,108,160,213,20,65,238,130,32,65,108,153,178,26,65,3,253,230,64,108,41,55,21,65,87,7,215,64,108,192,55,14,65,87,7,215,64,98,192,55,14,65,87,7,215,64,174,221,9,65,30,125,221,64,233,172,9,65,79,74,225,64,108,205,63,3,65,
		133,112,41,65,98,67,222,2,65,180,255,45,65,175,27,9,65,32,156,49,65,109,41,15,65,32,156,49,65,101,0,0
	};
	constexpr unsigned char led_segment_2_f_data[]{ 
		110,109,172,218,32,65,107,119,7,64,108,86,142,34,65,24,33,78,64,108,77,8,28,65,86,138,192,64,108,177,243,18,65,171,51,210,64,108,168,109,12,65,171,51,210,64,98,168,109,12,65,171,51,210,64,157,2,11,65,35,203,202,64,212,147,11,65,254,245,195,64,98,12,37,
		12,65,174,30,189,64,177,243,18,65,109,206,42,64,177,243,18,65,109,206,42,64,98,234,132,19,65,74,44,13,64,120,46,27,65,107,119,7,64,172,218,32,65,107,119,7,64,101,0,0
	};
	constexpr unsigned char led_segment_2_g_data[]{ 110,109,110,15,24,65,82,52,210,64,108,203,176,29,65,29,111,227,64,108,224,91,76,65,29,111,227,64,108,42,196,84,65,38,234,211,64,108,46,192,78,65,46,88,196,64,108,49,107,30,65,46,88,196,64,99,101,0,0 };

	constexpr auto led_segment_1_a_size = sizeof(led_segment_1_a_data);
	constexpr auto led_segment_1_b_size = sizeof(led_segment_1_b_data);
	constexpr auto led_segment_1_c_size = sizeof(led_segment_1_c_data);
	constexpr auto led_segment_1_d_size = sizeof(led_segment_1_d_data);
	constexpr auto led_segment_1_e_size = sizeof(led_segment_1_e_data);
	constexpr auto led_segment_1_f_size = sizeof(led_segment_1_f_data);
	constexpr auto led_segment_1_g_size = sizeof(led_segment_1_g_data);
	constexpr auto led_segment_2_a_size = sizeof(led_segment_2_a_data);
	constexpr auto led_segment_2_b_size = sizeof(led_segment_2_b_data);
	constexpr auto led_segment_2_c_size = sizeof(led_segment_2_c_data);
	constexpr auto led_segment_2_d_size = sizeof(led_segment_2_d_data);
	constexpr auto led_segment_2_e_size = sizeof(led_segment_2_e_data);
	constexpr auto led_segment_2_f_size = sizeof(led_segment_2_f_data);
	constexpr auto led_segment_2_g_size = sizeof(led_segment_2_g_data);

	static const Path led_segment_1_a{ Paths_A::load_path(led_segment_1_a_data, led_segment_1_a_size) };
	static const Path led_segment_1_b{ Paths_A::load_path(led_segment_1_b_data, led_segment_1_b_size) };
	static const Path led_segment_1_c{ Paths_A::load_path(led_segment_1_c_data, led_segment_1_c_size) };
	static const Path led_segment_1_d{ Paths_A::load_path(led_segment_1_d_data, led_segment_1_d_size) };
	static const Path led_segment_1_e{ Paths_A::load_path(led_segment_1_e_data, led_segment_1_e_size) };
	static const Path led_segment_1_f{ Paths_A::load_path(led_segment_1_f_data, led_segment_1_f_size) };
	static const Path led_segment_1_g{ Paths_A::load_path(led_segment_1_g_data, led_segment_1_g_size) };
	static const Path led_segment_2_a{ Paths_A::load_path(led_segment_2_a_data, led_segment_2_a_size) };
	static const Path led_segment_2_b{ Paths_A::load_path(led_segment_2_b_data, led_segment_2_b_size) };
	static const Path led_segment_2_c{ Paths_A::load_path(led_segment_2_c_data, led_segment_2_c_size) };
	static const Path led_segment_2_d{ Paths_A::load_path(led_segment_2_d_data, led_segment_2_d_size) };
	static const Path led_segment_2_e{ Paths_A::load_path(led_segment_2_e_data, led_segment_2_e_size) };
	static const Path led_segment_2_f{ Paths_A::load_path(led_segment_2_f_data, led_segment_2_f_size) };
	static const Path led_segment_2_g{ Paths_A::load_path(led_segment_2_g_data, led_segment_2_g_size) };

}
