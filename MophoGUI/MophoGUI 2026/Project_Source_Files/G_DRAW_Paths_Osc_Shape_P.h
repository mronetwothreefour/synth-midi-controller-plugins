#pragma once

#include <JuceHeader.h>

#include "G_DRAW_Paths_B.h"

struct Draw_Paths_Osc_Shape_P
{
private: static const float x() { return 9.0f; };
private: static const float y() { return 12.0f; };
private: static PathStrokeType stroke();

public: static void pulse(Graphics& g, const int width, float& scale_factor);
public: static void sawtooth(Graphics& g, float& scale_factor);
public: static void triangle(Graphics& g, float& scale_factor);
public: static void saw_tri(Graphics& g, float& scale_factor);
};
