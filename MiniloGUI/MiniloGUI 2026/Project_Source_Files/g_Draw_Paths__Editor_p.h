#pragma once

#include <JuceHeader.h>

#include "g_Draw_Paths_b.h"

struct Draw_Paths_Editor :
	public Draw_Paths_Base
{
private: static ColourGradient gradient_fill_silver(float w, float h);
public: static void background(Graphics& g);
};