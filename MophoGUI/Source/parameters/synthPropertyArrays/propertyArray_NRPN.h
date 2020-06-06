#pragma once

#include <JuceHeader.h>

// Builds an array of NRPNs (int) for the hardware synthesizer's parameters
struct NRPNarrayFactory
{
	static void fillArray(Array<int>& nrpnArray)
	{
		/*0  */nrpnArray.add(0);
		/*1  */nrpnArray.add(1);
	}
};

