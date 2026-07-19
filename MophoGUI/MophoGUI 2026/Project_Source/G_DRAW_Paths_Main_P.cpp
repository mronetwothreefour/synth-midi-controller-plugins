#include "G_DRAW_Paths_Main_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_Backdrop_Main_P.h"

void Draw_Paths_Main_P::backdrop(Graphics& g) {
	g.fillAll(COLOR::ground);
	g.setColour(COLOR::yellow);
	g.fillPath(load_path(PATH::main_bullseye));
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::main_black));
	g.setColour(COLOR::yellow);
	g.fillPath(load_path(PATH::main_yellow));
	g.setColour(COLOR::red_btn);
	g.fillPath(load_path(PATH::main_red_btn));
	g.setColour(COLOR::red_btn_dark_1);
	g.fillPath(load_path(PATH::main_red_btn_dark_1));
	g.setColour(COLOR::red_btn_dark_2);
	g.fillPath(load_path(PATH::main_red_btn_dark_2));
	g.setColour(COLOR::red_btn_lite_1);
	g.fillPath(load_path(PATH::main_red_btn_lite_1));
	g.setColour(COLOR::red_btn_lite_2);
	g.fillPath(load_path(PATH::main_red_btn_lite_2));
	g.setColour(COLOR::white);
	g.fillPath(load_path(PATH::main_white));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(load_path(PATH::main_alt_underlines));
}
