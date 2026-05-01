#include "G_Paint_Paths.h"

#include "C_COLOR.h"
#include "C_PATH_Editor_Background.h"

Path Paint_Paths::load_path(const void* data, size_t data_size, float scale_factor) {
	Path path;
	path.loadPathFromData(data, data_size);
	path.applyTransform(AffineTransform::scale(scale_factor, scale_factor));
	return path;
}

void Paint_Paths::editor_background(Graphics& g, float scale_factor) {
	g.fillAll(COLOR::background);
	g.setColour(COLOR::yellow);
	g.fillPath(load_path(PATH::editor_bullseye, sizeof(PATH::editor_bullseye), scale_factor));
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::editor_black, sizeof(PATH::editor_black), scale_factor));
	g.setColour(COLOR::red_toggle_off);
	g.fillPath(load_path(PATH::editor_red_toggle_off, sizeof(PATH::editor_red_toggle_off), scale_factor));
	g.setColour(COLOR::yellow);
	g.fillPath(load_path(PATH::editor_yellow, sizeof(PATH::editor_yellow), scale_factor));
	g.setColour(COLOR::red_btn);
	g.fillPath(load_path(PATH::editor_red_btn, sizeof(PATH::editor_red_btn), scale_factor));
	g.setColour(COLOR::red_btn_shadow_1);
	g.fillPath(load_path(PATH::editor_red_btn_shadow_1, sizeof(PATH::editor_red_btn_shadow_1), scale_factor));
	g.setColour(COLOR::red_btn_shadow_2);
	g.fillPath(load_path(PATH::editor_red_btn_shadow_2, sizeof(PATH::editor_red_btn_shadow_2), scale_factor));
	g.setColour(COLOR::red_btn_hilite_1);
	g.fillPath(load_path(PATH::editor_red_btn_hilite_1, sizeof(PATH::editor_red_btn_hilite_1), scale_factor));
	g.setColour(COLOR::red_btn_hilite_2);
	g.fillPath(load_path(PATH::editor_red_btn_hilite_2, sizeof(PATH::editor_red_btn_hilite_2), scale_factor));
	g.setColour(COLOR::white);
	g.fillPath(load_path(PATH::editor_white, sizeof(PATH::editor_white), scale_factor));
}
