#pragma once

#include <JuceHeader.h>

#include "../epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../../gui/gui_comp_JuceSlidersWithMouseMods.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class KnobAndAttachment_ForVoiceNameChar :
	public Component,
	public Slider::Listener
	// Note: listening to a slider with an exposed parameter attachment is
	// much, much faster than listening directly to an exposed parameter
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
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