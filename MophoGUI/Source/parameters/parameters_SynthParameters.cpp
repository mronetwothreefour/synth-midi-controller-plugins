#include "parameters_SynthParameters.h"

void ExposedSynthParameters_Database::fillExposedSynthParamArray()
{
	/*0*/SynthParameter xpsdParam_PitchOsc1{
		ID::xpsdParam_PitchOsc1, "Oscillator 1 Pitch", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 0, IntToOscPitchString::get(), /*maxValue*/ 120, /*default*/ 24, Point<int>(48, 50) };
	exposedSynthParamArray.add(xpsdParam_PitchOsc1);

	/*1*/SynthParameter xpsdParam_FineTuneOsc1{
		ID::xpsdParam_FineTuneOsc1, "Oscillator 1 Fine Tune", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 1, IntToFineTuneString::get(), /*maxValue*/ 100, /*default*/ 49, Point<int>(93, 50) };
	exposedSynthParamArray.add(xpsdParam_FineTuneOsc1);

	/*2*/SynthParameter xpsdParam_ShapeOsc1{
		ID::xpsdParam_ShapeOsc1, "Oscillator 1 Wave Shape", ControlType::knobWithWaveShapeDisplay,
		/*NRPN*/ 2, IntToOscWaveShape::get(), /*maxValue*/ 103, /*default*/ 1, Point<int>(138, 50) };
	exposedSynthParamArray.add(xpsdParam_ShapeOsc1);
}
