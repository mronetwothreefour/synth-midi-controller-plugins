#pragma once

#include "D_CONVERT_A.h"

struct CONVERT :
	public CONVERT_A
{
	static std::string int_to_seq_step_pitch(const int i);
};