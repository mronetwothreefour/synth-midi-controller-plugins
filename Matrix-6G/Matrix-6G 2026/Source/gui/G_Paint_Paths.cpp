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
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::editor_black, sizeof(PATH::editor_black), scale_factor));
	g.setColour(COLOR::light_blue);
	g.fillPath(load_path(PATH::editor_light_blue, sizeof(PATH::editor_light_blue), scale_factor));
	g.setColour(COLOR::light_grey);
	g.fillPath(load_path(PATH::editor_light_grey, sizeof(PATH::editor_light_grey), scale_factor));
	g.setColour(COLOR::blue);
	g.fillPath(load_path(PATH::editor_blue, sizeof(PATH::editor_blue), scale_factor));
	g.setColour(COLOR::grey);
	g.fillPath(load_path(PATH::editor_grey, sizeof(PATH::editor_grey), scale_factor));
	g.setColour(COLOR::orange);
	g.fillPath(load_path(PATH::editor_orange, sizeof(PATH::editor_orange), scale_factor));
	g.setColour(COLOR::red);
	g.fillPath(load_path(PATH::editor_red, sizeof(PATH::editor_red), scale_factor));
	g.setColour(COLOR::off_white);
	g.fillPath(load_path(PATH::editor_off_white, sizeof(PATH::editor_off_white), scale_factor));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(load_path(PATH::editor_alt_underlines, sizeof(PATH::editor_alt_underlines), scale_factor));
}
