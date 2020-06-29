#include "parameters_SynthParameters.h"

void ExposedSynthParametersDatabase::fillExposedSynthParamArray()
{
	/*0*/SynthParameter expParam_PitchOsc1{
		ID::expParam_PitchOsc1, "Oscillator 1 Pitch", ControlType::knobWithValueStringDisplay,
		0, IntToOscPitchString::get(), 120, 24, Point<int>(48, 50) };
	ExposedSynthParamArray.add(expParam_PitchOsc1);

	/*1*/SynthParameter expParam_FineTuneOsc1{
		ID::expParam_FineTuneOsc1, "Oscillator 1 Fine Tune", ControlType::knobWithValueStringDisplay,
		1, IntToFineTuneString::get(), 100, 49, Point<int>(93, 50) };
	ExposedSynthParamArray.add(expParam_FineTuneOsc1);
}
