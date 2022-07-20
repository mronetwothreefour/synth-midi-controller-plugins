#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;



class ExposedParamsRandomizationOptions;
class UnexposedParameters;

class SeqTrackTargetStep :
	public Component,
	public ComboBox::Listener
{
	Track track;
	ExposedParamsRandomizationOptions* randomization;
	ComboBox stepSelector;

public:
	SeqTrackTargetStep() = delete;

	SeqTrackTargetStep(Track track, ExposedParamsRandomizationOptions* randomization, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void comboBoxChanged(ComboBox* comboBox) override;
	~SeqTrackTargetStep();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SeqTrackTargetStep)
};