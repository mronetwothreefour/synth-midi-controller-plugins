#include "params_InfoForExposedParameters_Singleton.h"

InfoForExposedParameters::InfoForExposedParameters() {
	fillAllInfoContainers();
}

InfoForExposedParameters::~InfoForExposedParameters() {
}

InfoForExposedParameters& InfoForExposedParameters::get() noexcept {
	static InfoForExposedParameters exposedParamsInfo;
	return exposedParamsInfo;
}

int InfoForExposedParameters::numberOfExposedParameters() noexcept {
	return identifiers.size();
}

Identifier InfoForExposedParameters::IDfor(uint8 paramIndex) noexcept {

	return identifiers[paramIndex];
}

String InfoForExposedParameters::exposedNameFor(uint8 paramIndex) noexcept {
	return exposedNames[paramIndex];
}

ControlType InfoForExposedParameters::controlTypeFor(uint8 paramIndex) noexcept {
	return controlTypes[paramIndex];
}

uint16 InfoForExposedParameters::NRPNfor(uint8 paramIndex) noexcept {
	return NRPNs[paramIndex];
}

IntToContextualStringConverter* InfoForExposedParameters::converterFor(uint8 paramIndex) noexcept {
	return converters[paramIndex];
}

uint8 InfoForExposedParameters::maxValueFor(uint8 paramIndex) noexcept {
	return maxValues[paramIndex];
}

uint8 InfoForExposedParameters::defaultValueFor(uint8 paramIndex) noexcept {
	return defaultValues[paramIndex];
}

uint16 InfoForExposedParameters::numberOfStepsFor(uint8 paramIndex) noexcept {
	return maxValues[paramIndex] + 1;
}

String InfoForExposedParameters::descriptionFor(uint8 paramIndex) noexcept {
	return descriptions[paramIndex];
}

Point<int> InfoForExposedParameters::ctrlCenterPointFor(uint8 paramIndex) noexcept {
	return ctrlCenterPoints[paramIndex];
}

int InfoForExposedParameters::ctrlWidthFor(uint8 paramIndex) noexcept {
	return ctrlWidths[paramIndex];
}

int InfoForExposedParameters::ctrlHeightFor(uint8 paramIndex) noexcept {
	return ctrlHeights[paramIndex];
}

uint8 InfoForExposedParameters::getIndexFor(const String& parameterID) noexcept {
	return (uint8)identifiers.indexOf(Identifier(parameterID));
}

void InfoForExposedParameters::fillAllInfoContainers() noexcept {
	const uint8 knob_diameter{ 40 };
	const uint8 toggle_diameter{ 14 };

	identifiers.add("osc1Pitch"); // 0
	exposedNames.add("Oscillator 1 Pitch");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)0); 
	converters.add(IntToOscPitchString::get()); 
	maxValues.add((uint8)120); 
	defaultValues.add((uint8)24);
	descriptions.add("Sets oscillator 1's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5.");
	auto dingle{ descriptions[0] };
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(48, 50));

	identifiers.add("osc1Fine"); // 1
	exposedNames.add("Oscillator 1 Fine Tune");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)1); 
	converters.add(IntToFineTuneString::get());
	maxValues.add((uint8)100); 
	defaultValues.add((uint8)49);
	descriptions.add("Fine tunes oscillator 1's base pitch.\nRange: -50 cents to +50 cents.\n0 = no detuning (centered).");
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(93, 50));

	identifiers.add("osc1Shape"); // 2
	exposedNames.add("Oscillator 1 Wave Shape");
	controlTypes.add(ControlType::knobWithWaveShapeDisplay);
	NRPNs.add((uint16)2); 
	converters.add(IntToOscWaveShapeString::get());
	maxValues.add((uint8)103); 
	defaultValues.add((uint8)1);
	descriptions.add("Selects oscillator 1's wave shape.\nAvailable options: Off; Sawtooth; Triangle;\nSawtooth/Triangle Mix; Pulse (Width 0 to 99).\nA Pulse with width 50 is a square wave.");
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(138, 50));

	identifiers.add("osc1Glide");
	exposedNames.add("Oscillator 1 Glide Rate");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)3); 
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127); 
	defaultValues.add((uint8)0);
	descriptions.add("Sets the oscillator's glide (portamento) rate.\nRange: 0 (instantaneous) to 127 (very slow)");
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(183, 50));

	identifiers.add("osc1KeyTrack");
	exposedNames.add("Oscillator 1 Keyboard Track On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)4); 
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1); 
	defaultValues.add((uint8)1);
	descriptions.add("Turns keyboard tracking for oscillator 1\non or off. When turned off, oscillator 1\nalways produces its base pitch, unaffected\nby the pitch of incoming MIDI notes.\n");
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(273, 50));
}



