#pragma once

#include <JuceHeader.h>

#include "G_DRAW_Paths_B.h"

struct Draw_Paths_Editor_P :
	public Draw_Paths_B
{
private: static ColourGradient gradient_fill_silver(float w, float h);
public: static void background(Graphics& g);
};