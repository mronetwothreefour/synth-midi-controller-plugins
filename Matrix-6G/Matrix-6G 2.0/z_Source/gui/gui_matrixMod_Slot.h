#pragma once

#include <JuceHeader.h>

#include "../widgets_ComboBox/widget_matrixMod_ComboBoxForSelectingDestinationForMod.h"
#include "../widgets_ComboBox/widget_matrixMod_ComboBoxForSelectingSourceForMod.h"
#include "../widgets_Slider/widget_matrixMod_SliderForSettingAmountForMod.h"



class UnexposedParameters;

class MatrixModSlot :
	public Component,
	public ComboBox::Listener,
	public Slider::Listener
{
	UnexposedParameters* unexposedParams;
	int modNumber;
	ComboBoxForSelectingDestinationForMatrixMod comboBox_ForSelectingDestinationForMatrixMod;
	ComboBoxForSelectingSourceForMatrixMod comboBox_ForSelectingSourceForMatrixMod;
	SliderForSettingAmountForMatrixMod slider_ForSettingAmountForMatrixMod;

public:
	MatrixModSlot() = delete;

	MatrixModSlot(UnexposedParameters* unexposedParams, int modNumber);
	void resized() override;
	void comboBoxChanged(ComboBox* comboBox) override;
	void sliderValueChanged(Slider* slider) override;
	~MatrixModSlot();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MatrixModSlot)
};
