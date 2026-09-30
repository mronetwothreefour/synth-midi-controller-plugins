#pragma once

#include "G_DRAW_Paths_A.h"

using namespace DRAW;

namespace RES
{

	constexpr unsigned char led_segment_a_data[]{ 110,109,152,199,156,63,0,0,0,0,108,188,70,29,64,154,153,153,63,108,179,9,141,64,154,153,153,63,108,172,26,163,64,222,78,69,62,108,26,112,179,64,154,153,153,63,108,154,121,239,64,154,153,153,63,108,0,0,16,65,0,0,0,0,99,101,0,0 };
	constexpr unsigned char led_segment_b_data[]{ 110,109,194,17,240,64,255,222,89,64,108,0,0,16,65,0,0,0,0,108,134,51,6,65,0,0,224,64,108,227,239,230,64,215,163,204,64,99,101,0,0 };
	constexpr unsigned char led_segment_c_data[]{ 110,109,134,51,6,65,0,0,224,64,108,26,206,248,64,0,0,96,65,108,61,195,219,64,111,133,42,65,108,160,82,228,64,51,51,243,64,99,101,0,0 };
	constexpr unsigned char led_segment_d_data[]{ 110,109,26,206,248,64,0,0,96,65,108,0,0,0,0,255,255,95,65,108,149,25,194,63,205,204,76,65,108,203,31,89,64,205,204,76,65,108,228,85,121,64,146,5,92,65,108,76,246,146,64,205,204,76,65,108,162,92,209,64,205,204,76,65,99,101,0,0 };
	constexpr unsigned char led_segment_e_data[]{ 110,109,0,0,0,0,0,0,96,65,108,151,199,28,63,0,0,224,64,108,76,69,225,63,51,51,243,64,108,245,184,191,63,64,136,41,65,99,101,0,0 };
	constexpr unsigned char led_segment_f_data[]{ 110,109,152,199,156,63,0,0,0,0,108,133,121,8,64,67,234,85,64,108,126,181,238,63,205,204,204,64,108,151,199,28,63,0,0,224,64,99,101,0,0 };
	constexpr unsigned char led_segment_g_data[]{ 110,109,152,199,156,63,0,0,0,0,108,188,70,29,64,154,153,153,63,108,20,46,131,64,138,19,151,64,108,0,0,144,64,0,0,224,64,108,93,185,99,64,205,204,204,64,108,133,121,8,64,67,234,85,64,99,101,0,0 };
	constexpr unsigned char led_segment_h_data[]{ 110,109,20,46,131,64,138,19,151,64,108,179,9,141,64,154,153,153,63,108,172,26,163,64,222,78,69,62,108,26,112,179,64,154,153,153,63,108,104,225,169,64,57,164,147,64,108,0,0,144,64,0,0,224,64,99,101,0,0 };
	constexpr unsigned char led_segment_i_data[]{ 110,109,154,121,239,64,153,153,153,63,108,0,0,16,65,0,0,0,0,108,194,17,240,64,255,222,89,64,108,58,255,178,64,205,204,204,64,108,0,0,144,64,0,0,224,64,108,104,225,169,64,58,164,147,64,99,101,0,0 };
	constexpr unsigned char led_segment_j_data[]{ 110,109,39,63,231,64,205,204,204,64,108,134,51,6,65,0,0,224,64,108,160,82,228,64,51,51,243,64,108,81,35,174,64,51,51,243,64,108,0,0,144,64,0,0,224,64,108,58,255,178,64,205,204,204,64,99,101,0,0 };
	constexpr unsigned char led_segment_k_data[]{ 110,109,81,35,174,64,51,51,243,64,108,61,195,219,64,111,133,42,65,108,26,206,248,64,0,0,96,65,108,162,92,209,64,205,204,76,65,108,236,209,156,64,59,118,20,65,108,0,0,144,64,0,0,224,64,99,101,0,0 };
	constexpr unsigned char led_segment_l_data[]{ 110,109,0,0,144,64,0,0,224,64,108,236,209,156,64,59,118,20,65,108,76,246,146,64,205,204,76,65,108,228,85,121,64,146,5,92,65,108,203,31,89,64,205,204,76,65,108,46,61,108,64,228,45,22,65,99,101,0,0 };
	constexpr unsigned char led_segment_m_data[]{ 110,109,0,0,144,64,0,0,224,64,108,46,61,108,64,228,45,22,65,108,147,25,194,63,205,204,76,65,108,55,51,53,53,254,255,95,65,108,240,184,191,63,65,136,41,65,108,203,31,89,64,51,51,243,64,99,101,0,0 };
	constexpr unsigned char led_segment_n_data[]{ 110,109,126,181,238,63,205,204,204,64,108,92,185,99,64,205,204,204,64,108,0,0,144,64,0,0,224,64,108,204,31,89,64,51,51,243,64,108,76,69,225,63,51,51,243,64,108,151,199,28,63,0,0,224,64,99,101,0,0 };
	constexpr unsigned char led_segment_o_data[]{ 110,109,177,211,10,65,196,141,85,65,108,248,206,12,65,98,84,66,65,108,93,241,25,65,41,132,60,65,108,144,8,40,65,48,75,67,65,108,42,1,38,65,246,133,87,65,108,254,180,23,65,113,21,93,65,99,101,0,0 };
	constexpr unsigned char led_segment_p_data[]{ 110,109,170,248,9,65,0,0,96,65,108,171,34,37,65,0,0,96,65,108,39,230,35,65,33,194,105,65,108,82,14,14,65,222,255,127,65,108,102,102,6,65,0,0,128,65,99,101,0,0 };
	constexpr unsigned char led_vert_bar_data[]{
		110,109,154,153,25,63,0,0,128,63,108,0,0,0,0,254,255,255,63,108,0,0,0,0,0,248,15,65,108,154,153,25,63,0,0,32,65,108,154,153,153,63,0,248,15,65,108,154,153,153,63,254,255,255,63,99,109,154,153,25,63,0,0,32,65,108,0,0,0,0,0,0,48,65,108,0,0,0,0,0,252,143,
		65,108,154,153,25,63,0,0,152,65,108,154,153,153,63,0,252,143,65,108,154,153,153,63,0,0,48,65,99,101,0,0
	};

