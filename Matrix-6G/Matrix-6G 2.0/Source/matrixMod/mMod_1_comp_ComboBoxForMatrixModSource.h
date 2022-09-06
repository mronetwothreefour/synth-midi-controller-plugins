#pragma once

#include <JuceHeader.h>

class MatrixModOptions;
class TooltipsOptions;

class ComboBoxForMatrixModSource :
	public ComboBox
{
	int modNum;
	MatrixModOptions* matrixModOptions;
	Value modSourceValue;
	Value shouldShowDescriptionAsValue;
	Value shouldShowCurrentChoiceAsValue;

public:
	ComboBoxForMatrixModSource() = delete;

	ComboBoxForMatrixModSource(int modNum, MatrixModOptions* matrixModOptions, TooltipsOptions* tooltips);
	void updateTooltip();
	void valueChanged(Value& value) override;
	~ComboBoxForMatrixModSource();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForMatrixModSource)
};