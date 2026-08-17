#pragma once

#include <JuceHeader.h>

namespace BUILD
{

	struct Font_For
	{
		static const FontOptions bold();

		static const Font file_browser(const float scale_factor);
		static const Font knob(const float scale_factor);
		static const Font knob_txt_edit(const float scale_factor);
		static const Font tip();
	};

}
