#pragma once

#include <JuceHeader.h>

#include "widget_KnobWithExposedParamAttacher.h"



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

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWithWaveShapeDisplay)
};
