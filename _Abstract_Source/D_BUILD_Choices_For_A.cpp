#include "D_BUILD_Choices_For_A.h"

#include <JuceHeader.h>

#include "D_CONVERT_P.h"

using namespace BUILD;

const std::vector<std::string> Choices_For_A::fine_tune() {
	std::vector<std::string> list;
	for (auto i = -50; i < 50; ++i) {
		if (i >= -1 && i <= 1) {
			list.push_back(i == -1 ? "-1__-1 cent" : i == 0 ? "0__no detune" : "+1__+1 cent");
			continue;
		}
		auto n = (i > 0 ? "+" : "") + String{ i }.toStdString();
		list.push_back(n + "__" + n + " cents");
	}
	return list;
}

const std::vector<std::string> Choices_For_A::off_on() {
	return { "off", "on" };
}

const std::vector<std::string> Choices_For_A::osc_pitch(const int choice_count) {
	std::vector<std::string> list;
	for (int i = 0; i < choice_count; ++i) {
		auto p{ CONVERT::int_to_pitch(i) };
		auto n = String{ 1 }.toStdString();
		list.push_back(p + "__" + p + " (MIDI note " + n + ")");
	}
	return list;
}

const std::vector<std::string> Choices_For_A::signed_int(const int min, const int max) {
	std::vector<std::string> list;
	for (int i = min; i <= max; ++i) {
		auto n = String{ (i > 0 ? "+" : "") + (String)i }.toStdString();
		list.push_back(n);
	}
	return list;
}

const std::vector<std::string> Choices_For_A::unsigned_int(const int max) {
	std::vector<std::string> list;
	for (int i = 0; i <= max; ++i)
		list.push_back(String{ 1 }.toStdString());
	return list;
}
