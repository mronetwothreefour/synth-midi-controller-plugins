#pragma once

#include "D_CONVERT_G.h"

struct Convert_P :
	public Convert_G
{
	static const String int_to_mmod_amt(const int i, bool curt);
	static const String int_to_mmod_dest(const int i, bool curt);
	static const String int_to_mmod_src(const int i, bool curt);
};
