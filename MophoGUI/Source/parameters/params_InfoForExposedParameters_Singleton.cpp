#include "params_InfoForExposedParameters_Singleton.h"

InfoForExposedParameters_Singleton::InfoForExposedParameters_Singleton() {
	fillAllInfoContainers();
}

InfoForExposedParameters_Singleton::~InfoForExposedParameters_Singleton() {
}

InfoForExposedParameters_Singleton& InfoForExposedParameters_Singleton::get() {
	static InfoForExposedParameters_Singleton exposedParamsInfo;
	return exposedParamsInfo;
}

void InfoForExposedParameters_Singleton::fillAllInfoContainers()
{
	const uint8 knob_diameter{ 40 };

	identifierToIndexMap["osc1Pitch"] = 0;
	publicNames.add("Oscillator 1 Pitch");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)0); 
	converters.add(IntToOscPitchString::get()); 
	maxValues.add((uint8)120); 
	defaultValues.add((uint8)24);
	descriptions.add("Sets oscillator 1's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5.");
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoint.add(Point<int>(48, 50));

	identifierToIndexMap["osc1Fine"] = 1;
	publicNames.add("Oscillator 1 Fine Tune");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)1); 
	converters.add(IntToFineTuneString::get());
	maxValues.add((uint8)100); 
	defaultValues.add((uint8)49);
	descriptions.add("Fine tunes oscillator 1's base pitch.\nRange: -50 cents to +50 cents.\n0 = no detuning (centered).");
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoint.add(Point<int>(93, 50));

	identifierToIndexMap["osc1Shape"] = 2;
	publicNames.add("Oscillator 1 Wave Shape");
	controlTypes.add(ControlType::knobWithWaveShapeDisplay);
	NRPNs.add((uint16)2); 
	converters.add(IntToOscWaveShape::get());
	maxValues.add((uint8)103); 
	defaultValues.add((uint8)1);
	descriptions.add("Selects oscillator 1's wave shape.\nAvailable options: Off; Sawtooth; Triangle;\nSawtooth/Triangle Mix; Pulse (Width 0 to 99).\nA Pulse with width 50 is a square wave.");
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoint.add(Point<int>(138, 50));

	identifierToIndexMap["osc1Glide"] = 3;
	publicNames.add("Oscillator 1 Glide Rate");
	controlTypes.add(ControlType::knobWithWaveShapeDisplay);
	NRPNs.add((uint16)3); 
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127); 
	defaultValues.add((uint8)0);
	descriptions.add("Sets the oscillator's glide (portamento) rate.\nRange: 0 (fastest) to 127 (slowest)");
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoint.add(Point<int>(183, 50));
}



