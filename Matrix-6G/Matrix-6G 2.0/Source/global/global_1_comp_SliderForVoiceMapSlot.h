#pragma once

#include <JuceHeader.h>

#include "global_0_comp_TextEditorForVoiceMapSlider.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"
#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class TooltipsOptions;
class UnexposedParameters;

class SliderForVoiceMapSlot :
	public RotarySliderWithMouseWheelMoveOverride,
	public Value::Listener
{
	uint8 mapSlotNum;
	VoiceMapSliderType sliderType;
	TextEditorForVoiceMapSlider textEditor;
	TooltipsOptions* tooltips;
	Value globalParamAsValue;

public:
	SliderForVoiceMapSlot() = delete;

	SliderForVoiceMapSlot(uint8 mapSlotNum, VoiceMapSliderType sliderType, UnexposedParameters* unexposedParams, UndoManager* undoManager);
	void updateTooltip();
	void paint(Graphics& g) override;
	void mouseDoubleClick(const MouseEvent& event) override;
	void valueChanged() override;
	void valueChanged(Value& value) override;
	~SliderForVoiceMapSlot();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForVoiceMapSlot)
};