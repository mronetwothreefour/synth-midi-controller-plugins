#pragma once

#include <JuceHeader.h>

#include "G_DRAW_Paths_B.h"

struct Draw_Paths_Widgets_P :
	public Draw_Paths_B
{
	static Path build_char_path(const uint8 char_num);
	static void knob(Graphics& g, float& rotation, float& scale_factor);
	static void lcd_char(Graphics& g, uint8 char_num, float& scale_factor);
};