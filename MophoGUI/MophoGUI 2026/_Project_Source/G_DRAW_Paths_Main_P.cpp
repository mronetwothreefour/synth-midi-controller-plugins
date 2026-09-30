#include "G_DRAW_Paths_Main_P.h"

#include "C_COLOR_P.h"
#include "C_RES_Backdrop_Main_P.h"

using namespace DRAW;

void Paths_Main::backdrop(Graphics& g) {
	g.fillAll(Colour{ COLOR::ground });
	g.setColour(Colour{ COLOR::yellow });
	g.fillPath(RES::main_bullseye);
	g.setColour(Colour{ COLOR::black });
	g.fillPath(RES::main_black);
	g.setColour(Colour{ COLOR::yellow });
	g.fillPath(RES::main_yellow);
	g.setColour(Colour{ COLOR::red_btn });
	g.fillPath(RES::main_red_btn);
	g.setColour(Colour{ COLOR::red_btn_dark_1 });
	g.fillPath(RES::main_red_btn_dark_1);
	g.setColour(Colour{ COLOR::red_btn_dark_2 });
	g.fillPath(RES::main_red_btn_dark_2);
	g.setColour(Colour{ COLOR::red_btn_lite_1 });
	g.fillPath(RES::main_red_btn_lite_1);
	g.setColour(Colour{ COLOR::red_btn_lite_2 });
	g.fillPath(RES::main_red_btn_lite_2);
	g.setColour(Colour{ COLOR::white });
	g.fillPath(RES::main_white);
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(RES::main_alt_underlines);
}
