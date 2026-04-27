#pragma once

#include <JuceHeader.h>

struct Path_From_Data
{
public: static Path load(const void* data, size_t data_size, float scale_factor) {
			Path path;
			path.loadPathFromData(data, data_size);
			path.applyTransform(AffineTransform::scale(scale_factor, scale_factor));
			return path;
		}
};