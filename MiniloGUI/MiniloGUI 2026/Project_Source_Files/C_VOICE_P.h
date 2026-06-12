#pragma once

#include <JuceHeader.h>

namespace VOICE
{
	const int voice_name_char_count{ 12 };

	static const int voice_data_msg_size{ 511 };

	const String allowed_name_chars{ " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?#$%&'()*+,-./:;<=>@" };
	const String init_voice_name{ "Init Program" };
}