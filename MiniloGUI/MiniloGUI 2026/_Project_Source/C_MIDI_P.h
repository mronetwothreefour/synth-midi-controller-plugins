#pragma once

namespace MIDI
{

	constexpr unsigned char id_device = 48;
	constexpr unsigned char id_maker = 66;

	constexpr unsigned char msg_type_dump_global = 81;
	constexpr unsigned char msg_type_dump_microtune_octave = 0x69;
	constexpr unsigned char msg_type_dump_microtune_scale = 68;
	constexpr unsigned char msg_type_dump_pgm = 76;
	constexpr unsigned char msg_type_dump_pgm_buffer = 64;
	constexpr unsigned char msg_type_request_global = 14;
	constexpr unsigned char msg_type_request_microtune_octave = 21;
	constexpr unsigned char msg_type_request_microtune_scale = 20;
	constexpr unsigned char msg_type_request_pgm = 28;
	constexpr unsigned char msg_type_request_pgm_buffer = 16;

}