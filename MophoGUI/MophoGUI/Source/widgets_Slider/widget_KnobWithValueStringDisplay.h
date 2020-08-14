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

