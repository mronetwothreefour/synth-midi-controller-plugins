#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/ButtonWidgets.h"
#include "../widgets/KnobWidgets.h"
#include "../widgets/MenuWidgets.h"

// A set of controls for the parameters that are specific to sequencer
// track 1: destination, steps 1 to 16, and a clear steps button
class Track1Controls :
	public Component,
	public ComboBox::Listener,
	public Button::Listener
{
public:
	Track1Controls
	(
		PluginProcessor& p,
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		ValueConverters* vc
	) :
		processor{ p },
		menu_destination{ 1, publicParams, privateParams, this, vc },
		button_Clear{ "CLEAR", "Sets all steps to \"Rest.\""},
		knob_Step01{ 1 , publicParams, privateParams, vc },
		knob_Step02{ 2 , publicParams, privateParams, vc },
		knob_Step03{ 3 , publicParams, privateParams, vc },
		knob_Step04{ 4 , publicParams, privateParams, vc },
		knob_Step05{ 5 , publicParams, privateParams, vc },
		knob_Step06{ 6 , publicParams, privateParams, vc },
		knob_Step07{ 7 , publicParams, privateParams, vc },
		knob_Step08{ 8 , publicParams, privateParams, vc },
		knob_Step09{ 9 , publicParams, privateParams, vc },
		knob_Step10{ 10, publicParams, privateParams, vc },
		knob_Step11{ 11, publicParams, privateParams, vc },
		knob_Step12{ 12, publicParams, privateParams, vc },
		knob_Step13{ 13, publicParams, privateParams, vc },
		knob_Step14{ 14, publicParams, privateParams, vc },
		knob_Step15{ 15, publicParams, privateParams, vc },
		knob_Step16{ 16, publicParams, privateParams, vc }
	{
		button_Clear.addListener(this);

		addAndMakeVisible(menu_destination);

		addAndMakeVisible(button_Clear);

		addAndMakeVisible(knob_Step01);
		addAndMakeVisible(knob_Step02);
		addAndMakeVisible(knob_Step03);
		addAndMakeVisible(knob_Step04);
		addAndMakeVisible(knob_Step05);
		addAndMakeVisible(knob_Step06);
		addAndMakeVisible(knob_Step07);
		addAndMakeVisible(knob_Step08);
		addAndMakeVisible(knob_Step09);
		addAndMakeVisible(knob_Step10);
		addAndMakeVisible(knob_Step11);
		addAndMakeVisible(knob_Step12);
		addAndMakeVisible(knob_Step13);
		addAndMakeVisible(knob_Step14);
		addAndMakeVisible(knob_Step15);
		addAndMakeVisible(knob_Step16);

		comboBoxChanged(menu_destination.getMenuPointer());

		auto trackControls_w{ 446 };
		auto trackControls_h{ 62 };
		setSize(trackControls_w, trackControls_h);
	}

	~Track1Controls() 
	{
		button_Clear.removeListener(this);
	}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw track label
		//==============================================================================
		Font oscNumLabel{ "Arial", "Black", 18.0f };
		g.setFont(oscNumLabel);
		Rectangle<int> oscNumLabelArea{ 0, 0, 95, 16 };
		g.drawText("TRACK 1", oscNumLabelArea, Justification::topLeft);
	}

	void resized() override
	{
		menu_destination.setBounds(105, 0, menu_destination.getWidth(), menu_destination.getHeight());

		button_Clear.setBounds(354, 0, 42, 16);

		auto step_w{ knob_Step01.getWidth() };
		auto step_h{ knob_Step01.getHeight() };
		auto stepGap{ 2 };
		auto step01_x{ 0 };
		auto step02_x{ step01_x + step_w + stepGap };
		auto step03_x{ step02_x + step_w + stepGap };
		auto step04_x{ step03_x + step_w + stepGap };
		auto step05_x{ step04_x + step_w + stepGap };
		auto step06_x{ step05_x + step_w + stepGap };
		auto step07_x{ step06_x + step_w + stepGap };
		auto step08_x{ step07_x + step_w + stepGap };
		auto step09_x{ step08_x + step_w + stepGap };
		auto step10_x{ step09_x + step_w + stepGap };
		auto step11_x{ step10_x + step_w + stepGap };
		auto step12_x{ step11_x + step_w + stepGap };
		auto step13_x{ step12_x + step_w + stepGap };
		auto step14_x{ step13_x + step_w + stepGap };
		auto step15_x{ step14_x + step_w + stepGap };
		auto step16_x{ step15_x + step_w + stepGap };
		auto step_y{ 22 };
		knob_Step01.setBounds(step01_x, step_y, step_w, step_h);
		knob_Step02.setBounds(step02_x, step_y, step_w, step_h);
		knob_Step03.setBounds(step03_x, step_y, step_w, step_h);
		knob_Step04.setBounds(step04_x, step_y, step_w, step_h);
		knob_Step05.setBounds(step05_x, step_y, step_w, step_h);
		knob_Step06.setBounds(step06_x, step_y, step_w, step_h);
		knob_Step07.setBounds(step07_x, step_y, step_w, step_h);
		knob_Step08.setBounds(step08_x, step_y, step_w, step_h);
		knob_Step09.setBounds(step09_x, step_y, step_w, step_h);
		knob_Step10.setBounds(step10_x, step_y, step_w, step_h);
		knob_Step11.setBounds(step11_x, step_y, step_w, step_h);
		knob_Step12.setBounds(step12_x, step_y, step_w, step_h);
		knob_Step13.setBounds(step13_x, step_y, step_w, step_h);
		knob_Step14.setBounds(step14_x, step_y, step_w, step_h);
		knob_Step15.setBounds(step15_x, step_y, step_w, step_h);
		knob_Step16.setBounds(step16_x, step_y, step_w, step_h);
	}

	void comboBoxChanged(ComboBox* comboBox) override
	{
		// Tell steps to draw their values as pitches if the
		// destination is set to an oscillator pitch parameter
		bool shouldDrawAsPitch;
		if (comboBox->getSelectedItemIndex() > 0 && comboBox->getSelectedItemIndex() < 4)
			shouldDrawAsPitch = true;
		else shouldDrawAsPitch = false;
		knob_Step01.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step02.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step03.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step04.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step05.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step06.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step07.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step08.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step09.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step10.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step11.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step12.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step13.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step14.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step15.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step16.drawValueAsPitch(shouldDrawAsPitch);
	}

	void buttonClicked(Button* buttonThatWasClicked) override 
	{
		if (buttonThatWasClicked == &button_Clear)
			processor.clearSequencerTrack(1);
	}

	void buttonStateChanged(Button* /*buttonThatChanged*/) override {}

