#pragma once

#include <JuceHeader.h>

#include "C_COLOR.h"

struct Paint_Path
{
private: static Path create_path_from_data(const void* data, size_t data_size, float scale_factor);
public: static void editor_black(Graphics& g, float scale_factor);
public: static void editor_blue(Graphics& g, float scale_factor);
public: static void editor_grey(Graphics& g, float scale_factor);
public: static void editor_light_grey(Graphics& g, float scale_factor);
public: static void editor_orange(Graphics& g, float scale_factor);
public: static void editor_red(Graphics& g, float scale_factor);
};