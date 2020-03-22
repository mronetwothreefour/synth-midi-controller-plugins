#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/EnvelopeWidget.h"
#include "../widgets/KnobWidgets.h"

// A set of controls targeting the low-pass filter parameters:
// mode, frequency, resonance, keyboard amount, envelope amount,
// velocity amount, FM amount, and the LPF envelope parameters
class LPFSection : public Component
{
public:
	LPFSection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		knob_LPFfreq{ publicParams, privateParams, mophoLaF },
		knob_LPFreso{ publicParams, privateParams, mophoLaF },
		knob_LPFkeyAmt{ publicParams, privateParams, mophoLaF },
		knob_LPFenvAmt{ publicParams, privateParams, mophoLaF },
		knob_LPFvelAmt{ publicParams, privateParams, ID::lpfVelAmount, mophoLaF },
		knob_LPFfmAmt{ publicParams, privateParams, mophoLaF },
		envelopeWidget{ publicParams, privateParams, "lpf", mophoLaF }
	{
		addAndMakeVisible(knob_LPFfreq);
		addAndMakeVisible(knob_LPFreso);
		addAndMakeVisible(knob_LPFkeyAmt);
		addAndMakeVisible(knob_LPFenvAmt);
		addAndMakeVisible(knob_LPFvelAmt); 
		addAndMakeVisible(knob_LPFfmAmt);
		addAndMakeVisible(envelopeWidget);

		auto section_w{ 370 };
		auto section_h{ 150 };
		setSize(section_w, section_h);
	}

	~LPFSection() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 30, 15 };
		g.drawText("LPF", sectionLabelArea, Justification::centredLeft);
	}

	void resized() override
	{
		auto knob_w{ knob_LPFfreq.getWidth() };
		auto knob_h{ knob_LPFfreq.getHeight() };
		auto knobGap{ 5 };
		auto knob_col1_x{ 13 };
		auto knob_col2_x{ knob_col1_x + knob_w + knobGap };
		auto knob_col3_x{ knob_col2_x + knob_w + knobGap };
		auto knob_row1_y{ 41 };
		auto knob_row2_y{ 93 };
		knob_LPFfreq	.setBounds(knob_col1_x, knob_row1_y, knob_w, knob_h);
		knob_LPFreso	.setBounds(knob_col2_x, knob_row1_y, knob_w, knob_h);
		knob_LPFkeyAmt	.setBounds(knob_col3_x, knob_row1_y, knob_w, knob_h);
		knob_LPFenvAmt	.setBounds(knob_col1_x, knob_row2_y, knob_w, knob_h);
		knob_LPFvelAmt	.setBounds(knob_col2_x, knob_row2_y, knob_w, knob_h);
		knob_LPFfmAmt	.setBounds(knob_col3_x, knob_row2_y, knob_w, knob_h);

		envelopeWidget.setBounds(148, 0, envelopeWidget.getWidth(), envelopeWidget.getHeight());
	}

private:
    KnobWidget_LPFfreq     knob_LPFfreq;
    KnobWidget_LPFreso     knob_LPFreso;
    KnobWidget_LPFkeyAmt   knob_LPFkeyAmt;
    KnobWidget_LPFenvAmt   knob_LPFenvAmt;
    KnobWidget_VelAmount   knob_LPFvelAmt;
    KnobWidget_LPFfmAmt    knob_LPFfmAmt;

    EnvelopeWidget envelopeWidget;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LPFSection)
};