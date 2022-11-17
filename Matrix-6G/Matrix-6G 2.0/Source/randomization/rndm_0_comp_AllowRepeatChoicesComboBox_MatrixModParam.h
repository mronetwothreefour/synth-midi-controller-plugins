#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;
using MM_Type = MatrixModParamType;

class ExposedParameters;
class MatrixModOptions;
class ParamRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;

class AllowRepeatChoicesComboBox_MatrixModParam :
	public Component,
	public Value::Listener
{
	int modNum; 
	MM_Type paramType;
	MatrixModOptions* matrixModOptions;
	ParamRandomizationOptions* randomization;
	Value onlyOneChoiceIsAllowedForParamAsValue;
	ComboBox comboBox_AllowRepeatChoices;

public:
	AllowRepeatChoicesComboBox_MatrixModParam() = delete;

	AllowRepeatChoicesComboBox_MatrixModParam(int modNum, MM_Type paramType, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	void valueChanged(Value& value) override;
	~AllowRepeatChoicesComboBox_MatrixModParam();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesComboBox_MatrixModParam)
};