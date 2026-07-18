#pragma once

#include <JuceHeader.h>

#include "C_COLOR_G.h"

namespace COLOR
{

	const Colour grey{ 0xff505050 };
	const Colour grey_dark{ 0xff171717 };
	const Colour grey_lite{ 0xffa6a6a6 };
	const Colour red_btn{ 0xff7d0000 };
	const Colour red_led_1{ 0xff2d0000 };
	const Colour red_led_2{ 0xff460000 };
	const Colour red_led_3{ 0xffed1c24 };
	const Colour translucent_white{ 0xa6ffffff };
	const Colour tip_border{ COLOR::white };
	const Colour txt_caret{ red_led_3.withAlpha(0.75f) };
	const Colour txt_highlight{ red_led_3.withAlpha(0.4f) };

}