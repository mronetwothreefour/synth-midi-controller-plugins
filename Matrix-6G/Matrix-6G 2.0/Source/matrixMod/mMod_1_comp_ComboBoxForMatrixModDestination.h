#pragma once

#include <JuceHeader.h>

class MatrixModOptions;
class TooltipsOptions;

class ComboBoxForMatrixModDestination :
	public ComboBox
{
	int modNum;
	MatrixModOptions* matrixModOptions;
	Value modDestValue;
	Value shouldShowDescriptionValue;
	Value shouldShowCurrentChoiceValue;

public:
	ComboBoxForMatrixModDestination() = delete;

	ComboBoxForMatrixModDestination(int modNum, MatrixModOptions* matrixModOptions, TooltipsOptions* tooltips);
	void updateTooltip();
	void paint(Graphics& g) override;
	void valueChanged(Value& value) override;
	~ComboBoxForMatrixModDestination();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForMatrixModDestination)
};