#include "parameters_ExposedParamsInfo_Singleton.h"

ExposedParamsInfo_Singleton::ExposedParamsInfo_Singleton() {
	fillExposedSynthParamArray();
}

ExposedParamsInfo_Singleton::~ExposedParamsInfo_Singleton() {
}

Array<ExposedParameterInfo>& ExposedParamsInfo_Singleton::get() {
	static ExposedParamsInfo_Singleton exposedParamsInfo;
	return exposedParamsInfo.exposedParamInfoArray;
}

void ExposedParamsInfo_Singleton::fillExposedSynthParamArray()
{
	const uint8 knob_diameter{ 40 };

	/*0*/ExposedParameterInfo osc1Pitch{
		/*ID*/"osc1Pitch", /*publicName*/"Oscillator 1 Pitch", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 0, IntToOscPitchString::get(), /*maxValue*/ 120, /*default*/ 24, 
		/*description*/ "Sets oscillator 1's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5.",
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(48, 50)
	};
	exposedParamInfoArray.add(osc1Pitch);

	/*1*/ExposedParameterInfo osc1Fine{
		/*ID*/"osc1Fine", /*publicName*/"Oscillator 1 Fine Tune", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 1, IntToFineTuneString::get(), /*maxValue*/ 100, /*default*/ 49,
		/*description*/ "Fine tunes oscillator 1's base pitch.\nRange: -50 cents to +50 cents.\n0 = no detuning (centered).",
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(93, 50)
	};
	exposedParamInfoArray.add(osc1Fine);

	/*2*/ExposedParameterInfo osc1Shape{
		/*ID*/"osc1Shape", /*publicName*/"Oscillator 1 Wave Shape", ControlType::knobWithWaveShapeDisplay,
		/*NRPN*/ 2, IntToOscWaveShape::get(), /*maxValue*/ 103, /*default*/ 1, 
		/*description*/ "Selects oscillator 1's wave shape.\nAvailable options: Off; Sawtooth; Triangle;\nSawtooth/Triangle Mix; Pulse (Width 0 to 99).\nA Pulse with width 50 is a square wave.",
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(138, 50)
	};
	exposedParamInfoArray.add(osc1Shape);

	/*3*/ExposedParameterInfo osc1Glide{
		/*ID*/"osc1Glide", /*publicName*/"Oscillator 1 Glide Rate", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 3, IntToPlainValueString::get(), /*maxValue*/ 127, /*default*/ 0, 
		/*description*/ "Sets the oscillator's glide (portamento) rate.\nRange: 0 (fastest) to 127 (slowest)",
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(183, 50)
	};
	exposedParamInfoArray.add(osc1Glide);
}



