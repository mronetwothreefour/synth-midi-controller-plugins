#include "G_DRAW_Paths_Main_P.h"

#include "C_COLOR_P.h"
#include "C_ID_A.h"
#include "C_PATH_Backdrop_Main_P.h"
#include "C_XYWH_P.h"

using namespace DRAW;
using namespace ID;
using namespace XYWH;

ColourGradient Paths_Main::ground_gradient(float w, float h) {
	Colour ground_1{ COLOR::ground_1 };
	Colour ground_2{ COLOR::ground_2 };
	ColourGradient gradient{ ground_1, 0.0f, h, Colour{ ground_1 }, w, 0.0f, false };
	gradient.addColour(0.22, ground_2);
	gradient.addColour(0.5, ground_1);
	gradient.addColour(0.77, ground_2);
	return gradient;
}

void Paths_Main::backdrop(Graphics& g) {
	g.setGradientFill(ground_gradient((float)editor_init_w, (float)editor_init_h));
	g.fillAll();
	Path screws_path{ load_path(PATH::main_screws, sizeof(PATH::main_screws)) };
	DropShadow screws_shadow{ Colour{ COLOR::black }, 1, Point<int>{ -1, 1 } };
	screws_shadow.drawForPath(g, screws_path);
	g.setColour(Colour{ COLOR::screw });
	g.fillPath(screws_path);
	g.setColour(Colour{ COLOR::screw_hole });
	g.fillPath(load_path(PATH::main_screw_holes, sizeof(PATH::main_screw_holes)));
	g.setColour(Colour{ COLOR::black });
	g.fillPath(load_path(PATH::main_black, sizeof(PATH::main_black)));
	g.setColour(Colour{ COLOR::grey_btn });
	g.fillPath(load_path(PATH::main_grey_buttons, sizeof(PATH::main_grey_buttons)));
	g.setColour(Colour{ COLOR::grey_cbox_arrow });
	g.fillPath(load_path(PATH::main_grey_cbox_arrows, sizeof(PATH::main_grey_cbox_arrows)));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier) {
		g.setColour(Colour{ COLOR::black });
		g.fillPath(load_path(PATH::main_alt_underlines, sizeof(PATH::main_alt_underlines)));
	}
}
