#include "D_BUILD_Choices_For_P.h"

using namespace BUILD;

const StringArray BUILD::Choices_For::app_curr_pgm_num() {
	StringArray list;
	for (int i = 0; i < 100; ++i)
		list.add(String{ i }.paddedLeft('0', 2));
	return list;
}

const StringArray Choices_For::exp_filter_key_track() {
	return { "off", "1/2", "full" };
}

const StringArray Choices_For::exp_lfo_shape() {
	return { "square", "triangle" };
}
