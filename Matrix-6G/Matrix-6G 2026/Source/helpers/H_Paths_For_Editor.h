#pragma once

#include <JuceHeader.h>

#include "C_COLOR.h"

struct Paths_For_Editor
{
private: static void editor_black(Graphics& g, float scale_factor);
private: static void editor_blue(Graphics& g, float scale_factor);
private: static void editor_grey(Graphics& g, float scale_factor);
private: static void editor_light_grey(Graphics& g, float scale_factor);
private: static void editor_off_white(Graphics& g, float scale_factor);
private: static void editor_orange(Graphics& g, float scale_factor);
private: static void editor_red(Graphics& g, float scale_factor);
public: static void paint(Graphics& g, float scale_factor);
};