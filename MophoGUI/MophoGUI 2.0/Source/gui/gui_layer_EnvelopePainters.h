#pragma once

#include <JuceHeader.h>

#include "gui_comp_EnvelopePainter.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"

using namespace MophoConstants;

class GUI_Layer_EnvelopePainters :
	public Component
{
	EnvelopePainter envelopePainter_LPF;
	EnvelopePainter envelopePainter_VCA;
	EnvelopePainter envelopePainter_Env3;

public:
	GUI_Layer_EnvelopePainters() = delete;

	GUI_Layer_EnvelopePainters(ExposedParameters* exposedParams) :
		envelopePainter_LPF{ EnvelopeType::lpf, exposedParams, },
		envelopePainter_VCA{ EnvelopeType::vca, exposedParams, },
		envelopePainter_Env3{ EnvelopeType::env_3, exposedParams, }
	{
		setInterceptsMouseClicks(false, false);

		addAndMakeVisible(envelopePainter_LPF);
		addAndMakeVisible(envelopePainter_VCA);
		addAndMakeVisible(envelopePainter_Env3);

		const int envPainter_h{ 90 };
		const int envPainter_w{ 210 };
		const int envPainter_x{ 168 };
		const int envPaintersVertSpacing{ 158 };
		const int envPainter_LPF_y{ 154 };
		const int envPainter_VCA_y{ envPainter_LPF_y + envPaintersVertSpacing };
		const int envPainter_Env3_y{ envPainter_VCA_y + envPaintersVertSpacing };
		envelopePainter_LPF.setBounds(envPainter_x, envPainter_LPF_y, envPainter_w, envPainter_h);
		envelopePainter_VCA.setBounds(envPainter_x, envPainter_VCA_y, envPainter_w, envPainter_h);
		envelopePainter_Env3.setBounds(envPainter_x, envPainter_Env3_y, envPainter_w, envPainter_h);
	}

	~GUI_Layer_EnvelopePainters() {
		envelopePainter_LPF.deleteAttachmentsBeforeKnobsToPreventMemLeaks();
		envelopePainter_VCA.deleteAttachmentsBeforeKnobsToPreventMemLeaks();
		envelopePainter_Env3.deleteAttachmentsBeforeKnobsToPreventMemLeaks();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_EnvelopePainters)
};