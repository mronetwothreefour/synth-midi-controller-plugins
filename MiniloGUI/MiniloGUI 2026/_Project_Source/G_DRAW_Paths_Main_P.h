#pragma once

#include "G_DRAW_Paths_A.h"

struct Draw_Paths_Main_P :
	public Draw_Paths_A
{
private: static ColourGradient ground_gradient(float w, float h);
public: static void backdrop(Graphics& g);
};