#pragma once

#include <JuceHeader.h>

#include "widget_KnobWithExposedParamAttacher.h"



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

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWithValueStringDisplay)
};

