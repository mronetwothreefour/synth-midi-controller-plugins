#pragma once

#include <JuceHeader.h>

#include "C_COLOR_G.h"

namespace COLOR
{

	const Colour ground{ 0xffde9600 };
	const Colour red_btn{ 0xff870000 };
	const Colour red_btn_lite_1{ 0xffb40000 };
	const Colour red_btn_lite_2{ 0xffc80000 };
	const Colour red_btn_dark_1{ 0xff500000 };
	const Colour red_btn_dark_2{ 0xff640000 };
	const Colour red_toggle_off{ 0xff4a0000 };
	const Colour red_toggle_on{ 0xffff0000 };
	const Colour tip_border{ COLOR::white };
	const Colour yellow{ 0xffffbe00 };
	const Colour txt_caret{ yellow.withAlpha(0.9f) };
	const Colour txt_highlight{ yellow.withAlpha(0.6f) };

}