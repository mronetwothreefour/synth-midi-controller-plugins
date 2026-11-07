#include "G_DRAW_Paths_LED_P.h"

#include "C_COLOR_P.h"
#include "C_MISC_P.h"
#include "C_RES_LED_P.h"

void DRAW::Paths_LED::digit(Graphics& g, const int d, AffineTransform transform) {
	auto& flags = MISC::led_segment_flags[std::clamp(d, 0, 9)];
	Colour off{ COLOR::red_led_2 };
	Colour on{ COLOR::red_led_3 };
	g.setColour(std::get<0>(flags) ? on : off);
	g.fillPath(RES::led_segment_a, transform);
	g.setColour(std::get<1>(flags) ? on : off);
	g.fillPath(RES::led_segment_b, transform);
	g.setColour(std::get<2>(flags) ? on : off);
	g.fillPath(RES::led_segment_c, transform);
	g.setColour(std::get<3>(flags) ? on : off);
	g.fillPath(RES::led_segment_d, transform);
	g.setColour(std::get<4>(flags) ? on : off);
	g.fillPath(RES::led_segment_e, transform);
	g.setColour(std::get<5>(flags) ? on : off);
	g.fillPath(RES::led_segment_f, transform);
	g.setColour(std::get<6>(flags) ? on : off);
	g.fillPath(RES::led_segment_g, transform);
}
