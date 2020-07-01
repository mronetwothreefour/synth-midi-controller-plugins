#pragma once

#include <JuceHeader.h>

#include "widget_KnobValueRenderers.h"
#include "widget_Sliders.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class Knob : public Component
{
protected:
	RotarySliderWithMouseWheelMod slider;
	std::unique_ptr<SliderAttachment> attachment;

public:
	Knob()
	{
		addAndMakeVisible(slider);
		slider.setComponentID(ID::component_Knob.toString());
	}

	~Knob() {}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams, String paramID)
	{
		attachment.reset(new SliderAttachment(*exposedParams, paramID, slider));
	}

	void deleteAttachment() { attachment = nullptr; }

	Slider* getSlider() { return &slider; }
};



class KnobWithValueStringDisplay : public Knob
{
	ValueStringRendererForKnobs valueStringDisplay;

public:
	explicit KnobWithValueStringDisplay(SynthParameter param) :
		valueStringDisplay{ &slider, param }
	{
		setSize(param.width, param.height);

		slider.setSize(param.width, param.height);

		addAndMakeVisible(valueStringDisplay);
		valueStringDisplay.setInterceptsMouseClicks(false, false);
		valueStringDisplay.setBounds(getLocalBounds());
	}

	~KnobWithValueStringDisplay() {}
};



class KnobWithWaveShapeDisplay : public Knob
{
	WaveShapeRendererForKnobs waveShapeRenderer;

public:
	explicit KnobWithWaveShapeDisplay(SynthParameter param) :
		waveShapeRenderer{ &slider }
	{
		setSize(param.width, param.height);

		slider.setSize(param.width, param.height);

		addAndMakeVisible(waveShapeRenderer);
		waveShapeRenderer.setInterceptsMouseClicks(false, false);
		waveShapeRenderer.setBounds(getLocalBounds().reduced(5));
	}

	~KnobWithWaveShapeDisplay() {}
};


