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
		tooltip += "re-triggered when a new note is played before\n";
		tooltip += "the previous note has been released.";
	}
	return tooltip;
}
