#pragma once

#include <JuceHeader.h>

struct SynthParameter
{
	StaticProperty<Identifier> ID;
	StaticProperty<String> publicName;
	StaticProperty<uint16> NRPN;
	StaticProperty<int> converterType;
	StaticProperty<uint8> maxValue;
	StaticProperty<uint16> numberOfSteps{ maxValue + 1 };

	SynthParameter() :
		ID{ "default" },
		publicName{ "default" },
		NRPN{ 16383 },
		converterType{ IntToStringConverters::ToPlainValue },
		maxValue{ 0 }
	{}

	SynthParameter
	(
		Identifier ID, String publicName, uint16 NRPN, int converterType, uint8 maxValue
	) :
		ID{ ID },
		publicName{ publicName },
		NRPN{ NRPN },
		converterType{ converterType },
		maxValue{ maxValue }
	{}
};

struct SynthParameterArrayFactory
{
	static int fillArray(Array<SynthParameter>& synthParamArray)
	{
		int firstNonPublicParam{ 0 };

		synthParamArray.clear();

		/*0*/SynthParameter pitchOsc1{
			ID::pitchOsc1, "Oscillator 1 Pitch", 0,
			IntToStringConverters::ToOscPitch, 120 };
		synthParamArray.add(pitchOsc1); ++firstNonPublicParam;

		/*1*/SynthParameter fineTuneOsc1{
			ID::fineTuneOsc1, "Oscillator 1 Fine Tune", 1,
			IntToStringConverters::ToFineTune, 100 };
		synthParamArray.add(fineTuneOsc1); ++firstNonPublicParam;

		return firstNonPublicParam;
	}
};

