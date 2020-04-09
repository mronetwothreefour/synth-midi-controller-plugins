#include "MenuWidgets.h"

StringArray MenuWidget_NotePriority::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 6; ++i)
	{
		choices.add(valueConverters.intToNotePriorityChoice(i, false));
	}
	return choices;
}

String MenuWidget_NotePriority::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToNotePriorityChoice(currentValue, true) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Selects which note is given priority when multiple\n";
		tooltip += "notes are played, and whether the envelopes are\n";
		tooltip += "re-triggered when a note is played legato (while\n";
		tooltip += "the previous note is still being held).";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_GlideMode::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 4; ++i)
	{
		choices.add(valueConverters.intToGlideMode(i));
	}
	return choices;
}

String MenuWidget_GlideMode::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToGlideMode(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Fixed Rate: The actual glide time depends on the size of the note interval.\n";
		tooltip += "Fixed Time: The glide time is constant, regardless of the interval size.\n";
		tooltip += "The Auto modes only apply glide when a note is played legato (while the\n";
		tooltip += "previous note is still being held).";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_ArpegMode::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 4; ++i)
	{
		choices.add(valueConverters.intToArpegMode(i));
	}
	return choices;
}

String MenuWidget_ArpegMode::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToArpegMode(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the order in which the arpeggiator plays notes.\n";
		tooltip += "Available options: Up, Down, Up & Down, and Assign\n";
		tooltip += "(notes play in the order in which they were struck).";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_ModDestination::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 47; ++i)
	{
		choices.add(valueConverters.intToModDestination(i));
	}
	return choices;
}

String MenuWidget_ModDestination::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToModDestination(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Selects the target parameter for modulation.";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_ModSource::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 23; ++i)
	{
		choices.add(valueConverters.intToModSource(i));
	}
	return choices;
}

String MenuWidget_ModSource::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToModSource(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Selects the modulation source.";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_MidiDestination::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 47; ++i)
	{
		choices.add(valueConverters.intToModDestination(i));
	}
	return choices;
}

String MenuWidget_MidiDestination::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToModDestination(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Selects the target parameter for\n";
		tooltip += "modulation by the MIDI controller.";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_LFOshape::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 5; ++i)
	{
		choices.add(valueConverters.intToLFOshape(i));
	}
	return choices;
}

String MenuWidget_LFOshape::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToLFOshape(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Selects the low-frequency oscillator's wave shape.\n";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_SeqTrigger::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 6; ++i)
	{
		choices.add(valueConverters.intToSeqTrigger(i));
	}
	return choices;
}

String MenuWidget_SeqTrigger::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToSeqTrigger(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Normal: New notes reset the sequencer to the first step.\n";
		tooltip += "The envelopes are re-triggered with each step.\n";
		tooltip += "Normal, No Reset: New notes do not reset the sequencer to the\n";
		tooltip += "first step. The envelopes are re-triggered with each step.\n";
		tooltip += "No Gate: New notes reset the sequencer to the first step. New\n";
		tooltip += "notes re-trigger the envelopes, but sequencer steps do not.\n";
		tooltip += "No Gate, No Reset: New notes do not reset the sequencer to the\n";
		tooltip += "first step. Sequencer steps do not re-trigger the envelopes.\n";
		tooltip += "Key Step: Each new note advances the sequencer one step.\n";
		tooltip += "Audio Input: The sequencer advances one step every time the\n";
		tooltip += "external audio input level surpasses a certain threshold.";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_ClockDiv::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 13; ++i)
	{
		choices.add(valueConverters.intToClockDiv(i, false));
	}
	return choices;
}

String MenuWidget_ClockDiv::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToClockDiv(currentValue, true) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the rate at which the sequencer and\n";
		tooltip += "arpeggiator advance, relative to the BPM.";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_PushItMode::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 3; ++i)
	{
		choices.add(valueConverters.intToPushItMode(i));
	}
	return choices;
}

String MenuWidget_PushItMode::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToPushItMode(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the operating mode for the Mopho's Push It! switch.\n";
		tooltip += "Normal: The selected note is gated on when the switch is\n";
		tooltip += "pressed and gated off when the switch is released.\n";
		tooltip += "Toggle: The selected note is gated on when the switch is\n";
		tooltip += "pressed and remains on until the switch is pressed again.\n";
		tooltip += "Audio In: The selected note is gated on for as long as the\n";
		tooltip += "external audio input level is above a certain threshold.";
	}
	return tooltip;
}

//==============================================================================

StringArray MenuWidget_KnobAssign::createChoices() const
{
	StringArray choices;
	for (auto i = 0; i != 169; ++i)
	{
		choices.add(valueConverters.intToParamName(i, false));
	}
	return choices;
}

String MenuWidget_KnobAssign::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToParamName(currentValue, true) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Selects a target parameter for the\n";
		tooltip += "Mopho's assignable hardware knob " + (String)knobNum + ".";
	}
	return tooltip;
}
