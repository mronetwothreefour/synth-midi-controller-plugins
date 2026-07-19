#pragma once

#include <JuceHeader.h>

#include "G_DRAW_Paths_G.h"

struct Draw_Paths_Main_P :
	public Draw_Paths_G
{
private: static ColourGradient ground_gradient(float w, float h);
public: static void backdrop(Graphics& g);
};