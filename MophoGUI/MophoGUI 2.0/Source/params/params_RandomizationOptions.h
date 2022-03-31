#pragma once

#include <JuceHeader.h>



class RandomizationOptions
{
	ValueTree paramLocksTree;
	ValueTree oscAllowedPitchesTree;
	ValueTree lfoAllowedFrequenciesTree;

public:
	RandomizationOptions();

private:
	void fillAllRandomizationOptionsTreesWithProperties();

public:
	const bool paramIsLocked(uint8 param);
	void setParamIsLocked(uint8 param);
	void setParamIsUnlocked(uint8 param);

	const bool pitchIsAllowedForOscillator(int pitchNum, int oscNum);
	const bool noteIsAllowedForOscillator(int noteNum, int oscNum);
	void setNoteIsAllowedForOscillator(int noteNum, int oscNum);
	void setNoteIsNotAllowedForOscillator(int noteNum, int oscNum);
	const bool noNoteIsAllowedForOscillator(int oscNum);
	const bool octaveIsAllowedForOscillator(int octaveNum, int oscNum);
	void setOctaveIsAllowedForOscillator(int octaveNum, int oscNum);
	void setOctaveIsNotAllowedForOscillator(int octaveNum, int oscNum);
	const bool noOctaveIsAllowedForOscillator(int oscNum);
	const bool onlyOctave10_IsAllowedForOscillator(int oscNum);

	const bool unsyncedFreqAreAllowedForLFO(int lfoNum);
	void setUnsyncedFreqAreAllowedForLFO(int lfoNum);
	void setUnsyncedFreqAreNotAllowedForLFO(int lfoNum);
	const uint8 minUnsyncedFreqForLFO(int lfoNum);
	void setMinUnsyncedFreqForLFO(uint8 newMin, int lfoNum);
	const uint8 maxUnsyncedFreqForLFO(int lfoNum);
	void setMaxUnsyncedFreqForLFO(uint8 newMax, int lfoNum);
	const bool pitchedFreqAreAllowedForLFO(int lfoNum);
	void setPitchedFreqAreAllowedForLFO(int lfoNum);
	void setPitchedFreqAreNotAllowedForLFO(int lfoNum);
	const bool pitchIsAllowedForLFO(int pitchNum, int lfoNum);
	const bool noteIsAllowedForLFO(int noteNum, int lfoNum);
	void setNoteIsAllowedForLFO(int noteNum, int lfoNum);
	void setNoteIsNotAllowedForLFO(int noteNum, int lfoNum);
	const bool noNoteIsAllowedForLFO(int lfoNum);
	const bool octaveIsAllowedForLFO(int octaveNum, int lfoNum);
	void setOctaveIsAllowedForLFO(int octaveNum, int lfoNum);
	void setOctaveIsNotAllowedForLFO(int octaveNum, int lfoNum);
	const bool noOctaveIsAllowedForLFO(int lfoNum);
	const bool onlyOctave5_IsAllowedForLFO(int lfoNum);
	const bool syncedFreqAreAllowedForLFO(int lfoNum);
	void setSyncedFreqAreAllowedForLFO(int lfoNum);
	void setSyncedFreqAreNotAllowedForLFO(int lfoNum);
	const bool syncedFreqIsAllowedForLFO(int syncedFreqNum, int lfoNum);
	void setSyncedFreqIsAllowedForLFO(int syncedFreqNum, int lfoNum);
	void setSyncedFreqIsNotAllowedForLFO(int syncedFreqNum, int lfoNum);
	const bool noSyncedFreqAreAllowedForLFO(int lfoNum);
	const bool noFreqAreAllowedForLFO(int lfoNum);

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptions)
};
