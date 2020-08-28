#pragma once

#include <JuceHeader.h>



class GlobalAudioOptions
{
	ValueTree globalAudioOptionsTree;

public:
	GlobalAudioOptions();

private:
	void fillglobalAudioOptionsTreeWithProperties();

public:
	void resetGlobalAudioOptionsToDefaults();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	uint8 globalTranspose();
	void setGlobalTranspose(uint8 newTransposition);
	uint8 globalFineTune();
	void setGlobalFineTune(uint8 newFineTune);
	bool hardwareOutputIsStereo();
	void setHardwareOutputStereo();
	void setHardwareOutputMono();
	uint8 globalBalance();
	void setGlobalBalance(uint8 newBalance);
	~GlobalAudioOptions();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalAudioOptions)
};
