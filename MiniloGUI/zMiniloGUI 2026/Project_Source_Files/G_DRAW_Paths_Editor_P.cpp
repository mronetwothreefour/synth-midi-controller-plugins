#include "G_DRAW_Paths_Editor_P.h"

#include "C_COLOR_P.h"
#include "C_XYWH_P.h"
#include "C_PATH_Editor_Background_P.h"

ColourGradient Draw_Paths_Editor_P::gradient_fill_silver(float w, float h) {
	ColourGradient gradient{ COLOR::silver_1, 0.0f, h, COLOR::silver_1, w, 0.0f, false };
	gradient.addColour(0.22, COLOR::silver_2);
	gradient.addColour(0.5, COLOR::silver_1);
	gradient.addColour(0.77, COLOR::silver_2);
	return gradient;
}

void Draw_Paths_Editor_P::background(Graphics& g) {
	g.setGradientFill(gradient_fill_silver((float)XYWH::gui_init_w, (float)XYWH::gui_init_h));
	g.fillAll();
	Path screws_path{ load_path(PATH::editor_screws, sizeof(PATH::editor_screws)) };
	DropShadow screws_shadow{ COLOR::black, 1, Point<int>{ -1, 1 } };
	screws_shadow.drawForPath(g, screws_path);
	g.setColour(COLOR::screw);
	g.fillPath(screws_path);
	g.setColour(COLOR::screw_hole);
	g.fillPath(load_path(PATH::editor_screw_holes, sizeof(PATH::editor_screw_holes)));
	g.setColour(COLOR::black);
	g.fillPath(load_path(PATH::editor_black, sizeof(PATH::editor_black)));
	g.setColour(COLOR::grey_buttons);
	g.fillPath(load_path(PATH::editor_grey_buttons, sizeof(PATH::editor_grey_buttons)));
	g.setColour(COLOR::grey_cbox_arrows);
	g.fillPath(load_path(PATH::editor_grey_cbox_arrows, sizeof(PATH::editor_grey_cbox_arrows)));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier) {
		g.setColour(COLOR::black);
		g.fillPath(load_path(PATH::editor_alt_underlines, sizeof(PATH::editor_alt_underlines)));
	}
}
