#pragma once

#include <JuceHeader.h>

#include "widget_KnobWithExposedParamAttacher.h"
#include "../guiRenderers/guiRenderer_ForKnobWaveShapes.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"



class KnobWithWaveShapeDisplay : public KnobWithExposedParamAttacher
{
	RendererForKnobWaveShapes waveShapeDisplay;

public:
	KnobWithWaveShapeDisplay() = delete;

	KnobWithWaveShapeDisplay(uint8 param, UnexposedParameters* unexposedParams) :
		KnobWithExposedParamAttacher{ param, unexposedParams },
		waveShapeDisplay{ &slider }
	{
		auto ctrlWidth{ InfoForExposedParameters::get().controlWidthFor(param) };
		auto ctrlHeight{ InfoForExposedParameters::get().controlHeightFor(param) };
		setSize(ctrlWidth, ctrlHeight);
		slider.setSize(ctrlWidth, ctrlHeight);
		addAndMakeVisible(waveShapeDisplay);
		waveShapeDisplay.setInterceptsMouseClicks(false, false);
		waveShapeDisplay.setBounds(getLocalBounds().reduced(5));
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWithWaveShapeDisplay)
};
