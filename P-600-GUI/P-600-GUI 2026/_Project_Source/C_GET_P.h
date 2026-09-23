#pragma once

#include "C_GET_A.h"

struct GET :
	public GET_A
{
	static const int first_nybble_for(const std::string& id);
	static const int first_bit_for(const std::string& id);
	static const int bit_count_for(const std::string& id);
};
