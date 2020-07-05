#pragma once

#include <JuceHeader.h>

#include "widget_KnobValueRenderers.h"
#include "widget_Sliders.h"
#include "widget_TooltipSetters.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class Knob : public Component
{
protected:
	RotarySliderWithMouseWheelMod slider;
	std::unique_ptr<SliderAttachment> attachment;
	uint16 paramIndex;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	Knob() = delete;

	explicit Knob(uint16 paramIndex) :
		paramIndex{ paramIndex },
		tooltipSetter{ slider, paramIndex }
	{
		auto& allParamsInfo{ ExposedParamsInfo_Singleton::get() };
		auto paramInfo{ allParamsInfo[paramIndex] };
		addAndMakeVisible(slider);
		slider.setMouseDragSensitivity(80 + paramInfo.numberOfSteps / 2);
		slider.setComponentID(ID::component_Knob.toString());
	}

	~Knob() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
		auto& allParamsInfo{ ExposedParamsInfo_Singleton::get() };
		auto paramInfo{ allParamsInfo[paramIndex] };
		attachment.reset(new SliderAttachment(*exposedParams, paramInfo.ID, slider));
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
		auto& allParamsInfo{ ExposedParamsInfo_Singleton::get() };
		auto paramInfo{ allParamsInfo[paramIndex] };
		setSize(paramInfo.ctrlWidth, paramInfo.ctrlHeight);
		slider.setSize(paramInfo.ctrlWidth, paramInfo.ctrlHeight);
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
		auto& allParamsInfo{ ExposedParamsInfo_Singleton::get() };
		auto paramInfo{ allParamsInfo[paramIndex] };
		setSize(paramInfo.ctrlWidth, paramInfo.ctrlHeight);
		slider.setSize(paramInfo.ctrlWidth, paramInfo.ctrlHeight);
		addAndMakeVisible(waveShapeRenderer);
		waveShapeRenderer.setInterceptsMouseClicks(false, false);
		waveShapeRenderer.setBounds(getLocalBounds().reduced(5));
	}

	~KnobWithWaveShapeDisplay() {
	}
};


