#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class SplitOptions;
class TooltipsOptions;
class MatrixModOptions;

class TextEditorForMatrixModAmountSlider :
	public Component,
	public Value::Listener
{
	int modNum;
	Label textEditor;
	Value modAmountAsValue;

public:
	TextEditorForMatrixModAmountSlider() = delete;

	TextEditorForMatrixModAmountSlider(int modNum, MatrixModOptions* matrixModOptions, TooltipsOptions* tooltips);

private:
	void setEditorTextUsingStoredValue();

public:
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForMatrixModAmountSlider();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForMatrixModAmountSlider)
};