#pragma once

#include <JuceHeader.h>



class RandomizationOptions
{
	ValueTree paramLocksTree;
	ValueTree osc1AllowedNotesTree;
	ValueTree osc1AllowedOctavesTree;
	ValueTree osc2AllowedNotesTree;
	ValueTree osc2AllowedOctavesTree;

public:
	RandomizationOptions();

private:
	void fillAllRandomizationOptionsTreesWithProperties();

public:
	const bool paramIsLocked(uint8 param);
	void setParamIsLocked(uint8 param);
	void setParamIsUnlocked(uint8 param);
	const bool pitchIsAllowedForOscillator(int noteNum, int octaveNum, int oscNum);
	const bool noteIsAllowedForOscillator(int noteNum, int oscNum);
	void setNoteIsAllowedForOscillator(int noteNum, int oscNum);
	void setNoteIsNotAllowedForOscillator(int noteNum, int oscNum);
	const bool octaveIsAllowedForOscillator(int octaveNum, int oscNum);
	void setOctaveIsAllowedForOscillator(int octaveNum, int oscNum);
	void setOctaveIsNotAllowedForOscillator(int octaveNum, int oscNum);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
