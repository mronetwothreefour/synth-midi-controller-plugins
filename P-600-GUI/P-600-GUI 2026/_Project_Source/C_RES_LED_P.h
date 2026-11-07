#pragma once

#include "G_DRAW_Paths_A.h"

using namespace DRAW;

namespace RES
{

	constexpr unsigned char led_segment_a_data[]{ 110,109,199,247,2,64,0,0,0,0,108,106,148,171,64,0,0,0,0,108,28,18,163,64,213,154,113,63,108,245,163,8,64,213,154,113,63,99,101,0,0 };
	constexpr unsigned char led_segment_b_data[]{ 
		110,109,207,85,179,64,19,163,66,60,108,102,253,167,64,221,78,138,63,108,115,67,156,64,29,57,121,64,108,83,58,167,64,59,146,140,64,108,38,57,181,64,59,146,140,64,98,38,57,181,64,59,146,140,64,79,237,189,64,116,28,134,64,216,78,190,64,67,79,130,64,108,
		15,41,203,64,59,196,5,63,98,33,236,203,64,87,69,115,62,70,113,191,64,19,163,66,60,207,85,179,64,19,163,66,60,101,0,0
	};
	constexpr unsigned char led_segment_c_data[]{ 
		110,109,80,243,143,64,239,238,15,65,108,254,139,140,64,8,137,252,64,108,12,152,153,64,62,15,163,64,108,68,193,171,64,232,101,145,64,108,86,205,184,64,232,101,145,64,98,86,205,184,64,232,101,145,64,113,163,187,64,112,206,152,64,255,128,186,64,150,163,
		159,64,98,140,94,185,64,230,122,166,64,68,193,171,64,46,25,7,65,68,193,171,64,46,25,7,65,98,214,158,170,64,184,129,14,65,182,75,155,64,239,238,15,65,81,243,143,64,239,238,15,65,101,0,0
	};
	constexpr unsigned char led_segment_d_data[]{ 110,109,173,181,137,64,239,238,15,65,108,50,233,124,63,239,238,15,65,108,208,125,160,63,65,213,0,65,108,145,223,134,64,65,213,0,65,99,101,0,0 };
	constexpr unsigned char led_segment_e_data[]{ 
		110,109,11,222,62,63,70,190,15,65,108,154,208,140,63,38,74,253,64,108,99,184,187,63,78,65,163,64,108,228,220,143,63,161,75,147,64,108,49,195,47,63,161,75,147,64,98,49,195,47,63,161,75,147,64,18,68,212,62,104,193,153,64,125,43,206,62,153,142,157,64,108,
		0,15,136,58,170,146,7,65,98,139,146,186,188,217,33,12,65,92,4,188,62,69,190,15,65,10,222,62,63,69,190,15,65,101,0,0
	};
	constexpr unsigned char led_segment_f_data[]{ 
		110,109,254,248,236,63,0,0,0,0,108,72,150,250,63,91,83,141,63,108,255,101,198,63,64,157,121,64,108,67,130,123,63,246,119,142,64,108,176,33,19,63,246,119,142,64,98,176,33,19,63,246,119,142,64,240,225,248,62,110,15,135,64,107,132,5,63,73,58,128,64,98,249,
		151,14,63,241,197,114,64,67,130,123,63,7,92,13,63,67,130,123,63,7,92,13,63,98,234,74,130,63,238,155,182,61,90,151,191,63,0,0,0,0,254,248,236,63,0,0,0,0,101,0,0
	};
	constexpr unsigned char led_segment_g_data[]{ 110,109,26,159,166,63,157,120,142,64,108,1,170,211,63,104,179,159,64,108,169,64,146,64,104,179,159,64,108,63,17,163,64,112,46,144,64,108,70,9,151,64,120,156,128,64,108,51,125,217,63,120,156,128,64,99,101,0,0 };

	constexpr auto led_segment_a_size = sizeof(led_segment_a_data);
	constexpr auto led_segment_b_size = sizeof(led_segment_b_data);
	constexpr auto led_segment_c_size = sizeof(led_segment_c_data);
	constexpr auto led_segment_d_size = sizeof(led_segment_d_data);
	constexpr auto led_segment_e_size = sizeof(led_segment_e_data);
	constexpr auto led_segment_f_size = sizeof(led_segment_f_data);
	constexpr auto led_segment_g_size = sizeof(led_segment_g_data);

	static const Path led_segment_a{ Paths_A::load_path(led_segment_a_data, led_segment_a_size) };
	static const Path led_segment_b{ Paths_A::load_path(led_segment_b_data, led_segment_b_size) };
	static const Path led_segment_c{ Paths_A::load_path(led_segment_c_data, led_segment_c_size) };
	static const Path led_segment_d{ Paths_A::load_path(led_segment_d_data, led_segment_d_size) };
	static const Path led_segment_e{ Paths_A::load_path(led_segment_e_data, led_segment_e_size) };
	static const Path led_segment_f{ Paths_A::load_path(led_segment_f_data, led_segment_f_size) };
	static const Path led_segment_g{ Paths_A::load_path(led_segment_g_data, led_segment_g_size) };

}
