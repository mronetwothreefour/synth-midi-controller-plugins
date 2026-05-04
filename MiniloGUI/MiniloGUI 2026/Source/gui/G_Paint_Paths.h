#pragma once

#include <JuceHeader.h>

struct Paint_Paths
{
private: static Path load_path(const void* data, size_t data_size);
private: static ColourGradient gradient_fill_silver(float w, float h);
public: static void editor_background(Graphics& g);
};