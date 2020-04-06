#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
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
	public Button::Listener,
	private Timer
{
public:
	Track1Controls
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		menu_destination{ 1, publicParams, privateParams, mophoLaF, this },
		button_Clear{ "CLEAR", "Sets all steps to \"Rest.\""},
		knob_Step01{ 1 , publicParams, privateParams, mophoLaF },
		knob_Step02{ 2 , publicParams, privateParams, mophoLaF },
		knob_Step03{ 3 , publicParams, privateParams, mophoLaF },
		knob_Step04{ 4 , publicParams, privateParams, mophoLaF },
		knob_Step05{ 5 , publicParams, privateParams, mophoLaF },
		knob_Step06{ 6 , publicParams, privateParams, mophoLaF },
		knob_Step07{ 7 , publicParams, privateParams, mophoLaF },
		knob_Step08{ 8 , publicParams, privateParams, mophoLaF },
		knob_Step09{ 9 , publicParams, privateParams, mophoLaF },
		knob_Step10{ 10, publicParams, privateParams, mophoLaF },
		knob_Step11{ 11, publicParams, privateParams, mophoLaF },
		knob_Step12{ 12, publicParams, privateParams, mophoLaF },
		knob_Step13{ 13, publicParams, privateParams, mophoLaF },
		knob_Step14{ 14, publicParams, privateParams, mophoLaF },
		knob_Step15{ 15, publicParams, privateParams, mophoLaF },
		knob_Step16{ 16, publicParams, privateParams, mophoLaF }
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
		{
			knob_Step01.setToRest();
			stepCounter = 2;
			startTimer(timerInterval);
		}
	}

	void timerCallback() override
	{
		stopTimer();
		switch (stepCounter)
		{
		case 2 : knob_Step02.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 3 : knob_Step03.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 4 : knob_Step04.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 5 : knob_Step05.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 6 : knob_Step06.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 7 : knob_Step07.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 8 : knob_Step08.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 9 : knob_Step09.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 10: knob_Step10.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 11: knob_Step11.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 12: knob_Step12.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 13: knob_Step13.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 14: knob_Step14.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 15: knob_Step15.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		case 16: knob_Step16.setToRest(); ++stepCounter; startTimer(timerInterval); break;
		default:
			break;
		}
	}


	void buttonStateChanged(Button* /*buttonThatChanged*/) override {}

private:
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

	int stepCounter{ 1 };
	int timerInterval{ 10 };

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Track1Controls)
};



// Groups together the controls for the sequencer:
// sequencer off/on, trigger mode, clock division, BPM,
// and controls for 4 sequencer tracks.
class SequencerSection : public Component
{
public:
	SequencerSection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		button_SequencerOffOn{ publicParams, privateParams, mophoLaF },
		menu_TriggerMode{ publicParams, privateParams, mophoLaF, 114 },
		menu_ClockDiv{ publicParams, privateParams, mophoLaF, 124 },
		knob_ClockTempo{ publicParams, privateParams, mophoLaF },
		track1Controls{ publicParams, privateParams, mophoLaF }
	{
		addAndMakeVisible(button_SequencerOffOn);
		addAndMakeVisible(menu_TriggerMode);
		addAndMakeVisible(menu_ClockDiv);
		addAndMakeVisible(knob_ClockTempo);
		addAndMakeVisible(track1Controls);

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
		track1Controls.setBounds(0, 47, track1Controls.getWidth(), track1Controls.getHeight());
	}

private:
	ButtonWidget_SequencerOffOn button_SequencerOffOn;

	KnobWidget_ClockTempo knob_ClockTempo;

	MenuWidget_SeqTrigger menu_TriggerMode;
	MenuWidget_ClockDiv menu_ClockDiv;

	Track1Controls track1Controls;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerSection)
};
