#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/ValueConverters.h"
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
		PrivateParameters* privateParams
	) :
		knob_VCAlevel{ "LEVEL", publicParams, privateParams, ID::vcaLevel, MophoParameterIndex::vcaLevel, MophoParameterType::plainInteger, MophoKnobSensitivity::zeroTo127 },
		knob_VCAenvAmt{ "ENV", publicParams, privateParams, ID::vcaEnvAmount, MophoParameterIndex::vcaEnvAmount, MophoParameterType::plainInteger, MophoKnobSensitivity::zeroTo127 },
		knob_VelAmount{ "VELO", publicParams, privateParams, ID::vcaVelAmount, MophoParameterIndex::vcaVelAmount, MophoParameterType::plainInteger, MophoKnobSensitivity::zeroTo127 },
		knob_PgmVolume{ "VOLUME", publicParams, privateParams, ID::pgmVolume, MophoParameterIndex::pgmVolume, MophoParameterType::plainInteger, MophoKnobSensitivity::zeroTo127 },
		envelopeWidget{ publicParams, privateParams, "vca", MophoParameterIndex::vcaDelay }
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
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 30, 15 };
		g.drawText("VCA", sectionLabelArea, Justification::left);
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
	KnobWidget knob_VCAlevel;
	KnobWidget knob_VCAenvAmt;
	KnobWidget knob_VelAmount;
	KnobWidget knob_PgmVolume;

	EnvelopeWidget envelopeWidget;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VCASection)
};

