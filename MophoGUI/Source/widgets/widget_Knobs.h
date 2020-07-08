#pragma once

#include <JuceHeader.h>

#include "widget_KnobValueRenderers.h"
#include "widget_Sliders.h"
#include "widget_TooltipSetters.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class KnobWithExposedParamAttacher : public Component
{
protected:
	RotarySliderWithMouseWheelMod slider;
	std::unique_ptr<SliderAttachment> attachment;
	uint8 param;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	KnobWithExposedParamAttacher() = delete;

	explicit KnobWithExposedParamAttacher(uint8 param) :
		param{ param },
		tooltipSetter{ slider, param }
	{
		addAndMakeVisible(slider);
		slider.setMouseDragSensitivity(80 + InfoForExposedParameters::get().numberOfStepsFor(param) / 2);
		slider.setComponentID(ID::component_Knob.toString());
	}

	~KnobWithExposedParamAttacher() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
		attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), slider));
	}

	void deleteAttachment() { 
		attachment = nullptr; 
	}
};



class KnobWithValueStringDisplay : public KnobWithExposedParamAttacher
{
	ValueStringRendererForKnobs valueStringDisplay;

public:
	explicit KnobWithValueStringDisplay(uint8 param) :
		KnobWithExposedParamAttacher{ param },
		valueStringDisplay{ &slider, param }
	{
		auto ctrlWidth{ InfoForExposedParameters::get().ctrlWidthFor(param) };
		auto ctrlHeight{ InfoForExposedParameters::get().ctrlHeightFor(param) };
		setSize(ctrlWidth, ctrlHeight);
		slider.setSize(ctrlWidth, ctrlHeight);
		addAndMakeVisible(valueStringDisplay);
		valueStringDisplay.setInterceptsMouseClicks(false, false);
		valueStringDisplay.setBounds(getLocalBounds());
	}

	~KnobWithValueStringDisplay() {
	}
};



class KnobWithWaveShapeDisplay : public KnobWithExposedParamAttacher
{
	WaveShapeRendererForKnobs waveShapeRenderer;

public:
	explicit KnobWithWaveShapeDisplay(uint8 param) :
		KnobWithExposedParamAttacher{ param },
		waveShapeRenderer{ &slider }
	{
		auto ctrlWidth{ InfoForExposedParameters::get().ctrlWidthFor(param) };
		auto ctrlHeight{ InfoForExposedParameters::get().ctrlHeightFor(param) };
		setSize(ctrlWidth, ctrlHeight);
		slider.setSize(ctrlWidth, ctrlHeight);
		addAndMakeVisible(waveShapeRenderer);
		waveShapeRenderer.setInterceptsMouseClicks(false, false);
		waveShapeRenderer.setBounds(getLocalBounds().reduced(5));
	}

	~KnobWithWaveShapeDisplay() {
	}
};


