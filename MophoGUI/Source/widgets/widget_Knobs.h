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
	uint16 paramIndex;

public:
	Knob() = delete;

	explicit Knob(uint16 paramIndex) :
		paramIndex{ paramIndex }
	{
		auto& exposedParamsDB{ ExposedParameters_Database::get() };
		auto param{ exposedParamsDB.getSynthParameter(paramIndex) };
		addAndMakeVisible(slider);
		slider.setMouseDragSensitivity(80 + param.numberOfSteps / 2);
		slider.setComponentID(ID::component_Knob.toString());
	}

	~Knob() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
		auto& exposedParamsDB{ ExposedParameters_Database::get() };
		auto param{ exposedParamsDB.getSynthParameter(paramIndex) };
		attachment.reset(new SliderAttachment(*exposedParams, param.ID, slider));
	}

	void deleteAttachment() { 
		attachment = nullptr; 
	}

	Slider* getSlider() { 
		return &slider; 
	}
};



class KnobWithValueStringDisplay : public Knob
{
	ValueStringRendererForKnobs valueStringDisplay;

public:
	explicit KnobWithValueStringDisplay(uint16 paramIndex) :
		Knob{ paramIndex },
		valueStringDisplay{ &slider, paramIndex }
	{
		auto& exposedParamsDB{ ExposedParameters_Database::get() };
		auto param{ exposedParamsDB.getSynthParameter(paramIndex) };
		setSize(param.width, param.height);
		slider.setSize(param.width, param.height);
		addAndMakeVisible(valueStringDisplay);
		valueStringDisplay.setInterceptsMouseClicks(false, false);
		valueStringDisplay.setBounds(getLocalBounds());
	}

	~KnobWithValueStringDisplay() {
	}
};



class KnobWithWaveShapeDisplay : public Knob
{
	WaveShapeRendererForKnobs waveShapeRenderer;

public:
	explicit KnobWithWaveShapeDisplay(uint16 paramIndex) :
		Knob{ paramIndex },
		waveShapeRenderer{ &slider }
	{
		auto& exposedParamsDB{ ExposedParameters_Database::get() };
		auto param{ exposedParamsDB.getSynthParameter(paramIndex) };
		setSize(param.width, param.height);
		slider.setSize(param.width, param.height);
		addAndMakeVisible(waveShapeRenderer);
		waveShapeRenderer.setInterceptsMouseClicks(false, false);
		waveShapeRenderer.setBounds(getLocalBounds().reduced(5));
	}

	~KnobWithWaveShapeDisplay() {
	}
};


