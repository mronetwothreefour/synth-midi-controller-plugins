#pragma once

#include <string>
#include <vector>

namespace BUILD
{

	struct Choices_For_A
	{
		static const std::vector<std::string> fine_tune();
		static const std::vector<std::string> off_on();
		static const std::vector<std::string> osc_pitch(const int choice_count);
		static const std::vector<std::string> signed_int(const int min, const int max);
		static const std::vector<std::string> unsigned_int(const int max);
	};

}
