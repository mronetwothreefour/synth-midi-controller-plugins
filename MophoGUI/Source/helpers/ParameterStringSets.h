#pragma once

#include <JuceHeader.h>

// Stores immutable strings associated with parameters:
// display name, control label text, and parameter description.
// The Strings are treated as properties of a ParameterStringSet and can be
// accessed using the format stringSet.data  (e.g. osc1PitchStrings.displayName). 
// The Strings cannot be altered at runtime.
class ParameterStringSet
{
public:
	ParameterStringSet() :
		displayName_{ "" },
		ctrlLabelText_{ "" },
		description_{ "" }
	{}

	ParameterStringSet(String displayName, String ctrlLabeText, String description) :
		displayName_{ displayName },
		ctrlLabelText_{ ctrlLabeText },
		description_{ description }
	{}

	String get_description() const noexcept { return description_; }
	void set_description() {}
	__declspec(property(get = get_description, put = set_description)) String description;

	String get_displayName() const noexcept { return displayName_; }
	void set_displayName() {}
	__declspec(property(get = get_displayName, put = set_displayName)) String displayName;

	String get_ctrlLabelText() const noexcept { return ctrlLabelText_; }
	void set_ctrlLabelText() {}
	__declspec(property(get = get_ctrlLabelText, put = set_ctrlLabelText)) String ctrlLabelText;

private:
	const String displayName_;
	const String ctrlLabelText_;
	const String description_;
};

struct ParameterStrings
{
	Array<ParameterStringSet> stringsForParameter{};

	ParameterStrings()
	{
		ParameterStringSet osc1PitchStrings{ "Oscillator 1 Pitch", "PITCH", "Sets oscillator 1's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5." }; 
		stringsForParameter.add(osc1PitchStrings);
		ParameterStringSet osc1FineStrings{ "Oscillator 1 Fine Tune", "FINE", "Fine tunes oscillator 1's base pitch.\nRange: -50 cents to +50 cents.\n0 = no detuning (centered)." }; 
		stringsForParameter.add(osc1FineStrings);
		ParameterStringSet osc1ShapeStrings{ "Oscillator 1 Wave Shape", "SHAPE", "Selects oscillator 1's wave shape.\nAvailable options: Off; Sawtooth; Triangle;\nSawtooth/Triangle Mix; Pulse (Width 0 to 99).\nA Pulse with width 50 is a square wave." }; 
		stringsForParameter.add(osc1ShapeStrings);
	}
};