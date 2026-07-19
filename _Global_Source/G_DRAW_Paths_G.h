#pragma once

#include <JuceHeader.h>

struct Draw_Paths_G
{
	protected: static Path load_path(const void* data) {
		Path path;
		path.loadPathFromData(data, sizeof(data));
		return path;
	}
};