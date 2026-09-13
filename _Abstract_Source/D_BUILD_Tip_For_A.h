#pragma once

#include <string>

namespace BUILD 
{

	struct Tip_For_A
	{
		static std::string from_SL(const char8_t* string_literal);
		static std::string txt_editor_pitch(const unsigned int example,
											const unsigned int min,
											const unsigned int max);
		static std::string txt_editor_s_int(const int abs_limit);
		static std::string txt_editor_u_int(const unsigned int max);
	};

}
