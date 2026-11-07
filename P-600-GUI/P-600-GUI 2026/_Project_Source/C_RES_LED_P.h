#pragma once

#include "G_DRAW_Paths_A.h"

using namespace DRAW;

namespace RES
{

	constexpr unsigned char led_segment_a_data[]{ 110,109,147,129,247,64,0,0,0,0,108,177,32,162,65,0,0,0,0,108,98,22,154,65,187,73,100,64,108,248,28,1,65,187,73,100,64,99,101,0,0 };
	constexpr unsigned char led_segment_b_data[]{ 
		110,109,182,116,169,65,181,232,55,61,108,76,188,158,65,77,175,130,64,108,185,167,147,65,132,124,107,65,108,249,3,158,65,189,210,132,65,108,108,61,171,65,189,210,132,65,98,108,61,171,65,189,210,132,65,214,118,179,65,58,112,125,65,0,211,179,65,32,65,118,
		65,108,247,247,191,65,130,201,252,63,98,73,176,192,65,188,220,101,63,111,229,180,65,192,232,55,61,182,116,169,65,192,232,55,61,101,0,0
	};
	constexpr unsigned char led_segment_c_data[]{ 
		110,109,61,5,136,65,0,0,8,66,108,234,205,132,65,178,157,238,65,108,248,33,145,65,110,18,154,65,108,17,75,162,65,77,98,137,65,108,36,159,174,65,77,98,137,65,98,36,159,174,65,77,98,137,65,63,77,177,65,76,98,144,65,205,58,176,65,9,215,150,65,98,91,40,175,
		65,210,77,157,65,17,75,162,65,208,77,255,65,17,75,162,65,208,77,255,65,98,163,56,161,65,234,166,6,66,161,189,146,65,0,0,8,66,60,5,136,65,0,0,8,66,101,0,0
	};
	constexpr unsigned char led_segment_d_data[]{ 110,109,155,31,130,65,0,0,8,66,108,126,250,110,64,0,0,8,66,108,118,166,151,64,200,118,243,65,108,0,227,126,65,200,118,243,65,99,101,0,0 };
	constexpr unsigned char led_segment_e_data[]{ 
		110,109,81,90,52,64,5,210,7,66,108,190,14,133,64,44,84,239,65,108,10,97,177,64,189,65,154,65,108,12,240,135,64,66,45,139,65,108,124,20,38,64,66,45,139,65,98,124,20,38,64,66,45,139,65,146,146,200,63,226,71,145,65,245,207,194,63,111,223,148,65,108,0,145,
		128,59,180,25,0,66,98,60,75,176,189,141,104,4,66,214,168,177,63,5,210,7,66,81,90,52,64,5,210,7,66,101,0,0
	};
	constexpr unsigned char led_segment_f_data[]{ 
		110,109,15,235,223,64,0,0,0,0,108,89,200,236,64,56,137,133,64,108,15,120,187,64,35,219,107,65,108,85,167,109,64,178,157,134,65,108,192,6,11,64,178,157,134,65,98,192,6,11,64,178,157,134,65,14,44,235,63,100,59,127,65,245,82,252,63,236,81,114,65,98,7,189,
		6,64,90,100,101,65,85,167,109,64,106,145,5,64,85,167,109,64,106,145,5,64,98,229,58,118,64,70,139,172,62,106,9,181,64,0,0,0,0,15,235,223,64,0,0,0,0,101,0,0
	};
	constexpr unsigned char led_segment_g_data[]{ 110,109,78,113,157,64,79,158,134,65,108,253,0,200,64,253,229,150,65,108,29,50,138,65,253,229,150,65,108,146,21,154,65,1,60,136,65,108,68,183,142,65,118,11,115,65,108,9,130,205,64,118,11,115,65,99,101,0,0 };

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
