#include "G_DRAW_Paths_Main_P.h"

#include "C_COLOR_P.h"
#include "C_ID_A.h"
#include "C_GET_P.h"
#include "C_PATH_Backdrop_Main_P.h"

using namespace ID;

ColourGradient Draw_Paths_Main_P::ground_gradient(float w, float h) {
	ColourGradient gradient{ COLOR::ground_1, 0.0f, h, COLOR::ground_1, w, 0.0f, false };
	gradient.addColour(0.22, COLOR::ground_2);
	gradient.addColour(0.5, COLOR::ground_1);
	gradient.addColour(0.77, COLOR::ground_2);
	return gradient;
}

void Draw_Paths_Main_P::backdrop(Graphics& g) {
	g.setGradientFill(ground_gradient((float)Get::init_w_for(gui_editor), (float)Get::init_h_for(gui_editor)));
	g.fillAll();
	Path screws_path{ load_path(PATH::main_screws, sizeof(PATH::main_screws)) };
	DropShadow screws_shadow{ COLOR::black, 1, Point<int>{ -1, 1 } };
	screws_shadow.drawForPath(g, screws_path);
	g.setColour(COLOR::screw);
	g.fillPath(screws_path);
	g.setColour(COLOR::screw_hole);
	g.fillPath(load_path(PATH::main_screw_holes, sizeof(PATH::main_screw_holes)));
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::main_black, sizeof(PATH::main_black)));
	g.setColour(COLOR::grey_btn);
	g.fillPath(load_path(PATH::main_grey_buttons, sizeof(PATH::main_grey_buttons)));
	g.setColour(COLOR::grey_cbox_arrow);
	g.fillPath(load_path(PATH::main_grey_cbox_arrows, sizeof(PATH::main_grey_cbox_arrows)));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier) {
		g.setColour(COLOR::black);
		g.fillPath(load_path(PATH::main_alt_underlines, sizeof(PATH::main_alt_underlines)));
	}
}
