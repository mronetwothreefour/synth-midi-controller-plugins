#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TextEditorForExposedParamKnob.h"
#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class KnobAndAttachment_ForOscShape :
	public Component
{
	const uint8 paramIndex;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	RotarySliderWithMouseDownModForOscShape knob;
	std::unique_ptr<SliderAttachment> attachment;
	TextEditorForExposedParamKnob textEditor;
	TooltipUpdaterForExposedParamControl tooltipUpdater;
	int choiceNum;
	const PathStrokeType strokeType;

public:
	KnobAndAttachment_ForOscShape() = delete;

	KnobAndAttachment_ForOscShape(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	void paintText(Graphics& g, String text);
	void paintSawtooth(Graphics& g, Path path);
	void paintTriangle(Graphics& g, Path path);
	void paintSawTriMix(Graphics& g, Path path);
	void paintPulse(Graphics& g, Path path, int pulseWidth);
	void mouseDoubleClick(const MouseEvent& event) override;
	void attachKnobToExposedParameter();
	void deleteAttachmentBeforeKnobToPreventMemLeak();
	~KnobAndAttachment_ForOscShape();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment_ForOscShape)
};