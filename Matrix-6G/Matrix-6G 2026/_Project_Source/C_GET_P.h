#pragma once

#include "C_GET_A.h"

struct GET :
	public GET_A
{
	static const int byte_index_for(const std::string& id);
	static const int quick_num_for(const std::string& id);
};
