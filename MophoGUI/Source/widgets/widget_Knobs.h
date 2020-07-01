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
	SynthParameter param;

public:
	Knob() = delete;

	explicit Knob(SynthParameter param) :
		param{ param }
	{
		addAndMakeVisible(slider);
		slider.setMouseDragSensitivity(80 + param.numberOfSteps / 2);
		slider.setComponentID(ID::component_Knob.toString());
	}

	~Knob() {}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams)
	{
		attachment.reset(new SliderAttachment(*exposedParams, param.ID, slider));
	}

	void deleteAttachment() { attachment = nullptr; }

	Slider* getSlider() { return &slider; }
};



class KnobWithValueStringDisplay : public Knob
{
	ValueStringRendererForKnobs valueStringDisplay;

public:
	explicit KnobWithValueStringDisplay(SynthParameter param) :
		Knob{ param },
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
		Knob{ param },
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


