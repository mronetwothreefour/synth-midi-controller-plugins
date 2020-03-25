#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/ButtonWidgets.h"
#include "../widgets/KnobWidgets.h"
#include "../widgets/MenuWidgets.h"

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
		knob_OscSubLvl		{ publicParams, privateParams, "osc" + oscNumString + "SubLevel",	mophoLaF },
		button_Track		{ "track", publicParams, privateParams, "osc" + oscNumString + "KeyTrack",	mophoLaF }
	{
		addAndMakeVisible(knob_OscPitch);
		addAndMakeVisible(knob_OscFineTune);
		addAndMakeVisible(knob_OscShape);
		addAndMakeVisible(knob_OscGlide);
		addAndMakeVisible(knob_OscSubLvl);
		addAndMakeVisible(button_Track);

		auto oscControls_w{ 280 };
		auto oscControls_h{ knob_OscPitch.getHeight() };
		setSize(oscControls_w, oscControls_h);
	}

	~OscillatorControls() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw oscillator number label
		//==============================================================================
		Font oscNumLabel{ "Arial", "Black", 24.0f };
		g.setFont(oscNumLabel);
		Rectangle<int> oscNumLabelArea{ 0, 5, 15, 30 };
		g.drawText(oscNumString, oscNumLabelArea, Justification::centredLeft);

		// Draw track button label
		//==============================================================================
		Font trackLabel{ "Arial", "Black", 12.0f };
		g.setFont(trackLabel);
		Rectangle<int> trackLabelArea{ 240, 29, 36, 14 };
		g.drawText("TRACK", trackLabelArea, Justification::centred);
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
		auto button_x{ knob5_x + knobWidget_w + knobGap + 13 };
		auto button_y{ 13 };
		knob_OscPitch		.setBounds(knob1_x, 0, knobWidget_w, knobWidget_h);
		knob_OscFineTune	.setBounds(knob2_x, 0, knobWidget_w, knobWidget_h);
		knob_OscShape		.setBounds(knob3_x, 0, knobWidget_w, knobWidget_h);
		knob_OscGlide		.setBounds(knob4_x, 0, knobWidget_w, knobWidget_h);
		knob_OscSubLvl		.setBounds(knob5_x, 0, knobWidget_w, knobWidget_h);
		button_Track		.setBounds(button_x, button_y, button_Track.getWidth(), button_Track.getHeight());
	}

private:
	String oscNumString;

	KnobWidget_OscPitch    knob_OscPitch;
	KnobWidget_FineTune    knob_OscFineTune;
	KnobWidget_OscShape    knob_OscShape;
	KnobWidget_OscGlide    knob_OscGlide;
	KnobWidget_OscSubLvl   knob_OscSubLvl;

	ButtonWidget_Track button_Track;

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
		button_Sync{ "oscSync", publicParams, privateParams, mophoLaF },
		osc1Controls{ 1, publicParams, privateParams, mophoLaF },
		osc2Controls{ 2, publicParams, privateParams, mophoLaF },
		knob_OscSlop{ publicParams, privateParams, mophoLaF },
		knob_OscMix{ publicParams, privateParams, mophoLaF },
		knob_BendRange{ publicParams, privateParams, mophoLaF },
		knob_NoiseLevel{ publicParams, privateParams, mophoLaF },
		knob_ExtInLevel{ publicParams, privateParams, mophoLaF },
		button_Arpeg{ "arpeg", publicParams, privateParams, mophoLaF },
		menu_NotePriority{ publicParams, privateParams, mophoLaF, 123 },
		menu_GlideMode{ publicParams, privateParams, mophoLaF, 123 },
		menu_ArpegMode{ publicParams, privateParams, mophoLaF, 123 }
	{
		addAndMakeVisible(button_Sync);
		addAndMakeVisible(osc1Controls);
		addAndMakeVisible(osc2Controls);
		addAndMakeVisible(knob_OscSlop);
		addAndMakeVisible(knob_OscMix);
		addAndMakeVisible(knob_BendRange);
		addAndMakeVisible(knob_NoiseLevel);
		addAndMakeVisible(knob_ExtInLevel);
		addAndMakeVisible(button_Arpeg);
		addAndMakeVisible(menu_NotePriority);
		addAndMakeVisible(menu_GlideMode);
		addAndMakeVisible(menu_ArpegMode);

		auto oscSection_w{ 550 };
		auto oscSection_h{ 130 };
		setSize(oscSection_w, oscSection_h);
	}

	~OscillatorsSection() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 105, 10 };
		g.drawText("OSCILLATORS", sectionLabelArea, Justification::left);

		// Draw sync button label
		Font buttonLabel{ "Arial", "Black", 12.0f };
		g.setFont(buttonLabel);
		Rectangle<int> syncLabelArea{ 218, 2, 30, 14 };
		g.drawText("SYNC", syncLabelArea, Justification::centredRight);

		// Draw arpeggiator button label
		Rectangle<int> arpegLabelArea{ 373, 104, 40, 14 };
		g.drawText("ARPEG", arpegLabelArea, Justification::centred);

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
		auto button_diameter{ button_Sync.getWidth() };
		button_Sync.setBounds(251, 2, button_diameter, button_diameter);

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

		button_Arpeg	.setBounds(knob_col3_x + 13, knob_row2_y + 13, button_diameter, button_diameter);

		auto menuCol_x{ 424 };
		auto menu1_y{ 15 };
		auto menu2_y{ menu1_y + 40 };
		auto menu3_y{ menu2_y + 40 };
		auto menu_w{ menu_NotePriority.getWidth() };
		auto menu_h{ menu_NotePriority.getHeight() };
		menu_NotePriority	.setBounds(menuCol_x, menu1_y, menu_w, menu_h);
		menu_GlideMode		.setBounds(menuCol_x, menu2_y, menu_w, menu_h);
		menu_ArpegMode		.setBounds(menuCol_x, menu3_y, menu_w, menu_h);
	}

private:
	ButtonWidget_Sync button_Sync;
	ButtonWidget_Arpeg button_Arpeg;

	OscillatorControls osc1Controls;
	OscillatorControls osc2Controls;

	KnobWidget_OscSlop     knob_OscSlop;
	KnobWidget_OscMix      knob_OscMix;
	KnobWidget_BendRange   knob_BendRange;
	KnobWidget_NoiseLevel  knob_NoiseLevel;
	KnobWidget_ExtInLevel  knob_ExtInLevel;

	MenuWidget_NotePriority menu_NotePriority;
	MenuWidget_GlideMode	menu_GlideMode;
	MenuWidget_ArpegMode	menu_ArpegMode;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscillatorsSection)
};