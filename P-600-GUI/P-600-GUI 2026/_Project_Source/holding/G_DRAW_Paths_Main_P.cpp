#include "G_DRAW_Paths_Main_P.h"

#include "C_COLOR_P.h"
#include "C_PATH_Backdrop_Main_P.h"

using namespace DRAW;

void Paths_Main::backdrop(Graphics& g) {
	MemoryInputStream texture_stream{ BinaryData::texture_jpg, BinaryData::texture_jpgSize, false };
	JPEGImageFormat img_format;
	auto background_texture = img_format.decodeImage(texture_stream);
	g.drawImageAt(background_texture, 0, 0);
	g.setColour(COLOR::translucent_white);
	g.fillPath(load_path(PATH::main_translucent_white, sizeof(PATH::main_translucent_white)));
	g.setColour(COLOR::grey_dark);
	g.fillPath(load_path(PATH::main_grey_dark, sizeof(PATH::main_grey_dark)));
	g.setColour(COLOR::red_led_1);
	g.fillPath(load_path(PATH::main_red_led_1, sizeof(PATH::main_red_led_1)));
	g.setColour(COLOR::red_led_2);
	g.fillPath(load_path(PATH::main_red_led_2, sizeof(PATH::main_red_led_2)));
	g.setColour(COLOR::red_btn);
	g.fillPath(load_path(PATH::main_red_btn, sizeof(PATH::main_red_btn)));
	g.setColour(COLOR::grey_lite);
	g.fillPath(load_path(PATH::main_grey_lite, sizeof(PATH::main_grey_lite)));
	if (ModifierKeys::currentModifiers == ModifierKeys::altModifier)
		g.fillPath(load_path(PATH::main_alt_underlines, sizeof(PATH::main_alt_underlines)));
}
