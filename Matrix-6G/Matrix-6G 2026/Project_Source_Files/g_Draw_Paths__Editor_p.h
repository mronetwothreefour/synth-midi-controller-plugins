#pragma once

#include <JuceHeader.h>

struct Paint_Paths
{
private: static Path load_path(const void* data, size_t data_size);
public: static void editor_background(Graphics& g);
};