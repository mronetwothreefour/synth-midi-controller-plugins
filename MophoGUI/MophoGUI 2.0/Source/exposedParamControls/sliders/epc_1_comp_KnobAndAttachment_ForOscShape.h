#pragma once

#include <JuceHeader.h>

#include "../epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../../gui/gui_comp_JuceSlidersWithMouseMods.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class ExposedParameters;

class KnobAndAttachment_ForOscShape :
	public Component,
	public Slider::Listener
	// Note: listening to a slider with an exposed parameter attachment is
	// much, much faster than listening directly to an exposed parameter
{
	uint8 paramIndex;
	ExposedParameters* exposedParams;
	RotarySliderWithMouseDownModForOscShape knob;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipsUpdater;
	int choiceNum;
	const PathStrokeType strokeType;

public:
	KnobAndAttachment_ForOscShape() = delete;

	KnobAndAttachment_ForOscShape(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void paintText(Graphics& g, String text);
	void paintSawtooth(Graphics& g, Path path);
	void paintTriangle(Graphics& g, Path path);
	void paintSawTriMix(Graphics& g, Path path);
	void paintPulse(Graphics& g, Path path, int pulseWidth);
	void attachKnobToExposedParameter();
	void sliderValueChanged(Slider* slider) override;
	void deleteAttachmentBeforeKnobToPreventMemLeak();
	~KnobAndAttachment_ForOscShape();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment_ForOscShape)
};