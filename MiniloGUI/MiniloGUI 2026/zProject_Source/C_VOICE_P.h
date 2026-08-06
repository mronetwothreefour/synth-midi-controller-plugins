#pragma once

namespace VOICE
{
	constexpr int voice_name_char_count{ 12 };

	constexpr int voice_data_msg_size{ 511 };

	static String allowed_name_chars{ " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?#$%&'()*+,-./:;<=>@" };
	static String init_voice_name{ "Init Program" };
}