#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../guiRenderers/guiRenderer_ForKnobWaveShapes.h"
#include "../widgets_Slider/widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class RandomizationOptionsComponent_OscShape :
	public Component,
	public Button::Listener,
	public Slider::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton toggle_ForAllowingOff;
	ToggleButton toggle_ForAllowingSawtooth;
	ToggleButton toggle_ForAllowingTriangle;
	ToggleButton toggle_ForAllowingSawTriMix;
	ToggleButton toggle_ForAllowingPulse;
	TextButton button_ForAllowingAllShapes;
	RotarySliderWithMouseWheelMod knob_ForMinWidth;
	RendererForKnobValueStrings valueDisplay_ForMinWidth;
	RotarySliderWithMouseWheelMod knob_ForMaxWidth;
	RendererForKnobValueStrings valueDisplay_ForMaxWidth;
	TextButton button_ForClosingComponent;
	int background_x;
	int background_y;

public:
	RandomizationOptionsComponent_OscShape() = delete;

	RandomizationOptionsComponent_OscShape(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void sliderValueChanged(Slider* slider) override;
	void hideThisComponent();
	~RandomizationOptionsComponent_OscShape();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_OscShape)
};
