#pragma once

#include <JuceHeader.h>

#include "G_DRAW_Paths_B.h"

struct Draw_Paths_Widgets_P :
	public Draw_Paths_B
{
public: static void knob(Graphics& g, float& rotation, float& scale_factor);
};