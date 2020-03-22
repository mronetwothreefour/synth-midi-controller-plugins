#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/EnvelopeWidget.h"
#include "../widgets/KnobWidgets.h"

// A set of controls targeting the voltage-controlled amplifier
// parameters: base level, envelope amount, velocity amount,
// program volume, and the VCA envelope parameters
class VCASection : public Component
{
public:
	VCASection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		knob_VCAlevel{ publicParams, privateParams, mophoLaF },
		knob_VCAenvAmt{ publicParams, privateParams, mophoLaF },
		knob_VelAmount{ publicParams, privateParams, ID::vcaVelAmount, mophoLaF },
		knob_PgmVolume{ publicParams, privateParams, mophoLaF },
		envelopeWidget{ publicParams, privateParams, "vca", mophoLaF }
	{
		addAndMakeVisible(knob_VCAlevel);
		addAndMakeVisible(knob_VCAenvAmt);
		addAndMakeVisible(knob_VelAmount);
		addAndMakeVisible(knob_PgmVolume);
		addAndMakeVisible(envelopeWidget);

		auto section_w{ 370 };
		auto section_h{ 150 };
		setSize(section_w, section_h);
	}

	~VCASection() {}

	void paint(Graphics& g) override
	{
		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 30, 15 };
		g.drawText("VCA", sectionLabelArea, Justification::centredLeft);
	}

	void resized() override
	{
		auto knob_w{ knob_VCAlevel.getWidth() };
		auto knob_h{ knob_VCAlevel.getHeight() };
		auto knobGap{ 5 };
		auto knob_col1_x{ 13 };
		auto knob_col2_x{ knob_col1_x + knob_w + knobGap };
		auto knob_col3_x{ knob_col2_x + knob_w + knobGap };
		auto knob_row1_y{ 41 };
		auto knob_row2_y{ 93 };
		knob_VCAlevel.setBounds(knob_col1_x, knob_row1_y, knob_w, knob_h);
		knob_VCAenvAmt.setBounds(knob_col2_x, knob_row1_y, knob_w, knob_h);
		knob_VelAmount.setBounds(knob_col3_x, knob_row1_y, knob_w, knob_h);
		knob_PgmVolume.setBounds(knob_col2_x, knob_row2_y, knob_w, knob_h);

		envelopeWidget.setBounds(148, 0, envelopeWidget.getWidth(), envelopeWidget.getHeight());
	}

private:
	KnobWidget_VCAlevel knob_VCAlevel;
	KnobWidget_VCAenvAmt knob_VCAenvAmt;
	KnobWidget_VelAmount knob_VelAmount;
	KnobWidget_PgmVolume knob_PgmVolume;

	EnvelopeWidget envelopeWidget;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VCASection)
};

