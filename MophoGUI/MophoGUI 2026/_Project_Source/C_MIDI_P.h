#pragma once

namespace MIDI
{

	constexpr auto data_size_pgm = 298;

	constexpr unsigned char id_device = 37;
	constexpr unsigned char id_maker = 1;

	constexpr unsigned char msg_type_dump_global = 15;
	constexpr unsigned char msg_type_dump_pgm = 2;
	constexpr unsigned char msg_type_dump_pgm_buffer = 3;
	constexpr unsigned char msg_type_request_global = 14;
	constexpr unsigned char msg_type_request_pgm = 5;
	constexpr unsigned char msg_type_request_pgm_buffer = 6;
}