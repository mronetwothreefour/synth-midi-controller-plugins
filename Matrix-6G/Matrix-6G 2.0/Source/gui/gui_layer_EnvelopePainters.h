#pragma once

#include <JuceHeader.h>

#include "gui_comp_EnvelopePainter.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"

using namespace Matrix_6G_Constants;

class GUI_Layer_EnvelopePainters :
	public Component
{
	EnvelopePainter envelope_1_Painter;
	EnvelopePainter envelope_2_Painter;
	EnvelopePainter envelope_3_Painter;

public:
	GUI_Layer_EnvelopePainters() = delete;

	GUI_Layer_EnvelopePainters(ExposedParameters* exposedParams) :
		envelope_1_Painter{ 1, exposedParams, },
		envelope_2_Painter{ 2, exposedParams, },
		envelope_3_Painter{ 3, exposedParams, }
	{
		setInterceptsMouseClicks(false, false);

		addAndMakeVisible(envelope_1_Painter);
		addAndMakeVisible(envelope_2_Painter);
		addAndMakeVisible(envelope_3_Painter);

		const int envPainter_h{ 108 };
		const int envPainter_w{ 228 };
		const int envPainter_y{ 408 };
		const int envPaintersHorizSpacing{ 410 };
		const int env_1_Painter_x{ 184 };
		const int env_2_Painter_x{env_1_Painter_x + envPaintersHorizSpacing };
		const int env_3_Painter_x{env_2_Painter_x + envPaintersHorizSpacing };
		envelope_1_Painter.setBounds(env_1_Painter_x, envPainter_y, envPainter_w, envPainter_h);
		envelope_2_Painter.setBounds(env_2_Painter_x, envPainter_y, envPainter_w, envPainter_h);
		envelope_3_Painter.setBounds(env_3_Painter_x, envPainter_y, envPainter_w, envPainter_h);
	}

	~GUI_Layer_EnvelopePainters() {
		envelope_1_Painter.deleteAttachmentsBeforeKnobsToPreventMemLeaks();
		envelope_2_Painter.deleteAttachmentsBeforeKnobsToPreventMemLeaks();
		envelope_3_Painter.deleteAttachmentsBeforeKnobsToPreventMemLeaks();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_EnvelopePainters)
};