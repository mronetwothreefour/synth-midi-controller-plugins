#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



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

	void addListenerToChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex);
	void removeListenerFromChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex);

	const bool transmitMethodIsNRPN();
	const bool transmitMethodIsSysEx();
	void setTransmitMethodIsNRPN();
	void setTransmitMethodIsSysEx();

	const bool paramIsLocked(uint8 paramIndex);
	const bool paramIsUnlocked(uint8 paramIndex);
	void lockParam(uint8 paramIndex);
	void unlockParam(uint8 paramIndex);

	const bool choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex);
	const bool choiceIsForbiddenForParam(uint8 choiceNum, uint8 paramIndex);
	void allowChoiceForParam(uint8 choiceNum, uint8 paramIndex);
	void forbidChoiceForParam(uint8 choiceNum, uint8 paramIndex);
	const bool onlyOneChoiceIsAllowedForParam(uint8 paramIndex);
	const bool moreThanOneChoiceIsAllowedForParam(uint8 paramIndex);
	const bool noChoiceIsAllowedForParam(uint8 paramIndex);

	const bool repeatChoicesAreAllowedForParam(uint8 paramIndex);
	const bool repeatChoicesAreForbiddenForParam(uint8 paramIndex);
	void setRepeatChoicesAreAllowedForParam(uint8 paramIndex);
	void setRepeatChoicesAreForbiddenForParam(uint8 paramIndex);

	const bool oscShapeIsAllowedForParam(OscWaveShape shape, uint8 paramIndex);
	void allowOscShapeForParam(OscWaveShape shape, uint8 paramIndex);
	void forbidOscShapeForParam(OscWaveShape shape, uint8 paramIndex);
	const bool noOscShapeIsAllowedForParam(uint8 paramIndex);
	const bool pulseWidthIsAllowedForParam(int pulseWidth, uint8 paramIndex);
	void allowPulseWidthForParam(int pulseWidth, uint8 paramIndex);
	void forbidPulseWidthForParam(int pulseWidth, uint8 paramIndex);
	const bool noPulseWidthIsAllowedForParam(uint8 paramIndex);
	const bool onlyOneOscShapeIsAllowedForParam(uint8 paramIndex);

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
