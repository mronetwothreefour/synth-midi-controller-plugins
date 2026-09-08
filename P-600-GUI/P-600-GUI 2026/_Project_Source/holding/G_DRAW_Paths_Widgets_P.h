#pragma once

#include "G_DRAW_Paths_A.h"

namespace DRAW
{

	struct Paths_Widgets :
		public Paths_A
	{
	private: static void draw_switch_tab(Graphics& g, float& scale_factor, char tab_position);
	public: static void knob(Graphics& g, float& rotation, float& scale_factor);
	public: static void switch_2_pole(Graphics& g, float& scale_factor, int setting);
	public: static void switch_3_pole(Graphics& g, float& scale_factor, int setting);
	};

}
