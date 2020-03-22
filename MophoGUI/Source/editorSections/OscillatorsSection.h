#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/ButtonWidgets.h"
#include "../widgets/KnobWidgets.h"

// A set of controls for the parameters that are specific
// to one of the oscillators: pitch, fine tune, wave shape,
// glide rate, sub-oscillator, and key tracking
class OscillatorControls : public Component
{
public:
	OscillatorControls
	(
		int oscNum,
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		oscNumString{ (String)oscNum },
		knob_OscPitch		{ publicParams, privateParams, "osc" + oscNumString + "Pitch", mophoLaF },
		knob_OscFineTune	{ publicParams, privateParams, "osc" + oscNumString + "Fine", mophoLaF },
		knob_OscShape		{ publicParams, privateParams, "osc" + oscNumString + "Shape", mophoLaF },
		knob_OscGlide		{ publicParams, privateParams, "osc" + oscNumString + "Glide", mophoLaF },
		knob_OscSubLvl		{ publicParams, privateParams, "osc" + oscNumString + "SubLevel",	mophoLaF }
	{
		addAndMakeVisible(knob_OscPitch);
		addAndMakeVisible(knob_OscFineTune);
		addAndMakeVisible(knob_OscShape);
		addAndMakeVisible(knob_OscGlide);
		addAndMakeVisible(knob_OscSubLvl);

		auto oscillatorSection_w{ 280 };
		auto oscillatorSection_h{ knob_OscPitch.getHeight() };
		setSize(oscillatorSection_w, oscillatorSection_h);
	}

	~OscillatorControls() {}

	void paint(Graphics& g) override
	{
		// Draw oscillator number label
		//==============================================================================
		g.setColour(Color::black);
		Font oscNumLabel{ "Arial", "Black", 24.0f };
		g.setFont(oscNumLabel);
		Rectangle<int> oscNumLabelArea{ 0, 5, 15, 30 };
		g.drawText(oscNumString, oscNumLabelArea, Justification::centredLeft);
	}

	void resized() override
	{
		auto knobWidget_w{ knob_OscPitch.getWidth() };
		auto knobWidget_h{ knob_OscPitch.getHeight() };
		auto knobGap{ 5 };
		auto knob1_x{ 13 };
		auto knob2_x{ knob1_x + knobWidget_w + knobGap };
		auto knob3_x{ knob2_x + knobWidget_w + knobGap };
		auto knob4_x{ knob3_x + knobWidget_w + knobGap };
		auto knob5_x{ knob4_x + knobWidget_w + knobGap };
		knob_OscPitch		.setBounds(knob1_x, 0, knobWidget_w, knobWidget_h);
		knob_OscFineTune	.setBounds(knob2_x, 0, knobWidget_w, knobWidget_h);
		knob_OscShape		.setBounds(knob3_x, 0, knobWidget_w, knobWidget_h);
		knob_OscGlide		.setBounds(knob4_x, 0, knobWidget_w, knobWidget_h);
		knob_OscSubLvl		.setBounds(knob5_x, 0, knobWidget_w, knobWidget_h);
	}

private:
	String oscNumString;

	KnobWidget_OscPitch    knob_OscPitch;
	KnobWidget_FineTune    knob_OscFineTune;
	KnobWidget_OscShape    knob_OscShape;
	KnobWidget_OscGlide    knob_OscGlide;
	KnobWidget_OscSubLvl   knob_OscSubLvl;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscillatorControls)
};

// Groups together the controls for the
// oscillators, the mixer, and the arpeggiator
class OscillatorsSection : public Component
{
public:
	OscillatorsSection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		button_Sync{ "oscSync", publicParams, privateParams, ID::oscSync, mophoLaF },
		osc1Controls{ 1, publicParams, privateParams, mophoLaF },
		osc2Controls{ 2, publicParams, privateParams, mophoLaF },
		knob_OscSlop{ publicParams, privateParams, mophoLaF },
		knob_OscMix{ publicParams, privateParams, mophoLaF },
		knob_BendRange{ publicParams, privateParams, mophoLaF },
		knob_NoiseLevel{ publicParams, privateParams, mophoLaF },
		knob_ExtInLevel{ publicParams, privateParams, mophoLaF }
	{
		addAndMakeVisible(button_Sync);
		addAndMakeVisible(osc1Controls);
		addAndMakeVisible(osc2Controls);
		addAndMakeVisible(knob_OscSlop);
		addAndMakeVisible(knob_OscMix);
		addAndMakeVisible(knob_BendRange);
		addAndMakeVisible(knob_NoiseLevel);
		addAndMakeVisible(knob_ExtInLevel);

		auto oscSection_w{ 550 };
		auto oscSection_h{ 130 };
		setSize(oscSection_w, oscSection_h);
	}

	~OscillatorsSection() { button_Sync.setLookAndFeel(nullptr); }

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 105, 15 };
		g.drawText("OSCILLATORS", sectionLabelArea, Justification::centredLeft);

		// Draw sync button label
		Font syncLabel{ "Arial", "Black", 12.0f };
		g.setFont(syncLabel);
		Rectangle<int> syncLabelArea{ 218, 0, 30, 14 };
		g.drawText("SYNC", syncLabelArea, Justification::centredRight);

		// Draw oscillator dividing line
		g.drawHorizontalLine(70, 0, 280);

		// Draw oscillator number labels for mix knob
		Font mixNumLabel{ "Arial", "Bold", 11.0f };
		g.setFont(mixNumLabel);
		Rectangle<int> mixNum1LabelArea{ 328, 44, 6, 13 };
		g.drawText("1", mixNum1LabelArea, Justification::centred);
		Rectangle<int> mixNum2LabelArea{ 363, 44, 6, 13 };
		g.drawText("2", mixNum2LabelArea, Justification::centred);
	}

	void resized() override
	{
		button_Sync.setBounds(251, 0, 14, 14);

		auto knob_w{ knob_OscSlop.getWidth() };
		auto knob_h{ knob_OscSlop.getHeight() };
		auto knobGap{ 5 };

		auto knob_col1_x{ 283 };
		auto knob_col2_x{ knob_col1_x + knob_w + knobGap };
		auto knob_col3_x{ knob_col2_x + knob_w + knobGap };

		auto knob_row1_y{ 15 };
		auto knob_row2_y{ 75 };
		osc1Controls.setBounds(0, knob_row1_y, osc1Controls.getWidth(), knob_h);
		osc2Controls.setBounds(0, knob_row2_y, osc2Controls.getWidth(), knob_h);

		knob_OscSlop	.setBounds(knob_col1_x, knob_row1_y, knob_w, knob_h);
		knob_OscMix		.setBounds(knob_col2_x, knob_row1_y, knob_w, knob_h);
		knob_BendRange	.setBounds(knob_col3_x, knob_row1_y, knob_w, knob_h);
		knob_NoiseLevel	.setBounds(knob_col1_x, knob_row2_y, knob_w, knob_h);
		knob_ExtInLevel	.setBounds(knob_col2_x, knob_row2_y, knob_w, knob_h);
	}

private:
	ButtonWidget_Sync button_Sync;

	OscillatorControls osc1Controls;
	OscillatorControls osc2Controls;

	KnobWidget_OscSlop     knob_OscSlop;
	KnobWidget_OscMix      knob_OscMix;
	KnobWidget_BendRange   knob_BendRange;
	KnobWidget_NoiseLevel  knob_NoiseLevel;
	KnobWidget_ExtInLevel  knob_ExtInLevel;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscillatorsSection)
};