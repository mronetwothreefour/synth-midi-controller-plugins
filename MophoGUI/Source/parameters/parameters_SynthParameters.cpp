#include "parameters_SynthParameters.h"

void ExposedSynthParameters_Database::fillExposedSynthParamArray()
{
	const uint8 knob_diameter{ 40 };

	/*0*/SynthParameter xpsdParam_PitchOsc1
	{
		"osc1Pitch", "Oscillator 1 Pitch", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 0, IntToOscPitchString::get(), /*maxValue*/ 120, /*default*/ 24, 
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(48, 50)
	};
	exposedSynthParamArray.add(xpsdParam_PitchOsc1);

	/*1*/SynthParameter xpsdParam_FineTuneOsc1
	{
		"osc1Fine", "Oscillator 1 Fine Tune", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 1, IntToFineTuneString::get(), /*maxValue*/ 100, /*default*/ 49,
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(93, 50)
	};
	exposedSynthParamArray.add(xpsdParam_FineTuneOsc1);

	/*2*/SynthParameter xpsdParam_ShapeOsc1
	{
		"osc1Shape", "Oscillator 1 Wave Shape", ControlType::knobWithWaveShapeDisplay,
		/*NRPN*/ 2, IntToOscWaveShape::get(), /*maxValue*/ 103, /*default*/ 1, 
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(138, 50)
	};
	exposedSynthParamArray.add(xpsdParam_ShapeOsc1);

	/*3*/SynthParameter xpsdParam_GlideOsc1
	{
		"osc1Glide", "Oscillator 1 Glide Rate", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 3, IntToPlainValueString::get(), /*maxValue*/ 127, /*default*/ 0, 
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(183, 50)
	};
	exposedSynthParamArray.add(xpsdParam_GlideOsc1);
}
