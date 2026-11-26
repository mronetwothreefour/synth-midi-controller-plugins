#pragma once

namespace MIDI
{

	constexpr auto cc_msg_prefix = 176;

	constexpr auto data_size_pgm = 293;

	constexpr unsigned char id_device = 37;
	constexpr unsigned char id_maker = 1;

	constexpr unsigned char msg_type_dump_global = 15;
	constexpr unsigned char msg_type_dump_pgm = 2;
	constexpr unsigned char msg_type_dump_pgm_buffer = 3;
	constexpr unsigned char msg_type_request_global = 14;
	constexpr unsigned char msg_type_request_pgm = 5;
	constexpr unsigned char msg_type_request_pgm_buffer = 6;

	constexpr unsigned char nrpn_id_lsb = 98;
	constexpr unsigned char nrpn_id_msb = 99;
	constexpr unsigned char nrpn_val_lsb = 38;
	constexpr unsigned char nrpn_val_msb = 6;

	constexpr auto pgm_hex_string_length = 458;

}