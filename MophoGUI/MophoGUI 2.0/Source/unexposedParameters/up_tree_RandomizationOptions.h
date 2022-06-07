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

	const bool transmitMethodIsNRPN();
	const bool transmitMethodIsSysEx();
	void setTransmitMethodIsNRPN();
	void setTransmitMethodIsSysEx();

	const bool repeatChoicesAreAllowedForParam(uint8 paramIndex);
	const bool repeatChoicesAreForbiddenForParam(uint8 paramIndex);
	void allowRepeatChoicesForParam(uint8 paramIndex);
	void forbidRepeatChoicesForParam(uint8 paramIndex);

	const bool paramIsLocked(uint8 paramIndex);
	const bool paramIsUnlocked(uint8 paramIndex);
	void lockParam(uint8 paramIndex);
	void unlockParam(uint8 paramIndex);

	const bool choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex);
	const bool choiceIsForbiddenForParam(uint8 choiceNum, uint8 paramIndex);
	void allowChoiceForParam(uint8 choiceNum, uint8 paramIndex);
	void forbidChoiceForParam(uint8 choiceNum, uint8 paramIndex);
	void checkNumberOfChoicesAllowedForParam(uint8 paramIndex);

	const bool oscShapeIsAllowedForParam(OscWaveShape shape, uint8 paramIndex);
	void allowOscShapeForParam(OscWaveShape shape, uint8 paramIndex);
	void forbidOscShapeForParam(OscWaveShape shape, uint8 paramIndex);
	const bool noOscShapeIsAllowedForParam(uint8 paramIndex);
	const bool pulseWidthIsAllowedForParam(int pulseWidth, uint8 paramIndex);
	void allowPulseWidthForParam(int pulseWidth, uint8 paramIndex);
	void forbidPulseWidthForParam(int pulseWidth, uint8 paramIndex);
	const bool noPulseWidthIsAllowedForParam(uint8 paramIndex);
	void checkNumberOfChoicesAllowedForOscShapeParam(uint8 paramIndex);

	//const bool categoryIsAllowedForLFO_FreqParam(LFO_FreqCategory category, uint8 paramIndex);
	//void allowCategoryForLFO_FreqParam(LFO_FreqCategory category, uint8 paramIndex);
	//void forbidCategoryForLFO_FreqParam(LFO_FreqCategory category, uint8 paramIndex);
	//const bool noCategoryIsAllowedForLFO_FreqParam(uint8 paramIndex);
	//const bool unsyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//void allowUnsyncedFreqForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//void forbidUnsyncedFreqForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//const bool noUnsyncedFreqIsAllowedForLFO_FreqParam(uint8 paramIndex);
	//const bool pitchedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//void allowPitchedFreqForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//void forbidPitchedFreqForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//const bool noPitchedFreqIsAllowedForLFO_FreqParam(uint8 paramIndex);
	//const bool syncedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//void allowSyncedFreqForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//void forbidSyncedFreqForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//const bool noSyncedFreqIsAllowedForLFO_FreqParam(uint8 paramIndex);
	//void checkNumberOfChoicesAllowedForLFO_FreqParam(uint8 paramIndex);

	const bool onlyOneChoiceIsAllowedForParam(uint8 paramIndex);
	const bool noChoiceIsAllowedForParam(uint8 paramIndex);

	void addListenerToChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex);
	void removeListenerFromChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex);
	ValueTree getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex);

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