private:
	PluginProcessor& processor;

	MenuWidget_TrackDestination menu_destination;

	TextButton button_Clear;

	KnobWidget_Track1Step knob_Step01;
	KnobWidget_Track1Step knob_Step02;
	KnobWidget_Track1Step knob_Step03;
	KnobWidget_Track1Step knob_Step04;
	KnobWidget_Track1Step knob_Step05;
	KnobWidget_Track1Step knob_Step06;
	KnobWidget_Track1Step knob_Step07;
	KnobWidget_Track1Step knob_Step08;
	KnobWidget_Track1Step knob_Step09;
	KnobWidget_Track1Step knob_Step10;
	KnobWidget_Track1Step knob_Step11;
	KnobWidget_Track1Step knob_Step12;
	KnobWidget_Track1Step knob_Step13;
	KnobWidget_Track1Step knob_Step14;
	KnobWidget_Track1Step knob_Step15;
	KnobWidget_Track1Step knob_Step16;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Track1Controls)
};

// A set of controls for the parameters that are specific to sequencer
// track 1: destination, steps 1 to 16, and a clear steps button
class Tracks2_3_4Controls :
	public Component,
	public ComboBox::Listener,
	public Button::Listener
{
public:
	Tracks2_3_4Controls
	(
		int trackNum,
		PluginProcessor& p,
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		ValueConverters* vc
	) :
		trackNumber{ trackNum },
		processor{ p },
		menu_destination{ trackNumber, publicParams, privateParams, this, vc },
		button_Clear{ "CLEAR", "Sets all steps to 0 (C0)"},
		knob_Step01{ trackNumber, 1 , publicParams, privateParams, vc },
		knob_Step02{ trackNumber, 2 , publicParams, privateParams, vc },
		knob_Step03{ trackNumber, 3 , publicParams, privateParams, vc },
		knob_Step04{ trackNumber, 4 , publicParams, privateParams, vc },
		knob_Step05{ trackNumber, 5 , publicParams, privateParams, vc },
		knob_Step06{ trackNumber, 6 , publicParams, privateParams, vc },
		knob_Step07{ trackNumber, 7 , publicParams, privateParams, vc },
		knob_Step08{ trackNumber, 8 , publicParams, privateParams, vc },
		knob_Step09{ trackNumber, 9 , publicParams, privateParams, vc },
		knob_Step10{ trackNumber, 10, publicParams, privateParams, vc },
		knob_Step11{ trackNumber, 11, publicParams, privateParams, vc },
		knob_Step12{ trackNumber, 12, publicParams, privateParams, vc },
		knob_Step13{ trackNumber, 13, publicParams, privateParams, vc },
		knob_Step14{ trackNumber, 14, publicParams, privateParams, vc },
		knob_Step15{ trackNumber, 15, publicParams, privateParams, vc },
		knob_Step16{ trackNumber, 16, publicParams, privateParams, vc }
	{
		button_Clear.addListener(this);

		addAndMakeVisible(menu_destination);

		addAndMakeVisible(button_Clear);

		addAndMakeVisible(knob_Step01);
		addAndMakeVisible(knob_Step02);
		addAndMakeVisible(knob_Step03);
		addAndMakeVisible(knob_Step04);
		addAndMakeVisible(knob_Step05);
		addAndMakeVisible(knob_Step06);
		addAndMakeVisible(knob_Step07);
		addAndMakeVisible(knob_Step08);
		addAndMakeVisible(knob_Step09);
		addAndMakeVisible(knob_Step10);
		addAndMakeVisible(knob_Step11);
		addAndMakeVisible(knob_Step12);
		addAndMakeVisible(knob_Step13);
		addAndMakeVisible(knob_Step14);
		addAndMakeVisible(knob_Step15);
		addAndMakeVisible(knob_Step16);

		comboBoxChanged(menu_destination.getMenuPointer());

		auto trackControls_w{ 446 };
		auto trackControls_h{ 62 };
		setSize(trackControls_w, trackControls_h);
	}

	~Tracks2_3_4Controls()
	{
		button_Clear.removeListener(this);
	}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw track label
		//==============================================================================
		Font oscNumLabel{ "Arial", "Black", 18.0f };
		g.setFont(oscNumLabel);
		Rectangle<int> oscNumLabelArea{ 0, 0, 95, 16 };
		g.drawText("TRACK " + (String)trackNumber, oscNumLabelArea, Justification::topLeft);
	}

	void resized() override
	{
		menu_destination.setBounds(105, 0, menu_destination.getWidth(), menu_destination.getHeight());

		button_Clear.setBounds(354, 0, 42, 16);

		auto step_w{ knob_Step01.getWidth() };
		auto step_h{ knob_Step01.getHeight() };
		auto stepGap{ 2 };
		auto step01_x{ 0 };
		auto step02_x{ step01_x + step_w + stepGap };
		auto step03_x{ step02_x + step_w + stepGap };
		auto step04_x{ step03_x + step_w + stepGap };
		auto step05_x{ step04_x + step_w + stepGap };
		auto step06_x{ step05_x + step_w + stepGap };
		auto step07_x{ step06_x + step_w + stepGap };
		auto step08_x{ step07_x + step_w + stepGap };
		auto step09_x{ step08_x + step_w + stepGap };
		auto step10_x{ step09_x + step_w + stepGap };
		auto step11_x{ step10_x + step_w + stepGap };
		auto step12_x{ step11_x + step_w + stepGap };
		auto step13_x{ step12_x + step_w + stepGap };
		auto step14_x{ step13_x + step_w + stepGap };
		auto step15_x{ step14_x + step_w + stepGap };
		auto step16_x{ step15_x + step_w + stepGap };
		auto step_y{ 22 };
		knob_Step01.setBounds(step01_x, step_y, step_w, step_h);
		knob_Step02.setBounds(step02_x, step_y, step_w, step_h);
		knob_Step03.setBounds(step03_x, step_y, step_w, step_h);
		knob_Step04.setBounds(step04_x, step_y, step_w, step_h);
		knob_Step05.setBounds(step05_x, step_y, step_w, step_h);
		knob_Step06.setBounds(step06_x, step_y, step_w, step_h);
		knob_Step07.setBounds(step07_x, step_y, step_w, step_h);
		knob_Step08.setBounds(step08_x, step_y, step_w, step_h);
		knob_Step09.setBounds(step09_x, step_y, step_w, step_h);
		knob_Step10.setBounds(step10_x, step_y, step_w, step_h);
		knob_Step11.setBounds(step11_x, step_y, step_w, step_h);
		knob_Step12.setBounds(step12_x, step_y, step_w, step_h);
		knob_Step13.setBounds(step13_x, step_y, step_w, step_h);
		knob_Step14.setBounds(step14_x, step_y, step_w, step_h);
		knob_Step15.setBounds(step15_x, step_y, step_w, step_h);
		knob_Step16.setBounds(step16_x, step_y, step_w, step_h);
	}

	void comboBoxChanged(ComboBox* comboBox) override
	{
		// Tell steps to draw their values as pitches if the
		// destination is set to an oscillator pitch parameter
		bool shouldDrawAsPitch;
		if (comboBox->getSelectedItemIndex() > 0 && comboBox->getSelectedItemIndex() < 4)
			shouldDrawAsPitch = true;
		else shouldDrawAsPitch = false;
		knob_Step01.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step02.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step03.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step04.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step05.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step06.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step07.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step08.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step09.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step10.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step11.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step12.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step13.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step14.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step15.drawValueAsPitch(shouldDrawAsPitch);
		knob_Step16.drawValueAsPitch(shouldDrawAsPitch);
	}

	void buttonClicked(Button* buttonThatWasClicked) override 
	{
		if (buttonThatWasClicked == &button_Clear)
			processor.clearSequencerTrack(trackNumber);
	}

	void buttonStateChanged(Button* /*buttonThatChanged*/) override {}

