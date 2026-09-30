#pragma once

#include <JuceHeader.h>

namespace DRAW
{

	struct Images_A
	{
	public: static Image load_from_jpg_data(const unsigned char* data, const size_t data_size);
	};

}