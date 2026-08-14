#pragma once

#include "G_DRAW_Paths_A.h"

namespace DRAW
{

	struct Paths_Main :
		public Paths_A
	{
	private: static ColourGradient ground_gradient(float w, float h);
	public: static void backdrop(Graphics& g);
	};

}