private:
	PluginProcessor& processor;

	int trackNumber;

	MenuWidget_TrackDestination menu_destination;

	TextButton button_Clear;

	KnobWidget_Tracks2_3_4Step knob_Step01;
	KnobWidget_Tracks2_3_4Step knob_Step02;
	KnobWidget_Tracks2_3_4Step knob_Step03;
	KnobWidget_Tracks2_3_4Step knob_Step04;
	KnobWidget_Tracks2_3_4Step knob_Step05;
	KnobWidget_Tracks2_3_4Step knob_Step06;
	KnobWidget_Tracks2_3_4Step knob_Step07;
	KnobWidget_Tracks2_3_4Step knob_Step08;
	KnobWidget_Tracks2_3_4Step knob_Step09;
	KnobWidget_Tracks2_3_4Step knob_Step10;
	KnobWidget_Tracks2_3_4Step knob_Step11;
	KnobWidget_Tracks2_3_4Step knob_Step12;
	KnobWidget_Tracks2_3_4Step knob_Step13;
	KnobWidget_Tracks2_3_4Step knob_Step14;
	KnobWidget_Tracks2_3_4Step knob_Step15;
	KnobWidget_Tracks2_3_4Step knob_Step16;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tracks2_3_4Controls)
};

// Groups together the controls for the sequencer:
// sequencer off/on, trigger mode, clock division, BPM,
// and controls for 4 sequencer tracks.
class SequencerSection : public Component
{
public:
	SequencerSection
	(
		PluginProcessor& processor,
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		ValueConverters* vc
	) :
		button_SequencerOffOn{ publicParams, privateParams, ID::sequencerOnOff, MophoParameterIndex::sequencerOnOff, MophoParameterType::offOn },
		menu_TriggerMode{ publicParams, privateParams, 114, vc },
		menu_ClockDiv{ publicParams, privateParams, 124, vc },
		knob_ClockTempo{ publicParams, privateParams, vc },
		track1Controls{ processor, publicParams, privateParams, vc },
		track2Controls{ 2, processor, publicParams, privateParams, vc },
		track3Controls{ 3, processor, publicParams, privateParams, vc },
		track4Controls{ 4, processor, publicParams, privateParams, vc }
	{
		addAndMakeVisible(button_SequencerOffOn);
		addAndMakeVisible(menu_TriggerMode);
		addAndMakeVisible(menu_ClockDiv);
		addAndMakeVisible(knob_ClockTempo);
		addAndMakeVisible(track1Controls);
		addAndMakeVisible(track2Controls);
		addAndMakeVisible(track3Controls);
		addAndMakeVisible(track4Controls);

		auto seqSection_w{ 450 };
		auto seqSection_h{ 370 };
		setSize(seqSection_w, seqSection_h);
	}

