#pragma once

#include <JuceHeader.h>

#include "G_DRAW_Paths_B.h"

struct Draw_Paths_Sliders_P :
	public Draw_Paths_B
{
private: static void draw_switch_h_led(Graphics& g, float& scale_factor, char led_position, Colour color);
private: static void draw_switch_h_slot(Graphics& g, float& scale_factor);
private: static void draw_switch_h_tab(Graphics& g, float& scale_factor, char tab_position);
private: static void draw_switch_v_led(Graphics& g, float& scale_factor, char led_position, Colour color);
private: static void draw_switch_v_slot(Graphics& g, float& scale_factor);
private: static void draw_switch_v_tab(Graphics& g, float& scale_factor, char tab_position);
public: static void switch_2_pole(Graphics& g, float& scale_factor, int setting);
public: static void switch_3_pole(Graphics& g, float& scale_factor, int setting);
public: static void switch_osc_octave(Graphics& g, float& scale_factor, int setting);
public: static void switch_lpf_type(Graphics& g, float& scale_factor, int setting);
public: static void switch_keyboard_octave(Graphics& g, float& scale_factor, int setting);
};