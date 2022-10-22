#pragma once

#include <JuceHeader.h>

#include "global_0_comp_TextEditorForGlobalParamSlider.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using namespace Matrix_6G_Constants;
using SliderType = GlobalParamSliderType;

class GlobalOptions;
class UnexposedParameters;

class SliderForGlobalParameter :
	public RotarySliderWithMouseWheelMoveOverride,
	public Value::Listener
{
	SliderType sliderType;
	GlobalOptions* global;
	UnexposedParameters* unexposedParams;
	TextEditorForGlobalParamSlider textEditor;
	Value globalParamAsValue;
	Value shouldShowDescriptionAsValue;
	Value shouldShowCurrentChoiceAsValue;

public:
	SliderForGlobalParameter() = delete;

	SliderForGlobalParameter(SliderType sliderType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void mouseDoubleClick(const MouseEvent& event) override;
	void valueChanged() override;
	void valueChanged(Value& value) override;
	~SliderForGlobalParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForGlobalParameter)
};