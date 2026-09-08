#pragma once

#include <JuceHeader.h>

namespace BUILD 
{

	struct Tip_For_A
	{
		static String from_string_literal(const char8_t* sl);
		static String txt_editor_pitch(const String& example_name, const int example_num,
									   const String& min_name, const int min_num,
									   const String& max_name, const int max_num);
		static String txt_editor_s_int(const int abs_limit);
		static String txt_editor_u_int(const int max);
	};

}
