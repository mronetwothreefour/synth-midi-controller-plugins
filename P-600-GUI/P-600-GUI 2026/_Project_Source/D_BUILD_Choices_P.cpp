#include "D_BUILD_Choices_P.h"

const StringArray Build_Choices::filter_key_track() {
	return { "off", "1/2", "full" };
}

const StringArray Build_Choices::lfo_shape() {
	return { "square", "triangle" };
}
