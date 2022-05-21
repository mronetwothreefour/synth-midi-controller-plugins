#pragma once

#include <JuceHeader.h>

#include "0_slider_JuceSlidersWithMouseMods.h"
#include "../component_TooltipUpdaterForExposedParamControl.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class KnobAndAttachment :
	public Component,
	public AudioProcessorParameter::Listener
{
protected:
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseWheelMoveOverride slider;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipsUpdater;

public:
	KnobAndAttachment() = delete;

	KnobAndAttachment(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void attachToExposedParameter();
	void deleteAttachmentBeforeKnobToPreventLeaking();
	void parameterValueChanged(int changedParamIndex, float newValue);
	void parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment)
};