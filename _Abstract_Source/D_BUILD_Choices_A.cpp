#include "D_BUILD_Choices_A.h"

#include "D_CONVERT_P.h"

const StringArray Build_Choices_A::off_on() {
	return { "off", "on" };
}

const StringArray Build_Choices_A::osc_pitch(const int choice_count) {
	StringArray list;
	for (int i = 0; i < choice_count; ++i) {
		String p{ Convert::int_to_pitch(i) };
		list.add(p + "^" + p + " (MIDI note " + (String)i + ")");
	}
	return list;
}

const StringArray Build_Choices_A::signed_int(const int min, const int max) {
	StringArray list;
	for (int i = min; i <= max; ++i) {
		String n{ (i > 0 ? "+" : "") + (String)i };
		list.add(n);
	}
	return list;
}

const StringArray Build_Choices_A::unsigned_int(const int max) {
	StringArray list;
	for (int i = 0; i <= max; ++i) {
		String n{ (i > 0 ? "+" : "") + (String)i };
		list.add(n);
	}
	return list;
}
