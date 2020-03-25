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
