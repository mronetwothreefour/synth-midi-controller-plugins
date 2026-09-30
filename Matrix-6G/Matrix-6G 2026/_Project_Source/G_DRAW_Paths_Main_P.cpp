#include "G_DRAW_Paths_Main_P.h"

#include "C_COLOR_P.h"
#include "C_RES_Backdrop_Main_P.h"

using namespace DRAW;

void Paths_Main::backdrop(Graphics& g) {
	g.fillAll(Colour{ COLOR::ground });
	g.setColour(Colour{ COLOR::black });
	g.fillPath(RES::main_black);
	g.setColour(Colour{ COLOR::blue_led });
	g.fillPath(RES::main_blue_led);
	g.setColour(Colour{ COLOR::grey_line });
	g.fillPath(RES::main_grey_line);
	g.setColour(Colour{ COLOR::blue });
	g.fillPath(RES::main_blue);
	g.setColour(Colour{ COLOR::grey });
	g.fillPath(RES::main_grey);
	g.setColour(Colour{ COLOR::orange });
	g.fillPath(RES::main_orange);
	g.setColour(Colour{ COLOR::off_white });
	g.fillPath(RES::main_off_white);
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(RES::main_alt_underlines);
}
