#include "G_05-P_Paint_Paths.h"

#include "C_10-P_COLOR.h"
#include "C_20-P_PATH_Editor_Bkgrnd.h"

Path Paint_Paths::load_path(const void* data, size_t data_size) {
	Path path;
	path.loadPathFromData(data, data_size);
	return path;
}

void Paint_Paths::editor_background(Graphics& g) {
	g.fillAll(COLOR::background);
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::editor_black, sizeof(PATH::editor_black)));
	g.setColour(COLOR::light_blue);
	g.fillPath(load_path(PATH::editor_light_blue, sizeof(PATH::editor_light_blue)));
	g.setColour(COLOR::light_grey);
	g.fillPath(load_path(PATH::editor_light_grey, sizeof(PATH::editor_light_grey)));
	g.setColour(COLOR::blue);
	g.fillPath(load_path(PATH::editor_blue, sizeof(PATH::editor_blue)));
	g.setColour(COLOR::grey);
	g.fillPath(load_path(PATH::editor_grey, sizeof(PATH::editor_grey)));
	g.setColour(COLOR::orange);
	g.fillPath(load_path(PATH::editor_orange, sizeof(PATH::editor_orange)));
	g.setColour(COLOR::off_white);
	g.fillPath(load_path(PATH::editor_off_white, sizeof(PATH::editor_off_white)));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(load_path(PATH::editor_alt_underlines, sizeof(PATH::editor_alt_underlines)));
}
