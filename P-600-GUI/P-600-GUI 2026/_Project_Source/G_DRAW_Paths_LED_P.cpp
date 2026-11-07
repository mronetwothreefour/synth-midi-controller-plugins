#include "G_DRAW_Paths_LED_P.h"

#include "C_COLOR_P.h"
#include "C_MISC_P.h"
#include "C_RES_LED_P.h"

void DRAW::Paths_LED::digit(Graphics& g, const int d, AffineTransform transform) {
	auto flags = MISC::led_segment_flags[std::clamp(d, 0, 99)];
	Colour off{ COLOR::red_led_2 };
	Colour on{ COLOR::red_led_3 };
	g.setColour(flags & 1 ? on : off);
	g.fillPath(RES::led_segment_a, transform);
	g.setColour(flags & 2 ? on : off);
	g.fillPath(RES::led_segment_b, transform);
	g.setColour(flags & 4 ? on : off);
	g.fillPath(RES::led_segment_c, transform);
	g.setColour(flags & 8 ? on : off);
	g.fillPath(RES::led_segment_d, transform);
	g.setColour(flags & 16 ? on : off);
	g.fillPath(RES::led_segment_e, transform);
	g.setColour(flags & 32 ? on : off);
	g.fillPath(RES::led_segment_f, transform);
	g.setColour(flags & 64 ? on : off);
	g.fillPath(RES::led_segment_g, transform);
	g.setColour(flags & 128 ? on : off);
}
