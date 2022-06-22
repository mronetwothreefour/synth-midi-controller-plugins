#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using ExposedParameters = AudioProcessorValueTreeState;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;



class RandomizationOptions;
class UnexposedParameters;

class ParamRandomizationMethods :
	private Timer
{
	ExposedParameters* exposedParams;
	RandomizationOptions* randomization;

public:
	ParamRandomizationMethods() = delete;

	ParamRandomizationMethods(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void randomizeAllUnlockedParameters();
	void randomizeParameter(String paramID);
	void randomizeSeqTrack(Track track);

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParamRandomizationMethods)
};