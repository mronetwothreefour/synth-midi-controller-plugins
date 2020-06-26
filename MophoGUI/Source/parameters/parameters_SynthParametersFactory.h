#pragma once

#include <JuceHeader.h>

struct SynthParameter
{
	StaticProperty<Identifier> ID;
	StaticProperty<String> publicName;
	StaticProperty<uint16> NRPN;
	StaticProperty<IntToStringConverter*> converter;
	StaticProperty<uint8> maxValue;
	StaticProperty<uint16> numberOfSteps{ maxValue + 1 };

	SynthParameter() :
		ID{ "null" },
		publicName{ "null" },
		NRPN{ 16383 },
		converter{ IntToNullString::get() },
		maxValue{ 0 }
	{}

	SynthParameter
	(
		Identifier ID, String publicName, uint16 NRPN, 
		IntToStringConverter* converter, uint8 maxValue
	) :
		ID{ ID },
		publicName{ publicName },
		NRPN{ NRPN },
		converter{ converter },
		maxValue{ maxValue }
	{}
};

struct SynthParameterArrayFactory
{
	static int fillArray(Array<SynthParameter>& synthParamArray)
	{
		int firstNonPublicParam{ 0 };

		/*0*/SynthParameter pitchOsc1{
			ID::pitchOsc1, "Oscillator 1 Pitch", 0,
			IntToOscPitchString::get(), 120 };
		synthParamArray.add(pitchOsc1); ++firstNonPublicParam;

		/*1*/SynthParameter fineTuneOsc1{
			ID::fineTuneOsc1, "Oscillator 1 Fine Tune", 1,
			IntToFineTuneString::get(), 100 };
		synthParamArray.add(fineTuneOsc1); ++firstNonPublicParam;

		return firstNonPublicParam;
	}
};

