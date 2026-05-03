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
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::editor_black, sizeof(PATH::editor_black), scale_factor));
	g.setColour(COLOR::translucent_white);
	g.fillPath(load_path(PATH::editor_translucent_white, sizeof(PATH::editor_translucent_white), scale_factor));
	g.setColour(COLOR::grey_dark);
	g.fillPath(load_path(PATH::editor_grey_dark, sizeof(PATH::editor_grey_dark), scale_factor));
	g.setColour(COLOR::grey);
	g.fillPath(load_path(PATH::editor_grey, sizeof(PATH::editor_grey), scale_factor));
	g.setColour(COLOR::red_led_1);
	g.fillPath(load_path(PATH::editor_red_led_1, sizeof(PATH::editor_red_led_1), scale_factor));
	g.setColour(COLOR::red_btn);
	g.fillPath(load_path(PATH::editor_red_btn, sizeof(PATH::editor_red_btn), scale_factor));
	g.setColour(COLOR::grey_lite);
	g.fillPath(load_path(PATH::editor_grey_lite, sizeof(PATH::editor_grey_lite), scale_factor));
}
