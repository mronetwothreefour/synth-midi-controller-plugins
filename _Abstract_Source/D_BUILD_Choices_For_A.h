#pragma once

#include <JuceHeader.h>

namespace BUILD
{

	struct Choices_For_A
	{
		protected: static void add_duplicate_strings_to_list(const String& s, const int dupe_count,
															 StringArray& target_list);

		public: static const StringArray fine_tune();
		public: static const StringArray off_on();
		public: static const StringArray osc_pitch(const int choice_count);
		public: static const StringArray signed_int(const int min, const int max);
		public: static const StringArray unsigned_int(const int max);
	};

}
