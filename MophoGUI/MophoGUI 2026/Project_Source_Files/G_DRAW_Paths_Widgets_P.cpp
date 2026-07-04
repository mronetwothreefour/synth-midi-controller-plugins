#include "G_DRAW_Paths_Widgets_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_Widgets_P.h"

void Draw_Paths_Widgets_P::knob(Graphics& g, float& rotation, float& scale) {
	auto knob = load_path(PATH::knob, sizeof(PATH::knob));
	knob.applyTransform(AffineTransform::rotation(rotation, 19, 19));
	g.setColour(COLOR::black);
	g.fillPath(knob, AffineTransform::scale(scale));
}