	constexpr auto led_segment_a_size = sizeof(led_segment_a_data);
	constexpr auto led_segment_b_size = sizeof(led_segment_b_data);
	constexpr auto led_segment_c_size = sizeof(led_segment_c_data);
	constexpr auto led_segment_d_size = sizeof(led_segment_d_data);
	constexpr auto led_segment_e_size = sizeof(led_segment_e_data);
	constexpr auto led_segment_f_size = sizeof(led_segment_f_data);
	constexpr auto led_segment_g_size = sizeof(led_segment_g_data);
	constexpr auto led_segment_h_size = sizeof(led_segment_h_data);
	constexpr auto led_segment_i_size = sizeof(led_segment_i_data);
	constexpr auto led_segment_j_size = sizeof(led_segment_j_data);
	constexpr auto led_segment_k_size = sizeof(led_segment_k_data);
	constexpr auto led_segment_l_size = sizeof(led_segment_l_data);
	constexpr auto led_segment_m_size = sizeof(led_segment_m_data);
	constexpr auto led_segment_n_size = sizeof(led_segment_n_data);
	constexpr auto led_segment_o_size = sizeof(led_segment_o_data);
	constexpr auto led_segment_p_size = sizeof(led_segment_p_data);
	constexpr auto led_vert_bar_size = sizeof(led_vert_bar_data);

	static const Path led_segment_a{ Paths_A::load_path(led_segment_a_data, led_segment_a_size) };
	static const Path led_segment_b{ Paths_A::load_path(led_segment_b_data, led_segment_b_size) };
	static const Path led_segment_c{ Paths_A::load_path(led_segment_c_data, led_segment_c_size) };
	static const Path led_segment_d{ Paths_A::load_path(led_segment_d_data, led_segment_d_size) };
	static const Path led_segment_e{ Paths_A::load_path(led_segment_e_data, led_segment_e_size) };
	static const Path led_segment_f{ Paths_A::load_path(led_segment_f_data, led_segment_f_size) };
	static const Path led_segment_g{ Paths_A::load_path(led_segment_g_data, led_segment_g_size) };
	static const Path led_segment_h{ Paths_A::load_path(led_segment_h_data, led_segment_h_size) };
	static const Path led_segment_i{ Paths_A::load_path(led_segment_i_data, led_segment_i_size) };
	static const Path led_segment_j{ Paths_A::load_path(led_segment_j_data, led_segment_j_size) };
	static const Path led_segment_k{ Paths_A::load_path(led_segment_k_data, led_segment_k_size) };
	static const Path led_segment_l{ Paths_A::load_path(led_segment_l_data, led_segment_l_size) };
	static const Path led_segment_m{ Paths_A::load_path(led_segment_m_data, led_segment_m_size) };
	static const Path led_segment_n{ Paths_A::load_path(led_segment_n_data, led_segment_n_size) };
	static const Path led_segment_o{ Paths_A::load_path(led_segment_o_data, led_segment_o_size) };
	static const Path led_segment_p{ Paths_A::load_path(led_segment_p_data, led_segment_p_size) };
	static const Path led_vert_bar{ Paths_A::load_path(led_vert_bar_data, led_vert_bar_size) };

}