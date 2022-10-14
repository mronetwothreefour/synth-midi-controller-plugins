#pragma once

#include <JuceHeader.h>

#include "splits_0_comp_TextEditorForSplitParamSlider.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using namespace Matrix_6G_Constants;
using SliderType = SplitParamSliderType;

class SplitOptions;
class TooltipsOptions;
class UnexposedParameters;

class RotarySliderForSplitParameter :
	public RotarySliderWithMouseWheelMoveOverride,
	public Value::Listener
{
	SliderType sliderType;
	SplitOptions* splitOptions;
	TooltipsOptions* tooltips;
	TextEditorForSplitParamSlider textEditor;
	Value splitParamAsValue;
	int slider_w;

public:
	RotarySliderForSplitParameter() = delete;

	RotarySliderForSplitParameter(SliderType sliderType, UnexposedParameters* unexposedParams, UndoManager* undoManager);
	void updateTooltip();
	void paint(Graphics& g) override;
	void mouseDoubleClick(const MouseEvent& event) override;
	void valueChanged() override;
	void valueChanged(Value& value) override;
	~RotarySliderForSplitParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RotarySliderForSplitParameter)
};


class LinearSliderForSplitZoneVolumeBalance :
	public LinearSliderWithMouseWheelMoveOverride,
	public Value::Listener
{
	SplitOptions* splitOptions;
	TooltipsOptions* tooltips;
	TextEditorForSplitParamSlider textEditor;
	Value splitZoneVolumeBalanceAsValue;

public:
	LinearSliderForSplitZoneVolumeBalance() = delete;

	LinearSliderForSplitZoneVolumeBalance(UnexposedParameters* unexposedParams, UndoManager* undoManager);
	void updateTooltip();
	void mouseDoubleClick(const MouseEvent& event) override;
	void valueChanged() override;
	void valueChanged(Value& value) override;
	~LinearSliderForSplitZoneVolumeBalance();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LinearSliderForSplitZoneVolumeBalance)
};
