#pragma once

#include <JuceHeader.h>

#include "mMod_0_comp_TextEditorForMatrixModAmountSlider.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

class ExposedParameters;
class MatrixModOptions;
class ParamRandomizationMethods;
class ParamRandomizationOptions;
class TooltipsOptions;

class SliderForMatrixModAmount :
	public RotarySliderWithMouseWheelMoveOverride,
	public Value::Listener
{
	int modNum;
	MatrixModOptions* matrixModOptions;
	ParamRandomizationMethods* randomize;
	ParamRandomizationOptions* randomization;
	TextEditorForMatrixModAmountSlider textEditor;
	Value modAmountAsValue;
	Value shouldShowDescriptionAsValue;
	Value shouldShowCurrentChoiceAsValue;

public:
	SliderForMatrixModAmount() = delete;

	SliderForMatrixModAmount(int modNum, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void updateTooltip();
	void paint(Graphics& g) override;
	void mouseDown(const MouseEvent& event) override;
	void mouseDoubleClick(const MouseEvent& event) override;
	void valueChanged() override;
	void valueChanged(Value& value) override;
	~SliderForMatrixModAmount();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForMatrixModAmount)
};