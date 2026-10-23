#pragma once

namespace MIDI
{

	constexpr auto data_size_exp = 192;
	constexpr auto data_size_m_mod = 60;
	constexpr auto data_size_pgm = 268;

	constexpr unsigned char id_device = 6;
	constexpr unsigned char id_maker = 16;
	constexpr unsigned char id_xpander = 2;

	constexpr unsigned char mode_global = 3;
	constexpr unsigned char mode_pgm = 1;
	constexpr unsigned char mode_split = 2;

	constexpr unsigned char msg_type_dump_request = 4;
	constexpr unsigned char msg_type_mode_change = 13;
	constexpr unsigned char msg_type_quick_edit = 6;
	constexpr unsigned char msg_type_quick_edit_enable = 5;

	constexpr unsigned char tx_val_for_bar_char = 29;

}