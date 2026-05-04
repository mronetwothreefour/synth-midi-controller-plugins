#include "G_Paint_Paths.h"

#include "C_COLOR.h"
#include "C_PATH_Editor_Background.h"
#include "C_XYWH.h"

Path Paint_Paths::load_path(const void* data, size_t data_size) {
	Path path;
	path.loadPathFromData(data, data_size);
	return path;
}

ColourGradient Paint_Paths::gradient_fill_silver(float w, float h) {
	ColourGradient gradient{ COLOR::silver_1, 0.0f, h, COLOR::silver_1, w, 0.0f, false };
	gradient.addColour(0.22, COLOR::silver_2);
	gradient.addColour(0.5, COLOR::silver_1);
	gradient.addColour(0.77, COLOR::silver_2);
	return gradient;
}

void Paint_Paths::editor_background(Graphics& g) {
	g.setGradientFill(gradient_fill_silver((float)XYWH::gui_init_w, (float)XYWH::gui_init_h));
	g.fillAll();
	Path screws_path{ load_path(PATH::editor_screws, sizeof(PATH::editor_screws)) };
	DropShadow screws_shadow{ COLOR::black, 1, Point<int>{ -1, 1 } };
	screws_shadow.drawForPath(g, screws_path);
	g.setColour(COLOR::screw);
	g.fillPath(screws_path);
	g.setColour(COLOR::screw_hole);
	g.fillPath(load_path(PATH::editor_screw_holes, sizeof(PATH::editor_screw_holes)));
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::editor_black, sizeof(PATH::editor_black)));
	g.setColour(COLOR::grey_buttons);
	g.fillPath(load_path(PATH::editor_grey_buttons, sizeof(PATH::editor_grey_buttons)));
	g.setColour(COLOR::grey_cbox_arrows);
	g.fillPath(load_path(PATH::editor_grey_cbox_arrows, sizeof(PATH::editor_grey_cbox_arrows)));
	g.setColour(COLOR::red_led_off);
	g.fillPath(load_path(PATH::editor_red_led_off, sizeof(PATH::editor_red_led_off)));
}
