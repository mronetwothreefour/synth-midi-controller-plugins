#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class MatrixModOptions;
class ParamRandomizationMethods;
class ParamRandomizationOptions;
class TooltipsOptions;

class ComboBoxForMatrixModDestination :
	public ComboBox
{
	int modNum;
	MatrixModOptions* matrixModOptions;
	ParamRandomizationMethods* randomize;
	ParamRandomizationOptions* randomization;
	Value modDestValue;
	Value shouldShowDescriptionAsValue;
	Value shouldShowCurrentChoiceAsValue;

public:
	ComboBoxForMatrixModDestination() = delete;

	ComboBoxForMatrixModDestination(int modNum, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void updateTooltip();
	void valueChanged(Value& value) override;
	void mouseDown(const MouseEvent& event) override;
	~ComboBoxForMatrixModDestination();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForMatrixModDestination)
};