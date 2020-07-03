#include "parameters_ExposedParameters_DB.h"

ExposedParameters_Database::ExposedParameters_Database() {
	fillExposedSynthParamArray();
}

ExposedParameters_Database::~ExposedParameters_Database() {
}

void ExposedParameters_Database::fillExposedSynthParamArray()
{
	const uint8 knob_diameter{ 40 };

	/*0*/ParameterProperties xpsdParam_PitchOsc1
	{
		"osc1Pitch", "Oscillator 1 Pitch", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 0, IntToOscPitchString::get(), /*maxValue*/ 120, /*default*/ 24, 
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(48, 50)
	};
	exposedSynthParamArray.add(xpsdParam_PitchOsc1);

	/*1*/ParameterProperties xpsdParam_FineTuneOsc1
	{
		"osc1Fine", "Oscillator 1 Fine Tune", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 1, IntToFineTuneString::get(), /*maxValue*/ 100, /*default*/ 49,
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(93, 50)
	};
	exposedSynthParamArray.add(xpsdParam_FineTuneOsc1);

	/*2*/ParameterProperties xpsdParam_ShapeOsc1
	{
		"osc1Shape", "Oscillator 1 Wave Shape", ControlType::knobWithWaveShapeDisplay,
		/*NRPN*/ 2, IntToOscWaveShape::get(), /*maxValue*/ 103, /*default*/ 1, 
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(138, 50)
	};
	exposedSynthParamArray.add(xpsdParam_ShapeOsc1);

	/*3*/ParameterProperties xpsdParam_GlideOsc1
	{
		"osc1Glide", "Oscillator 1 Glide Rate", ControlType::knobWithValueStringDisplay,
		/*NRPN*/ 3, IntToPlainValueString::get(), /*maxValue*/ 127, /*default*/ 0, 
		/*width*/ knob_diameter, /*height*/ knob_diameter, Point<int>(183, 50)
	};
	exposedSynthParamArray.add(xpsdParam_GlideOsc1);
}

ExposedParameters_Database& ExposedParameters_Database::get() {
	static ExposedParameters_Database synthParameterDatabase;
	return synthParameterDatabase;
}

int ExposedParameters_Database::size() const noexcept {
	return exposedSynthParamArray.size();
}

ParameterProperties ExposedParameters_Database::getSynthParameter(uint16 index) {
	return exposedSynthParamArray[index];
}
