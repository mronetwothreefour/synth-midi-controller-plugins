#pragma once

#include <JuceHeader.h>

#include "G_DRAW_Paths_B.h"

struct Draw_Paths_LED_P :
	public Draw_Paths_B
{
	static Path build_char_path(const uint8 char_num);
	static Path build_vert_bar(float& scale_factor);
	static void display_text(Graphics& g, const String text, const int ctrl_w, float& scale_factor,
							 Justification justification, float alpha);
	static void slider_tab(Graphics& g, float slider_position, float& scale_factor);
};