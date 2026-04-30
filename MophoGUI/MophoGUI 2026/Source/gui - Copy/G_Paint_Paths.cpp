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
	g.setColour(COLOR::red_toggle_off);
	g.fillPath(load_path(PATH::editor_red_toggle_off, sizeof(PATH::editor_red_toggle_off), scale_factor));
}
