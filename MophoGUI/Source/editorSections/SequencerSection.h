#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/ButtonWidgets.h"
#include "../widgets/KnobWidgets.h"
#include "../widgets/MenuWidgets.h"

// A set of controls for the parameters that are specific to sequence 1:
// destination, steps 1 to 16, and a clear sequence button
class Sequence1Controls : public Component
{
public:
	Sequence1Controls
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
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

		auto seqControls_w{ 446 };
		auto seqControls_h{ 62 };
		setSize(seqControls_w, seqControls_h);
	}

	~Sequence1Controls() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw sequence label
		//==============================================================================
		Font oscNumLabel{ "Arial", "Black", 18.0f };
		g.setFont(oscNumLabel);
		Rectangle<int> oscNumLabelArea{ 0, 0, 95, 16 };
		g.drawText("SEQUENCE 1", oscNumLabelArea, Justification::centredLeft);
	}

	void resized() override
	{
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

private:
	KnobWidget_Seq1Step knob_Step01;
	KnobWidget_Seq1Step knob_Step02;
	KnobWidget_Seq1Step knob_Step03;
	KnobWidget_Seq1Step knob_Step04;
	KnobWidget_Seq1Step knob_Step05;
	KnobWidget_Seq1Step knob_Step06;
	KnobWidget_Seq1Step knob_Step07;
	KnobWidget_Seq1Step knob_Step08;
	KnobWidget_Seq1Step knob_Step09;
	KnobWidget_Seq1Step knob_Step10;
	KnobWidget_Seq1Step knob_Step11;
	KnobWidget_Seq1Step knob_Step12;
	KnobWidget_Seq1Step knob_Step13;
	KnobWidget_Seq1Step knob_Step14;
	KnobWidget_Seq1Step knob_Step15;
	KnobWidget_Seq1Step knob_Step16;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Sequence1Controls)
};



// Groups together the controls for the sequencer
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
		sequence1Controls{ publicParams, privateParams, mophoLaF }
	{
		addAndMakeVisible(button_SequencerOffOn);
		addAndMakeVisible(menu_TriggerMode);
		addAndMakeVisible(menu_ClockDiv);
		addAndMakeVisible(knob_ClockTempo);
		addAndMakeVisible(sequence1Controls);

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
		sequence1Controls.setBounds(0, 47, sequence1Controls.getWidth(), sequence1Controls.getHeight());
	}

private:
	ButtonWidget_SequencerOffOn button_SequencerOffOn;

	KnobWidget_ClockTempo knob_ClockTempo;

	MenuWidget_SeqTrigger menu_TriggerMode;
	MenuWidget_ClockDiv menu_ClockDiv;

	Sequence1Controls sequence1Controls;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerSection)
};
