#include "D_BUILD_Choices_For_P.h"

using namespace BUILD;

const StringArray Choices_For::exp_filter_key_track() {
	return { "off", "1/2", "full" };
}

const StringArray Choices_For::exp_lfo_shape() {
	return { "square", "triangle" };
}
