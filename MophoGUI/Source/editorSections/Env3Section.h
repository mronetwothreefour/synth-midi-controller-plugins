#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/ButtonWidgets.h"
#include "../widgets/EnvelopeWidget.h"
#include "../widgets/KnobWidgets.h"

// A set of controls targeting the voltage-controlled amplifier
// parameters: base level, envelope amount, velocity amount,
// program volume, and the VCA envelope parameters
class Env3Section : public Component
{
public:
	Env3Section
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		button_Repeat{ "repeat", publicParams, privateParams, mophoLaF },
		knob_Env3Amt{ publicParams, privateParams, mophoLaF },
		knob_VelAmount{ publicParams, privateParams, ID::env3VelAmount, mophoLaF },
		envelopeWidget{ publicParams, privateParams, "env3", mophoLaF }
	{
		addAndMakeVisible(button_Repeat);
		addAndMakeVisible(knob_Env3Amt);
		addAndMakeVisible(knob_VelAmount);
		addAndMakeVisible(envelopeWidget);

		auto section_w{ 370 };
		auto section_h{ 150 };
		setSize(section_w, section_h);
	}

	~Env3Section() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 150, 15 };
		g.drawText("ENVELOPE 3", sectionLabelArea, Justification::centredLeft);

		// Draw repeat button label
		Font repeatLabel{ "Arial", "Black", 12.0f };
		g.setFont(repeatLabel);
		Rectangle<int> repeatLabelArea{ 13, 70, 40, 14 };
		g.drawText("REPEAT", repeatLabelArea, Justification::centred);
	}

	void resized() override
	{
		auto knob_w{ knob_Env3Amt.getWidth() };
		auto knob_h{ knob_Env3Amt.getHeight() };
		auto knobGap{ 5 };
		auto knob_col1_x{ 13 };
		auto button_x{ knob_col1_x + 13 };
		auto knob_col2_x{ knob_col1_x + knob_w + knobGap };
		auto knob_col3_x{ knob_col2_x + knob_w + knobGap };
		auto knob_row1_y{ 41 };
		auto button_y{ knob_row1_y + 13 };
		//auto knob_row2_y{ 93 };
		button_Repeat.setBounds(button_x, button_y, button_Repeat.getWidth(), button_Repeat.getHeight());
		knob_Env3Amt.setBounds(knob_col2_x, knob_row1_y, knob_w, knob_h);
		knob_VelAmount.setBounds(knob_col3_x, knob_row1_y, knob_w, knob_h);

		envelopeWidget.setBounds(148, 0, envelopeWidget.getWidth(), envelopeWidget.getHeight());
	}

private:
	ButtonWidget_Repeat button_Repeat;

	KnobWidget_Env3Amt knob_Env3Amt;
	KnobWidget_VelAmount knob_VelAmount;

	EnvelopeWidget envelopeWidget;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Env3Section)
};

