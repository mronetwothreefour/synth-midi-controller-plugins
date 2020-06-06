#pragma once

#include <JuceHeader.h>

#include "../../helpers/helper_Identifiers.h"

// Builds an array of Identifiers for the hardware synthesizer's parameters
struct IDarrayFactory
{
	static void fillArray(Array<Identifier>& idArray)
	{
		/*0  */idArray.add(ID::pitchOsc1);
		/*1  */idArray.add(ID::fineTuneOsc1);
	}
};

