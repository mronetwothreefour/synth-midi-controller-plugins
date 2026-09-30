#include "G_DRAW_Paths_Main_P.h"

#include "C_COLOR_P.h"
#include "C_RES_Backdrop_Main_P.h"

using namespace DRAW;

void Paths_Main::backdrop(Graphics& g) {
	g.drawImageAt(RES::main_texture, 0, 0);
	g.setColour(Colour{ COLOR::translucent_white });
	g.fillPath(RES::main_translucent_white);
	g.setColour(Colour{ COLOR::grey_dark });
	g.fillPath(RES::main_grey_dark);
	g.setColour(Colour{ COLOR::red_led_1 });
	g.fillPath(RES::main_red_led_1);
	g.setColour(Colour{ COLOR::red_led_2 });
	g.fillPath(RES::main_red_led_2);
	g.setColour(Colour{ COLOR::red_btn });
	g.fillPath(RES::main_red_btn);
	g.setColour(Colour{ COLOR::grey_lite });
	g.fillPath(RES::main_grey_lite);
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(RES::main_alt_underlines);
}
