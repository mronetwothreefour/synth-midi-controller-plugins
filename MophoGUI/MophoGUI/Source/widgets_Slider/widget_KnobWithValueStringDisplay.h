#pragma once

#include <JuceHeader.h>

#include "widget_KnobWithExposedParamAttacher.h"
#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"



class KnobWithValueStringDisplay : public KnobWithExposedParamAttacher
{
	RendererForKnobValueStrings valueStringDisplay;

public:
	KnobWithValueStringDisplay() = delete;

	KnobWithValueStringDisplay(uint8 param, UnexposedParameters* unexposedParams) :
		KnobWithExposedParamAttacher{ param, unexposedParams },
		valueStringDisplay{ &slider, InfoForExposedParameters::get().converterFor(param) }
	{
		auto ctrlWidth{ InfoForExposedParameters::get().controlWidthFor(param) };
		auto ctrlHeight{ InfoForExposedParameters::get().controlHeightFor(param) };
		setSize(ctrlWidth, ctrlHeight);
		slider.setSize(ctrlWidth, ctrlHeight);
		addAndMakeVisible(valueStringDisplay);
		valueStringDisplay.setInterceptsMouseClicks(false, false);
		valueStringDisplay.setBounds(getLocalBounds());
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWithValueStringDisplay)
};

