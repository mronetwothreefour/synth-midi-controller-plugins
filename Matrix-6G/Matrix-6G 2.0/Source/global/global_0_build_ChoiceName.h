#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

struct GlobalParamChoiceName
{
	static String buildForEnabledDisabled(const bool isEnabled, const ChoiceNameType type) {
		if (isEnabled)
			return type == ChoiceNameType::verbose ? "On" : "ON";
		else
			return type == ChoiceNameType::verbose ? "Off" : "OFF";
	}

	static String buildForVibratoModSource(const VibratoModSource modSource, const ChoiceNameType type) {
		switch (modSource)
		{
		case VibratoModSource::off:
			return  type == ChoiceNameType::verbose ? "Off" : "OFF";
		case VibratoModSource::lever_2:
			return  type == ChoiceNameType::verbose ? "Lever 2" : "LEVER2";
		case VibratoModSource::pedal_1:
			return  type == ChoiceNameType::verbose ? "Pedal 1" : "PEDAL1";
		default:
			return "range error";
		}
	}

	static String buildForVibratoWaveType(const VibratoWaveType waveType, const ChoiceNameType nameType) {
		switch (waveType)
		{
		case VibratoWaveType::triangle:
			return  nameType == ChoiceNameType::verbose ? "Triangle" : "TRI";
		case VibratoWaveType::upSawtooth:
			return  nameType == ChoiceNameType::verbose ? "Up (Positive) Sawtooth" : "UPSAW";
		case VibratoWaveType::downSawtooth:
			return  nameType == ChoiceNameType::verbose ? "Down (Negative) Sawtooth" : "DNSAW";
		case VibratoWaveType::square:
			return  nameType == ChoiceNameType::verbose ? "Square" : "SQUAR";
		case VibratoWaveType::random:
			return  nameType == ChoiceNameType::verbose ? "Random" : "RANDM";
		case VibratoWaveType::noise:
			return  nameType == ChoiceNameType::verbose ? "Noise" : "NOISE";
		default:
			return "range error";
		}
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamChoiceName)
};