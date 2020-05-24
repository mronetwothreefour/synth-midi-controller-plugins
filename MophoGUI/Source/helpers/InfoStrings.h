#pragma once

#include <JuceHeader.h>

// Provides functionality for generating a description 
// of what a control does, used when creating tooltips
struct MophoParameterTooltipGenerator : MophoParameterValueConverter
{
	// Returns a description of what the specified
	// control does as well as its range (for knob controls)
	String getInfoString(int ctrlIndex) const noexcept
	{
		switch (ctrlIndex)
		{
		// buttons
		case MophoParameterIndex::oscSync:
			return "Turns oscillator sync on or off. When\nturned on, every time oscillator 2 resets\nit forces oscillator 1 to reset as well.";

		case MophoParameterIndex::osc1KeyTrack:
			return "Turns keyboard tracking for oscillator 1\non or off. When turned off, oscillator 1\nalways produces its base pitch, unaffected\nby the pitch of incoming MIDI notes.\n";

		case MophoParameterIndex::osc2KeyTrack:
			return "Turns keyboard tracking for oscillator 2\non or off. When turned off, oscillator 2\nalways produces its base pitch, unaffected\nby the pitch of incoming MIDI notes.\n";

		case MophoParameterIndex::env3Repeat:
			return "When repeat is on, envelope 3 loops through\nits delay, attack, decay, and sustain segments\nfor as long as the envelope is gated on.\n";

		case MophoParameterIndex::arpegOnOff:
			return "Turns the Mopho's arpeggiator on and off.\nTurning this on will turn off the sequencer.";

		case MophoParameterIndex::lpfType:
			return "Switches the low-pass filter type between 2-Pole and 4-Pole.\nWhen set to 4-pole, the filter has a steeper cutoff frequency\nslope and more pronounced resonance.";

		case MophoParameterIndex::lfo1KeySync:
			return "When on, LFO 1's cycle will re-start\neach time a new note is played.";

		case MophoParameterIndex::lfo2KeySync:
			return "When on, LFO 2's cycle will re-start\neach time a new note is played.";

		case MophoParameterIndex::lfo3KeySync:
			return "When on, LFO 3's cycle will re-start\neach time a new note is played.";

		case MophoParameterIndex::lfo4KeySync:
			return "When on, LFO 4's cycle will re-start\neach time a new note is played.";

		case MophoParameterIndex::sequencerOnOff:
			return "Turns the Mopho's sequencer on and off.\nTurning this on will turn off the arpeggiator.";

		default: return "error";
		}
		// Knobs
		//const String KnobWidget_OscPitch
		//{
		//	"Sets the oscillator's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5."
		//};
	}

	String createTooltipString(int paramIndex, int paramType, const int& currentValue, const bool& shouldShowValueTip, const bool& shouldShowInfoTip) const noexcept
	{
		String tooltip{ "" };
		if (shouldShowValueTip)
			tooltip += "Current Value: " + convertIntToValueString(paramType, currentValue, true) + "\n";
		if (shouldShowInfoTip)
		{
			tooltip += getInfoString(paramIndex);
		}
		return tooltip;
	}
};