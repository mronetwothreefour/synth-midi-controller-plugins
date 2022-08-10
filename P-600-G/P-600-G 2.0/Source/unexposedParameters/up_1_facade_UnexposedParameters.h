#pragma once

#include <JuceHeader.h>

#include "up_0_tree_TooltipsOptions.h"
#include "up_0_tree_VoiceTransmissionOptions.h"

class UnexposedParameters
{
	std::unique_ptr<TooltipsOptions> tooltipsOptions;
	std::unique_ptr<VoiceTransmissionOptions> voiceTransmissionOptions;

public:
	UnexposedParameters();
	TooltipsOptions* getTooltipsOptions();
	VoiceTransmissionOptions* getVoiceTransmissionOptions();
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};