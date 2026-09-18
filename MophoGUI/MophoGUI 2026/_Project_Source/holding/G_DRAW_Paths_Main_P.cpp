#include "G_DRAW_Paths_Main_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_Backdrop_Main_P.h"

using namespace DRAW;

void Paths_Main::backdrop(Graphics& g) {
	g.fillAll(Colour{ COLOR::ground });
	g.setColour(Colour{ COLOR::yellow });
	g.fillPath(load_path(PATH::main_bullseye, sizeof(PATH::main_bullseye)));
	g.setColour(Colour{ COLOR::black });
	g.fillPath(load_path(PATH::main_black, sizeof(PATH::main_black)));
	g.setColour(Colour{ COLOR::yellow });
	g.fillPath(load_path(PATH::main_yellow, sizeof(PATH::main_yellow)));
	g.setColour(Colour{ COLOR::red_btn });
	g.fillPath(load_path(PATH::main_red_btn, sizeof(PATH::main_red_btn)));
	g.setColour(Colour{ COLOR::red_btn_dark_1 });
	g.fillPath(load_path(PATH::main_red_btn_dark_1, sizeof(PATH::main_red_btn_dark_1)));
	g.setColour(Colour{ COLOR::red_btn_dark_2 });
	g.fillPath(load_path(PATH::main_red_btn_dark_2, sizeof(PATH::main_red_btn_dark_2)));
	g.setColour(Colour{ COLOR::red_btn_lite_1 });
	g.fillPath(load_path(PATH::main_red_btn_lite_1, sizeof(PATH::main_red_btn_lite_1)));
	g.setColour(Colour{ COLOR::red_btn_lite_2 });
	g.fillPath(load_path(PATH::main_red_btn_lite_2, sizeof(PATH::main_red_btn_lite_2)));
	g.setColour(Colour{ COLOR::white });
	g.fillPath(load_path(PATH::main_white, sizeof(PATH::main_white)));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(load_path(PATH::main_alt_underlines, sizeof(PATH::main_alt_underlines)));
}
