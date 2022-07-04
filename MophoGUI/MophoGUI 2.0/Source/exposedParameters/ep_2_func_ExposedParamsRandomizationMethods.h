#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

using Step = SeqTrackStepNum;
using Track = SeqTrackNum;



class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;

class ExposedParamsRandomizationMethods :
	private Timer
{
	AudioProcessorValueTreeState* state;
	ExposedParamsRandomizationOptions* randomization;
	InfoForExposedParameters* info;

public:
	ExposedParamsRandomizationMethods() = delete;

	explicit ExposedParamsRandomizationMethods(ExposedParameters* exposedParams);
	void randomizeAllUnlockedParameters();
	void randomizeParameter(String paramID);
	void randomizeSeqTrack(Track track);

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamsRandomizationMethods)
};