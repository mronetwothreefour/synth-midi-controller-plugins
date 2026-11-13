#pragma once

#include <JuceHeader.h>

#include "D_CONVERT_A.h"

struct CONVERT :
	public CONVERT_A
{
public: static const std::vector<uint8> to_data_vector(const String& hex_string);
public: static const String to_hex_string(const std::vector<uint8> data_vector);
public: static void signed_val_from_app_to_device_format(bool range_is_s_7_bit, uint8& value);
public: static void signed_val_from_device_to_app_format(bool range_is_s_7_bit, uint8& value);
};