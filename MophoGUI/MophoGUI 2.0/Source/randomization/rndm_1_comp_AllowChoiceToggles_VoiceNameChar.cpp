#include "rndm_1_comp_AllowChoiceToggles_VoiceNameChar.h"

AllowChoiceToggles_VoiceNameChar::AllowChoiceToggles_VoiceNameChar(uint8 paramIndex, UnexposedParameters* unexposedParams)
{
}

String AllowChoiceToggles_VoiceNameChar::buildChoiceName(uint8 choiceNum)
{
	return String();
}

String AllowChoiceToggles_VoiceNameChar::buildTooltip()
{
	return String();
}

const bool AllowChoiceToggles_VoiceNameChar::choiceIsAllowed(uint8 choiceNum)
{
	return false;
}

void AllowChoiceToggles_VoiceNameChar::setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed)
{
}

void AllowChoiceToggles_VoiceNameChar::clearAllowedChoices()
{
}

const bool AllowChoiceToggles_VoiceNameChar::noChoiceIsAllowed()
{
	return false;
}

void AllowChoiceToggles_VoiceNameChar::restoreToggles()
{
}
