#include "G_DRAW_Paths_Main_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_Backdrop_Main_P.h"

void Draw_Paths_Main_P::backdrop(Graphics& g) {
	g.fillAll(COLOR::ground);
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::main_black));
	g.setColour(COLOR::blue_led);
	g.fillPath(load_path(PATH::main_blue_led));
	g.setColour(COLOR::grey_line);
	g.fillPath(load_path(PATH::main_grey_line));
	g.setColour(COLOR::blue);
	g.fillPath(load_path(PATH::main_blue));
	g.setColour(COLOR::grey);
	g.fillPath(load_path(PATH::main_grey));
	g.setColour(COLOR::orange);
	g.fillPath(load_path(PATH::main_orange));
	g.setColour(COLOR::off_white);
	g.fillPath(load_path(PATH::main_off_white));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(load_path(PATH::main_alt_underlines));
}
