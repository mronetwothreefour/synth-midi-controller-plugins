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
	const uint8 globalTranspose();
	void setGlobalTranspose(uint8 newTransposition);
	const uint8 globalFineTune();
	void setGlobalFineTune(uint8 newFineTune);
	bool hardwareOutputIsStereo();
	void setHardwareOutputStereo();
	void setHardwareOutputMono();
	const uint8 globalBalance();
	void setGlobalBalance(uint8 newBalance);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalAudioOptions)
};
