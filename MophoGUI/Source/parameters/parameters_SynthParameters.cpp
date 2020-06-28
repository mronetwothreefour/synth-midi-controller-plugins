#include "parameters_SynthParameters.h"

void ExposedSynthParametersDatabase::fillExposedSynthParamArray()
{
	/*0*/SynthParameter pitchOsc1{
		ID::pitchOsc1, "Oscillator 1 Pitch", ControlType::knobWithValueStringDisplay,
		0, IntToOscPitchString::get(), 120, 24, Point<int>(33, 35) };
	ExposedSynthParamArray.add(pitchOsc1);

	/*1*/SynthParameter fineTuneOsc1{
		ID::fineTuneOsc1, "Oscillator 1 Fine Tune", ControlType::knobWithValueStringDisplay,
		1, IntToFineTuneString::get(), 100, 49, Point<int>(78, 35) };
	ExposedSynthParamArray.add(fineTuneOsc1);
}
