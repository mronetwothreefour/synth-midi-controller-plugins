#pragma once

#include "D_CONVERT_G.h"

struct Convert_P :
	public Convert_G
{
	static String int_to_seq_step_pitch(const int i);
};