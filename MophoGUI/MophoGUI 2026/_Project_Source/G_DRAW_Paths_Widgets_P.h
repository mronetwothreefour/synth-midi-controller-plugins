#pragma once

#include "G_DRAW_Paths_A.h"

namespace DRAW
{

	struct Paths_Widgets :
		public Paths_A
	{
	public: static Path build_char_path(const uint8 char_num);
	public: static void knob(Graphics& g, float& rotation, float& scale_factor);
	public: static void lcd_char(Graphics& g, uint8 char_num, float& scale_factor);
	public: static void wave_pulse(Graphics& g, const int width, float& scale_factor);
	public: static void wave_saw(Graphics& g, float& scale_factor);
	public: static void wave_saw_tri(Graphics& g, float& scale_factor);
	private: static PathStrokeType wave_stroke();
	public: static void wave_tri(Graphics& g, float& scale_factor);
	private: static const float wave_x() { return 9.0f; };
	private: static const float wave_y() { return 12.0f; };
	};

}
