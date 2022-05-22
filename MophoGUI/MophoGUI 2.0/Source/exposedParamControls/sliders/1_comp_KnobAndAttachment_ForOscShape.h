#pragma once

#include <JuceHeader.h>

#include "0_slider_JuceSlidersWithMouseMods.h"
#include "../0_comp_TooltipUpdaterForExposedParamControl.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class KnobAndAttachment_ForOscShape :
	public Component,
	public AudioProcessorParameter::Listener
{
protected:
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseDownModForOscShape knob;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipsUpdater;
	int choiceNum;
	const PathStrokeType strokeType;

public:
	KnobAndAttachment_ForOscShape() = delete;

	KnobAndAttachment_ForOscShape(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void paintText(Graphics& g, String text);
	void paintSawtooth(Graphics& g, Path path);
	void paintTriangle(Graphics& g, Path path);
	void paintSawTriMix(Graphics& g, Path path);
	void paintPulse(Graphics& g, Path path, int pulseWidth);
	void attachKnobToExposedParameter();
	void parameterValueChanged(int changedParamIndex, float newValue);
	void parameterGestureChanged(int paramIndex, bool gestureIsStarting);
	void deleteAttachmentBeforeKnobToPreventMemLeak();

	~KnobAndAttachment_ForOscShape();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment_ForOscShape)
};