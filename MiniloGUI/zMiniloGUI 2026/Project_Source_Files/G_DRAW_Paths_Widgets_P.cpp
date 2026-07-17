#include "G_DRAW_Paths_Widgets_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_Widgets_P.h"

void Draw_Paths_Widgets_P::draw_switch_h_led(Graphics& g, float& scale, char pos, Colour clr) {
	Path led{};
	switch (pos)
	{
	case 'a': led.addPath(load_path(PATH::switch_h_led_a, sizeof(PATH::switch_h_led_a))); break;
	case 'b': led.addPath(load_path(PATH::switch_h_led_b, sizeof(PATH::switch_h_led_b))); break;
	case 'c': led.addPath(load_path(PATH::switch_h_led_c, sizeof(PATH::switch_h_led_c))); break;
	case 'd': led.addPath(load_path(PATH::switch_h_led_d, sizeof(PATH::switch_h_led_d))); break;
	case 'e': led.addPath(load_path(PATH::switch_h_led_e, sizeof(PATH::switch_h_led_e))); break;
	default: break;
	}
	if (!led.isEmpty()) {
		g.setColour(clr);
		g.fillPath(led, AffineTransform::scale(scale));
	}
}

void Draw_Paths_Widgets_P::draw_switch_h_slot(Graphics& g, float& scale) {
	Path slot{ load_path(PATH::switch_h_slot, sizeof(PATH::switch_h_slot)) };
	g.setColour(COLOR::black);
	g.fillPath(slot, AffineTransform::scale(scale));
}

void Draw_Paths_Widgets_P::draw_switch_h_tab(Graphics& g, float& scale, char pos) {
	Path tab{};
	switch (pos)
	{
	case 'a': tab.addPath(load_path(PATH::switch_h_tab_a, sizeof(PATH::switch_h_tab_a))); break;
	case 'b': tab.addPath(load_path(PATH::switch_h_tab_b, sizeof(PATH::switch_h_tab_b))); break;
	case 'c': tab.addPath(load_path(PATH::switch_h_tab_c, sizeof(PATH::switch_h_tab_c))); break;
	case 'd': tab.addPath(load_path(PATH::switch_h_tab_d, sizeof(PATH::switch_h_tab_d))); break;
	case 'e': tab.addPath(load_path(PATH::switch_h_tab_e, sizeof(PATH::switch_h_tab_e))); break;
	default: break;
	}
	if (!tab.isEmpty()) {
		g.setColour(COLOR::grey_switch_tabs);
		g.fillPath(tab, AffineTransform::scale(scale));
	}
}

void Draw_Paths_Widgets_P::draw_switch_v_led(Graphics& g, float& scale, char pos, Colour clr) {
	Path led{};
	switch (pos)
	{
	case 'a': led.addPath(load_path(PATH::switch_v_led_a, sizeof(PATH::switch_v_led_a))); break;
	case 'b': led.addPath(load_path(PATH::switch_v_led_b, sizeof(PATH::switch_v_led_b))); break;
	case 'c': led.addPath(load_path(PATH::switch_v_led_c, sizeof(PATH::switch_v_led_c))); break;
	case 'd': led.addPath(load_path(PATH::switch_v_led_d, sizeof(PATH::switch_v_led_d))); break;
	default: break;
	}
	if (!led.isEmpty()) {
		g.setColour(clr);
		g.fillPath(led, AffineTransform::scale(scale));
	}
}

void Draw_Paths_Widgets_P::draw_switch_v_slot(Graphics& g, float& scale) {
	Path slot{ load_path(PATH::switch_v_slot, sizeof(PATH::switch_v_slot)) };
	g.setColour(COLOR::black);
	g.fillPath(slot, AffineTransform::scale(scale));
}

void Draw_Paths_Widgets_P::draw_switch_v_tab(Graphics& g, float& scale, char pos) {
	Path tab{};
	switch (pos)
	{
	case 'a': tab.addPath(load_path(PATH::switch_v_tab_a, sizeof(PATH::switch_v_tab_a))); break;
	case 'b': tab.addPath(load_path(PATH::switch_v_tab_b, sizeof(PATH::switch_v_tab_b))); break;
	case 'c': tab.addPath(load_path(PATH::switch_v_tab_c, sizeof(PATH::switch_v_tab_c))); break;
	case 'd': tab.addPath(load_path(PATH::switch_v_tab_d, sizeof(PATH::switch_v_tab_d))); break;
	case 'e': tab.addPath(load_path(PATH::switch_v_tab_e, sizeof(PATH::switch_v_tab_e))); break;
	default: break;
	}
	if (!tab.isEmpty()) {
		g.setColour(COLOR::grey_switch_tabs);
		g.fillPath(tab, AffineTransform::scale(scale));
	}
}

