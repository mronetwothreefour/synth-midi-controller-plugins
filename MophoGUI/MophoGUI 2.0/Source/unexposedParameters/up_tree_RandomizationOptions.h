#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



class RandomizationOptions
{
	ValueTree randomizationOptionsTree;

public:
	RandomizationOptions();

	const bool transmitMethodIsSysEx();
	void setTransmitMethodIsSysEx(bool shouldBeSysEx);

	const bool repeatChoicesAreAllowedForParam(uint8 paramIndex);
	const bool repeatChoicesAreForbiddenForParam(uint8 paramIndex);
	void setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex);

	const bool paramIsLocked(uint8 paramIndex);
	const bool paramIsUnlocked(uint8 paramIndex);
	void setParamIsLocked(uint8 paramIndex, bool shouldBeLocked);

	const bool choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex);
	void setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex);
	void checkNumberOfChoicesAllowedForParam(uint8 paramIndex);
	void clearAllowedChoicesForParam(uint8 paramIndex);
	void allowAllChoicesForParam(uint8 paramIndex);

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
	//void setCategoryIsAllowedForLFO_FreqParam(LFO_FreqCategory category, bool shouldBeAllowed, uint8 paramIndex);
	//const bool noCategoryIsAllowedForLFO_FreqParam(uint8 paramIndex);
	//const bool unsyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex);
	//void setUnsyncedFreqAreAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex);
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
