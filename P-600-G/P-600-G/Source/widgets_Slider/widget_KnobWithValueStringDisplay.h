#pragma once

#include <JuceHeader.h>

#include "widget_KnobWithExposedParamAttacher.h"
#include "../gui/gui_Constants.h"
#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"

using namespace constants;


class KnobWithValueStringDisplay : public KnobWithExposedParamAttacher
{
	RendererForKnobValueStrings valueStringDisplay;

public:
	KnobWithValueStringDisplay() = delete;

	KnobWithValueStringDisplay(uint8 param, UnexposedParameters* unexposedParams) :
		KnobWithExposedParamAttacher{ param, unexposedParams },
		valueStringDisplay{ &slider, InfoForExposedParameters::get().converterFor(param) }
	{
		setSize(GUI::knobs_w, GUI::knobs_h);
		slider.setSize(GUI::knobs_w, GUI::knobs_h);
		addAndMakeVisible(valueStringDisplay);
		valueStringDisplay.setInterceptsMouseClicks(false, false);
		valueStringDisplay.setBounds(getLocalBounds());
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWithValueStringDisplay)
};