	~SequencerSection() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 18, 15, 90, 10 };
		g.drawText("SEQUENCER", sectionLabelArea, Justification::left);
	}

	void resized() override
	{
		auto menu_h{ menu_TriggerMode.getHeight() };
		button_SequencerOffOn.setBounds(0, 13, button_SequencerOffOn.getWidth(), button_SequencerOffOn.getHeight());
		menu_TriggerMode.setBounds(129, 12, menu_TriggerMode.getWidth(), menu_h);
		menu_ClockDiv.setBounds(265, 12, menu_ClockDiv.getWidth(), menu_h);
		knob_ClockTempo.setBounds(404, 0, knob_ClockTempo.getWidth(), knob_ClockTempo.getHeight());
		auto trackControls_w{ track1Controls.getWidth() };
		auto trackControls_h{ track1Controls.getHeight() };
		auto trackControlsGap{ 21 };
		auto track1Controls_y{ 47 };
		auto track2Controls_y{ track1Controls_y + trackControls_h + trackControlsGap };
		auto track3Controls_y{ track2Controls_y + trackControls_h + trackControlsGap };
		auto track4Controls_y{ track3Controls_y + trackControls_h + trackControlsGap };
		track1Controls.setBounds(0, track1Controls_y, trackControls_w, trackControls_h);
		track2Controls.setBounds(0, track2Controls_y, trackControls_w, trackControls_h);
		track3Controls.setBounds(0, track3Controls_y, trackControls_w, trackControls_h);
		track4Controls.setBounds(0, track4Controls_y, trackControls_w, trackControls_h);
	}

private:
	ButtonWidget button_SequencerOffOn;

	KnobWidget_ClockTempo knob_ClockTempo;

	MenuWidget_SeqTrigger menu_TriggerMode;
	MenuWidget_ClockDiv menu_ClockDiv;

	Track1Controls track1Controls;

	Tracks2_3_4Controls track2Controls;
	Tracks2_3_4Controls track3Controls;
	Tracks2_3_4Controls track4Controls;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerSection)
};
