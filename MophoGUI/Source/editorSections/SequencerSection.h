#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/ButtonWidgets.h"
#include "../widgets/KnobWidgets.h"
#include "../widgets/MenuWidgets.h"

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
		knob_ClockTempo{ publicParams, privateParams, mophoLaF }
	{
		addAndMakeVisible(button_SequencerOffOn);
		addAndMakeVisible(menu_TriggerMode);
		addAndMakeVisible(menu_ClockDiv);
		addAndMakeVisible(knob_ClockTempo);

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
	}

private:
	ButtonWidget_SequencerOffOn button_SequencerOffOn;

	KnobWidget_ClockTempo knob_ClockTempo;

	MenuWidget_SeqTrigger menu_TriggerMode;
	MenuWidget_ClockDiv menu_ClockDiv;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerSection)
};
