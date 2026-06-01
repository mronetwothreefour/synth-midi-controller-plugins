#pragma once

#include <JuceHeader.h>

struct Draw_Paths_B
{
protected: static Path load_path(const void* data, size_t data_size) {
	Path path;
	path.loadPathFromData(data, data_size);
	return path;
}
};