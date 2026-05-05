#include "G_Paint_Paths.h"

#include "C_COLOR.h"
#include "C_PATH_Editor_Background.h"

Path Paint_Paths::load_path(const void* data, size_t data_size) {
	Path path;
	path.loadPathFromData(data, data_size);
	return path;
}

void Paint_Paths::editor_background(Graphics& g) {
	g.fillAll(COLOR::background);
	g.setColour(COLOR::yellow);
	g.fillPath(load_path(PATH::editor_bullseye, sizeof(PATH::editor_bullseye)));
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::editor_black, sizeof(PATH::editor_black)));
	g.setColour(COLOR::red_toggle_off);
	g.fillPath(load_path(PATH::editor_red_toggle_off, sizeof(PATH::editor_red_toggle_off)));
	g.setColour(COLOR::yellow);
	g.fillPath(load_path(PATH::editor_yellow, sizeof(PATH::editor_yellow)));
	g.setColour(COLOR::red_btn);
	g.fillPath(load_path(PATH::editor_red_btn, sizeof(PATH::editor_red_btn)));
	g.setColour(COLOR::red_btn_shadow_1);
	g.fillPath(load_path(PATH::editor_red_btn_shadow_1, sizeof(PATH::editor_red_btn_shadow_1)));
	g.setColour(COLOR::red_btn_shadow_2);
	g.fillPath(load_path(PATH::editor_red_btn_shadow_2, sizeof(PATH::editor_red_btn_shadow_2)));
	g.setColour(COLOR::red_btn_hilite_1);
	g.fillPath(load_path(PATH::editor_red_btn_hilite_1, sizeof(PATH::editor_red_btn_hilite_1)));
	g.setColour(COLOR::red_btn_hilite_2);
	g.fillPath(load_path(PATH::editor_red_btn_hilite_2, sizeof(PATH::editor_red_btn_hilite_2)));
	g.setColour(COLOR::white);
	g.fillPath(load_path(PATH::editor_white, sizeof(PATH::editor_white)));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(load_path(PATH::editor_alt_underlines, sizeof(PATH::editor_alt_underlines)));
}
