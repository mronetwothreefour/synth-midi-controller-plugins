#include "G_DRAW_Paths_Editor_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_Editor_Background_P.h"

void Draw_Paths_Editor_P::background(Graphics& g) {
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::editor_black, sizeof(PATH::editor_black)));
	g.setColour(COLOR::translucent_white);
	g.fillPath(load_path(PATH::editor_translucent_white, sizeof(PATH::editor_translucent_white)));
	g.setColour(COLOR::grey_dark);
	g.fillPath(load_path(PATH::editor_grey_dark, sizeof(PATH::editor_grey_dark)));
	g.setColour(COLOR::grey);
	g.fillPath(load_path(PATH::editor_grey, sizeof(PATH::editor_grey)));
	g.setColour(COLOR::red_led_1);
	g.fillPath(load_path(PATH::editor_red_led_1, sizeof(PATH::editor_red_led_1)));
	g.setColour(COLOR::red_led_2);
	g.fillPath(load_path(PATH::editor_red_led_2, sizeof(PATH::editor_red_led_2)));
	g.setColour(COLOR::red_btn);
	g.fillPath(load_path(PATH::editor_red_btn, sizeof(PATH::editor_red_btn)));
	g.setColour(COLOR::grey_lite);
	g.fillPath(load_path(PATH::editor_grey_lite, sizeof(PATH::editor_grey_lite)));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(load_path(PATH::editor_alt_underlines, sizeof(PATH::editor_alt_underlines)));
}
