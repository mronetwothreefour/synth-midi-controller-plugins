#pragma once

#include <JuceHeader.h>

// Builds an array of public name Strings for the hardware synthesizer's parameters
// (This is the name of the property presented to the VST3 host)
struct PublicNameArrayFactory
{
	static void fillArray(Array<String>& publicNameArray)
	{
		/*0  */publicNameArray.add("Oscillator 1 Pitch");
		/*1  */publicNameArray.add("Oscillator 1 Fine Tune");
	}
};

