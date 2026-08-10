#pragma once

#include "D_CONVERT_A.h"

struct Convert :
	public Convert_A
{
	static String int_to_seq_step_pitch(const int i);
};