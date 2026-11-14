#pragma once

namespace MIDI
{

	constexpr auto data_size_exp = 192;
	constexpr auto data_size_m_mod = 60;
	constexpr auto data_size_pgm = 268;

	constexpr auto first_exp_data_byte = 16;
	constexpr auto first_mmod_data_byte = 208;

	constexpr unsigned char id_device = 6;
	constexpr unsigned char id_maker = 16;
	constexpr unsigned char id_xpander = 2;

	constexpr unsigned char msg_type_dump_global = 3;
	constexpr unsigned char msg_type_dump_pgm = 1;
	constexpr unsigned char msg_type_dump_request = 4;
	constexpr unsigned char msg_type_dump_split = 2;
	constexpr unsigned char msg_type_mode_change = 13;
	constexpr unsigned char msg_type_quick_edit = 6;
	constexpr unsigned char msg_type_quick_edit_enable = 5;

	constexpr auto pgm_hex_string_length = 270;

	constexpr unsigned char stored_ascii_val_for_bar = 29;

}