#pragma once

#include <JuceHeader.h>

#include "../widgets_LCDdisplayEditor/widget_LCDdisplayEditor.h"
#include "../widgets_Slider/widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class TooltipOptionsComponent :
	public Component,
	public Label::Listener,
	public Slider::Listener,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	TextButton button_ForClosingTooltipOptions;
	LinearSliderWithMouseWheelMod slider_DescriptionsSwitch;
	LinearSliderWithMouseWheelMod slider_CurrentSettingsSwitch;
	LCDdisplayEditor editor_DelayTime;

public:
	TooltipOptionsComponent() = delete;

	explicit TooltipOptionsComponent(UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void editorShown(Label* label, TextEditor& editor) override;
	void labelTextChanged(Label* label) override;
	void sliderValueChanged(Slider* slider) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
	void setTooltipsForAllControls();
	void hideThisComponent();

public:
	~TooltipOptionsComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipOptionsComponent)
};