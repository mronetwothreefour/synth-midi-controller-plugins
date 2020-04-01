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
		menu_TriggerMode{ publicParams, privateParams, mophoLaF, 114 }
	{
		addAndMakeVisible(button_SequencerOffOn);
		addAndMakeVisible(menu_TriggerMode);

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
	}

private:
	ButtonWidget_SequencerOffOn button_SequencerOffOn;

	MenuWidget_SeqTrigger menu_TriggerMode;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerSection)
};
