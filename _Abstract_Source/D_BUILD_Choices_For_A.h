#pragma once

#include <JuceHeader.h>

namespace BUILD {

	struct Choices_For_A
	{
		static const StringArray off_on();
		static const StringArray osc_pitch(const int choice_count);
		static const StringArray signed_int(const int min, const int max);
		static const StringArray unsigned_int(const int max);
	};

}
