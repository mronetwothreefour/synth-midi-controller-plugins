#pragma once

#include <JuceHeader.h>

// A collection of Strings containing descriptions of what 
// various controls do, used to generate tooltips
namespace InfoStrings
{
	//==============================================================================
	// Knobs
	const String KnobWidget_OscPitch
	{
		"Sets the oscillator's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5."
	};
};