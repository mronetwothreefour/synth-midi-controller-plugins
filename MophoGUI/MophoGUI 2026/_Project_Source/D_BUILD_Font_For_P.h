#pragma once

#include <JuceHeader.h>

namespace BUILD
{

	struct Font_For
	{
		static const FontOptions bold();
		static const FontOptions semi();

		static const Font cbox(const float scale_factor);
		static const Font file_browser(const float scale_factor);
		static const Font knob(const float scale_factor);
		static const Font knob_txt_edit(const float scale_factor);
		static const Font pulse_w_txt(const float scale_factor);
		static const Font seq_step(const float scale_factor);
		static const Font tip();
	};

}
