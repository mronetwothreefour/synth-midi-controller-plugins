#pragma once

#include "C_COLOR_A.h"

namespace COLOR
{

	const Colour blue{ 0xff05239d };
	const Colour blue_led{ 0xff00bed6 };
	const Colour env_stroke{ blue_led };
	const Colour grey{ 0xff3f3f3f };
	const Colour grey_line{ 0xff656565 };
	const Colour ground{ 0xff131316 };
	const Colour off_white{ 0xffe1e1e1 };
	const Colour orange{ 0xffb53100 };
	const Colour tip_border{ blue_led };
	const Colour txt_caret{ blue_led.withAlpha(0.9f) };
	const Colour txt_highlight{ blue_led.withAlpha(0.60f) };

}
