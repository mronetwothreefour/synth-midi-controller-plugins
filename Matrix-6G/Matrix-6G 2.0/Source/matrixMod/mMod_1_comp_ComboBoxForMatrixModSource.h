#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class MatrixModOptions;
class ParamRandomizationMethods;
class ParamRandomizationOptions;
class TooltipsOptions;

class ComboBoxForMatrixModSource :
	public ComboBox
{
	int modNum;
	MatrixModOptions* matrixModOptions;
	ParamRandomizationMethods* randomize;
	ParamRandomizationOptions* randomization;
	Value modSourceValue;
	Value shouldShowDescriptionAsValue;
	Value shouldShowCurrentChoiceAsValue;

public:
	ComboBoxForMatrixModSource() = delete;

	ComboBoxForMatrixModSource(int modNum, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void updateTooltip();
	void valueChanged(Value& value) override;
	void mouseDown(const MouseEvent& event) override;
	~ComboBoxForMatrixModSource();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForMatrixModSource)
};