void Draw_Paths_Widgets_P::knob(Graphics& g, float& rotation, float& scale) {
	auto body = load_path(PATH::knob_body, sizeof(PATH::knob_body));
	g.setColour(COLOR::black);
	g.fillPath(body, AffineTransform::scale(scale));
	auto indicator = load_path(PATH::knob_indicator, sizeof(PATH::knob_indicator));
	indicator.applyTransform(AffineTransform::rotation(rotation, 17, 17));
	g.setColour(COLOR::grey_knob_indicators);
	g.fillPath(indicator, AffineTransform::scale(scale));
}

void Draw_Paths_Widgets_P::knob_lpf_freq(Graphics& g, float& rotation, float& scale) {
	auto body = load_path(PATH::knob_lpf_freq_body, sizeof(PATH::knob_lpf_freq_body));
	g.setColour(COLOR::black);
	g.fillPath(body, AffineTransform::scale(scale));
	auto indicator = load_path(PATH::knob_lpf_freq_indicator, sizeof(PATH::knob_lpf_freq_indicator));
	indicator.applyTransform(AffineTransform::rotation(rotation, 25, 25));
	g.setColour(COLOR::grey_knob_indicators);
	g.fillPath(indicator, AffineTransform::scale(scale));
}

void Draw_Paths_Widgets_P::switch_2_pole(Graphics& g, float& scale, int setting) {
	draw_switch_v_slot(g, scale);
	switch (setting)
	{
	case 0: draw_switch_v_tab(g, scale, 'a'); break;
	case 1: draw_switch_v_tab(g, scale, 'e'); break;
	default: break;
	}
}

void Draw_Paths_Widgets_P::switch_3_pole(Graphics& g, float& scale, int setting) {
	draw_switch_v_slot(g, scale);
	switch (setting)
	{
	case 0: draw_switch_v_tab(g, scale, 'a'); break;
	case 1: draw_switch_v_tab(g, scale, 'c'); break;
	case 2: draw_switch_v_tab(g, scale, 'e'); break;
	default: break;
	}
}

void Draw_Paths_Widgets_P::switch_osc_octave(Graphics& g, float& scale, int setting) {
	draw_switch_v_slot(g, scale);
	switch (setting)
	{
	case 0: draw_switch_v_tab(g, scale, 'a'); break;
	case 1: draw_switch_v_tab(g, scale, 'b'); break;
	case 2: draw_switch_v_tab(g, scale, 'd'); break;
	case 3: draw_switch_v_tab(g, scale, 'e'); break;
	default: break;
	}
	draw_switch_v_led(g, scale, 'a', setting == 0 ? COLOR::red_led_on : COLOR::red_led_off);
	draw_switch_v_led(g, scale, 'b', setting == 1 ? COLOR::red_led_on : COLOR::red_led_off);
	draw_switch_v_led(g, scale, 'c', setting == 2 ? COLOR::red_led_on : COLOR::red_led_off);
	draw_switch_v_led(g, scale, 'd', setting == 3 ? COLOR::red_led_on : COLOR::red_led_off);
}

void Draw_Paths_Widgets_P::switch_lpf_type(Graphics& g, float& scale, int setting) {
	auto t = AffineTransform::translation(8, 16);
	auto slot = load_path(PATH::switch_v_slot, sizeof(PATH::switch_v_slot));
	slot.applyTransform(t);
	g.setColour(COLOR::black);
	g.fillPath(slot, AffineTransform::scale(scale));
	Path tab{};
	if (setting == 0)
		tab.addPath(load_path(PATH::switch_v_tab_a, sizeof(PATH::switch_v_tab_a)));
	if (setting == 1)
		tab.addPath(load_path(PATH::switch_v_tab_e, sizeof(PATH::switch_v_tab_e)));
	if (!tab.isEmpty()) {
		tab.applyTransform(t);
		g.setColour(COLOR::grey_switch_tabs);
		g.fillPath(tab, AffineTransform::scale(scale));
	}
}

void Draw_Paths_Widgets_P::switch_keyboard_octave(Graphics& g, float& scale, int setting) {
	draw_switch_h_slot(g, scale);
	switch (setting)
	{
	case 0: draw_switch_h_tab(g, scale, 'a'); break;
	case 1: draw_switch_h_tab(g, scale, 'b'); break;
	case 2: draw_switch_h_tab(g, scale, 'c'); break;
	case 3: draw_switch_h_tab(g, scale, 'd'); break;
	case 4: draw_switch_h_tab(g, scale, 'e'); break;
	default: break;
	}
	draw_switch_h_led(g, scale, 'a', setting == 0 ? COLOR::red_led_on : COLOR::red_led_off);
	draw_switch_h_led(g, scale, 'b', setting == 1 ? COLOR::red_led_on : COLOR::red_led_off);
	draw_switch_h_led(g, scale, 'c', setting == 2 ? COLOR::red_led_on : COLOR::red_led_off);
	draw_switch_h_led(g, scale, 'd', setting == 3 ? COLOR::red_led_on : COLOR::red_led_off);
	draw_switch_h_led(g, scale, 'e', setting == 4 ? COLOR::red_led_on : COLOR::red_led_off);
}
