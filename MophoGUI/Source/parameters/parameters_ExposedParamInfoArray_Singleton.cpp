#include "parameters_ExposedParamInfoArray_Singleton.h"

ExposedParamInfoArray_Singleton::ExposedParamInfoArray_Singleton() {
	fillExposedSynthParamArray();
}

ExposedParamInfoArray_Singleton::~ExposedParamInfoArray_Singleton() {
}

void ExposedParamInfoArray_Singleton::fillExposedSynthParamArray()
{
	const uint8 knob_diameter{ 40 };

	/*0*/ExposedParameterInfo xpsdParam_PitchOsc1
	{
		"osc1Pitch", "Oscillator 1 Pitch", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 0, IntToOscPitchString::get(), /*maxValue*/ 120, /*default*/ 24, 
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(48, 50)
	};
	exposedParamInfoArray.add(xpsdParam_PitchOsc1);

	/*1*/ExposedParameterInfo xpsdParam_FineTuneOsc1
	{
		"osc1Fine", "Oscillator 1 Fine Tune", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 1, IntToFineTuneString::get(), /*maxValue*/ 100, /*default*/ 49,
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(93, 50)
	};
	exposedParamInfoArray.add(xpsdParam_FineTuneOsc1);

	/*2*/ExposedParameterInfo xpsdParam_ShapeOsc1
	{
		"osc1Shape", "Oscillator 1 Wave Shape", ControlType::knobWithWaveShapeDisplay,
		/*NRPN*/ 2, IntToOscWaveShape::get(), /*maxValue*/ 103, /*default*/ 1, 
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(138, 50)
	};
	exposedParamInfoArray.add(xpsdParam_ShapeOsc1);

	/*3*/ExposedParameterInfo xpsdParam_GlideOsc1
	{
		"osc1Glide", "Oscillator 1 Glide Rate", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 3, IntToPlainValueString::get(), /*maxValue*/ 127, /*default*/ 0, 
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(183, 50)
	};
	exposedParamInfoArray.add(xpsdParam_GlideOsc1);
}

Array<ExposedParameterInfo>& ExposedParamInfoArray_Singleton::get() {
	static ExposedParamInfoArray_Singleton synthParameterDatabase;
	return synthParameterDatabase.exposedParamInfoArray;
}



