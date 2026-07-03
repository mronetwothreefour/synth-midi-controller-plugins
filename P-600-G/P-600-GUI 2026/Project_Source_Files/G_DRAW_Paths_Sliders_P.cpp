#include "G_DRAW_Paths_Sliders_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_Sliders_P.h"

void Draw_Paths_Sliders_P::draw_switch_tab(Graphics& g, float& scale, char pos) {
	Path tab_dark{};
	switch (pos)
	{
	case 'a': tab_dark.addPath(load_path(PATH::switch_tab_grey_dark_a, sizeof(PATH::switch_tab_grey_dark_a))); break;
	case 'b': tab_dark.addPath(load_path(PATH::switch_tab_grey_dark_b, sizeof(PATH::switch_tab_grey_dark_b))); break;
	case 'c': tab_dark.addPath(load_path(PATH::switch_tab_grey_dark_c, sizeof(PATH::switch_tab_grey_dark_c))); break;
	default: break;
	}
	if (!tab_dark.isEmpty()) {
		g.setColour(COLOR::grey_dark);
		g.fillPath(tab_dark, AffineTransform::scale(scale));
	}
	Path tab{};
	switch (pos)
	{
	case 'a': tab.addPath(load_path(PATH::switch_tab_grey_a, sizeof(PATH::switch_tab_grey_a))); break;
	case 'b': tab.addPath(load_path(PATH::switch_tab_grey_b, sizeof(PATH::switch_tab_grey_b))); break;
	case 'c': tab.addPath(load_path(PATH::switch_tab_grey_c, sizeof(PATH::switch_tab_grey_c))); break;
	default: break;
	}
	if (!tab.isEmpty()) {
		g.setColour(COLOR::grey);
		g.fillPath(tab, AffineTransform::scale(scale));
	}
}

void Draw_Paths_Sliders_P::knob(Graphics& g, float& rotation, float& scale) {
	auto body = load_path(PATH::knob_body, sizeof(PATH::knob_body));
	g.setColour(COLOR::grey_dark);
	g.fillPath(body, AffineTransform::scale(scale));
	auto indicator = load_path(PATH::knob_indicator, sizeof(PATH::knob_indicator));
	indicator.applyTransform(AffineTransform::rotation(rotation, 17, 17));
	g.setColour(COLOR::grey);
	g.fillPath(indicator, AffineTransform::scale(scale));
}

void Draw_Paths_Sliders_P::switch_2_pole(Graphics& g, float& scale, int setting) {
	Path slot{ load_path(PATH::switch_slot_2_pole, sizeof(PATH::switch_slot_2_pole)) };
	g.setColour(COLOR::black);
	g.fillPath(slot, AffineTransform::scale(scale));
	switch (setting)
	{
	case 0: draw_switch_tab(g, scale, 'b'); break;
	case 1: draw_switch_tab(g, scale, 'c'); break;
	default: break;
	}
}

void Draw_Paths_Sliders_P::switch_3_pole(Graphics& g, float& scale, int setting) {
	Path slot{ load_path(PATH::switch_slot_3_pole, sizeof(PATH::switch_slot_3_pole)) };
	g.setColour(COLOR::black);
	g.fillPath(slot, AffineTransform::scale(scale));
	switch (setting)
	{
	case 0: draw_switch_tab(g, scale, 'a'); break;
	case 1: draw_switch_tab(g, scale, 'b'); break;
	case 2: draw_switch_tab(g, scale, 'c'); break;
	default: break;
	}
}
