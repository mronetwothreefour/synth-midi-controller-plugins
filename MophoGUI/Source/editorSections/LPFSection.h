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
		button_LPFtype{ "lpfType", publicParams, privateParams, mophoLaF },
		knob_LPFfreq{ publicParams, privateParams, mophoLaF },
		knob_LPFreso{ publicParams, privateParams, mophoLaF },
		knob_LPFkeyAmt{ publicParams, privateParams, mophoLaF },
		knob_LPFenvAmt{ publicParams, privateParams, mophoLaF },
		knob_LPFvelAmt{ publicParams, privateParams, ID::lpfVelAmount, mophoLaF },
		knob_LPFfmAmt{ publicParams, privateParams, mophoLaF },
		envelopeWidget{ publicParams, privateParams, "lpf", mophoLaF }
	{
		addAndMakeVisible(button_LPFtype);
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
		g.drawText("LPF", sectionLabelArea, Justification::left);

		// Draw LPF type label
		//==============================================================================
		Font lpfTypeLabel{ "Arial", "Black", 12.0f };
		g.setFont(lpfTypeLabel);
		Rectangle<int> lpfTypeLabelArea{ 58, 18, 40, 14 };
		g.drawText("4-POLE", lpfTypeLabelArea, Justification::centred);
	}

	void resized() override
	{
		auto button_diameter{ button_LPFtype.getWidth() };
		auto knob_w{ knob_LPFfreq.getWidth() };
		auto knob_h{ knob_LPFfreq.getHeight() };
		auto knobGap{ 5 };
		auto knob_col1_x{ 13 };
		auto knob_col2_x{ knob_col1_x + knob_w + knobGap };
		auto knob_col3_x{ knob_col2_x + knob_w + knobGap };
		auto knob_row1_y{ 41 };
		auto knob_row2_y{ 93 };
		button_LPFtype.setBounds(71, 2, button_diameter, button_diameter);
		knob_LPFfreq.setBounds(knob_col1_x, knob_row1_y, knob_w, knob_h);
		knob_LPFreso.setBounds(knob_col2_x, knob_row1_y, knob_w, knob_h);
		knob_LPFkeyAmt.setBounds(knob_col3_x, knob_row1_y, knob_w, knob_h);
		knob_LPFenvAmt.setBounds(knob_col1_x, knob_row2_y, knob_w, knob_h);
		knob_LPFvelAmt.setBounds(knob_col2_x, knob_row2_y, knob_w, knob_h);
		knob_LPFfmAmt.setBounds(knob_col3_x, knob_row2_y, knob_w, knob_h);

		envelopeWidget.setBounds(148, 0, envelopeWidget.getWidth(), envelopeWidget.getHeight());
	}

private:
	ButtonWidget_LPFtype button_LPFtype;

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