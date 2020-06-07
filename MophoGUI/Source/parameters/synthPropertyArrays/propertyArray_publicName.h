#pragma once

#include <JuceHeader.h>

// Takes an Array<String> and fills it with public names
// for each of the hardware synthesizer's parameters (this
// is the name of the property presented to the VST3 host)
struct PublicNameArrayFactory
{
	static void fillArray(Array<String>& publicNameArray)
	{
		/*0  */publicNameArray.add("Oscillator 1 Pitch");
		/*1  */publicNameArray.add("Oscillator 1 Fine Tune");
	}
};

