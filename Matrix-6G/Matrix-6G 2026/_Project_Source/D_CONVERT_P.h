#pragma once

#include <JuceHeader.h>

#include "D_CONVERT_A.h"

struct CONVERT :
	public CONVERT_A
{
public: static const std::vector<uint8> to_data_vector(const String& hex_string);
public: static const String& to_hex_string(const std::vector<uint8> data_vector);
};