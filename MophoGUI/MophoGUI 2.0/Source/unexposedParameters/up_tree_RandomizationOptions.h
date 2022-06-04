#pragma once

#include <JuceHeader.h>



class RandomizationOptions
{
	ValueTree randomizationOptionsTree;
	const bool transmitSysEx{ true };
	const bool transmitNRPN{ false };
	const bool locked{ true };
	const bool unlocked{ false };
	const bool allowed{ true };
	const bool forbidden{ false };

public:
	RandomizationOptions();

	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);

	const bool transmitMethodIsNRPN();
	const bool transmitMethodIsSysEx();
	void setTransmitMethodIsNRPN();
	void setTransmitMethodIsSysEx();

	const bool isLocked(uint8 paramIndex);
	const bool isUnlocked(uint8 paramIndex);
	void setLocked(uint8 paramIndex);
	void setUnlocked(uint8 paramIndex);

	const bool choiceIsAllowedFor(uint8 choiceNum, uint8 paramIndex);
	const bool choiceIsForbiddenFor(uint8 choiceNum, uint8 paramIndex);
	void allowChoiceFor(uint8 choiceNum, uint8 paramIndex);
	void forbidChoiceFor(uint8 choiceNum, uint8 paramIndex);

	const bool repeatChoicesAreAllowedFor(uint8 paramIndex);
	const bool repeatChoicesAreForbiddenFor(uint8 paramIndex);
	void setRepeatChoicesAreAllowedFor(uint8 paramIndex);
	void setRepeatChoicesAreForbiddenFor(uint8 paramIndex);

	const bool onlyOneChoiceIsAllowedFor(uint8 paramIndex);
	const bool moreThanOneChoiceIsAllowedFor(uint8 paramIndex);
	const bool noChoiceIsAllowedFor(uint8 paramIndex);
	const bool atLeastOneChoiceIsAllowedFor(uint8 paramIndex);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
