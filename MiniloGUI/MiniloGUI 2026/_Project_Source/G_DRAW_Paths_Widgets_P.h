#pragma once

#include "G_DRAW_Paths_A.h"

namespace DRAW
{

	struct Paths_Widgets :
		public Paths_A
	{
	private: static void draw_switch_h_led(Graphics& g, float& scale_factor, char led_position, Colour color);
	private: static void draw_switch_h_slot(Graphics& g, float& scale_factor);
	private: static void draw_switch_h_tab(Graphics& g, float& scale_factor, char tab_position);
	private: static void draw_switch_v_led(Graphics& g, float& scale_factor, char led_position, Colour color);
	private: static void draw_switch_v_slot(Graphics& g, float& scale_factor);
	private: static void draw_switch_v_tab(Graphics& g, float& scale_factor, char tab_position);
	public: static void knob(Graphics& g, float& rotation, float& scale_factor);
	public: static void knob_lpf_freq(Graphics& g, float& rotation, float& scale_factor);
	public: static void switch_2_pole(Graphics& g, float& scale_factor, int setting);
	public: static void switch_3_pole(Graphics& g, float& scale_factor, int setting);
	public: static void switch_osc_octave(Graphics& g, float& scale_factor, int setting);
	public: static void switch_lpf_type(Graphics& g, float& scale_factor, int setting);
	public: static void switch_keyboard_octave(Graphics& g, float& scale_factor, int setting);
	};

}
