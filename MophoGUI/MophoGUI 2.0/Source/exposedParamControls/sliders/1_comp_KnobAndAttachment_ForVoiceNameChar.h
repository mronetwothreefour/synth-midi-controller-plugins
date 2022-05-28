#pragma once

#include <JuceHeader.h>

#include "0_slider_JuceSlidersWithMouseMods.h"
#include "../0_comp_TooltipUpdaterForExposedParamControl.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class KnobAndAttachment_ForVoiceNameChar :
	public Component,
	public Slider::Listener
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseWheelMoveOverride knob;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipsUpdater;
	int charNum;

public:
	KnobAndAttachment_ForVoiceNameChar() = delete;

	KnobAndAttachment_ForVoiceNameChar(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void attachKnobToExposedParameter();
	void limitKnobRangeToBasic_ASCII_CharsThatAreVisible();
	void sliderValueChanged(Slider* slider) override;
	void deleteAttachmentBeforeKnobToPreventMemLeak();
	~KnobAndAttachment_ForVoiceNameChar();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment_ForVoiceNameChar)
};