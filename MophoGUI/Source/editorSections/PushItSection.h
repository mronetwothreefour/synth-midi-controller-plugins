#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/MenuWidgets.h"
#include "../widgets/KnobWidgets.h"

// A set of controls targeting the Push It! button parameters:
// pitch, velocity, and switch mode.
class PushItSection : public Component
{
public:
	PushItSection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		knob_Pitch{ publicParams, privateParams, mophoLaF },
		knob_Velocity{ publicParams, privateParams, mophoLaF },
		menu_Mode{ publicParams, privateParams, mophoLaF, 80 }
	{
		addAndMakeVisible(knob_Pitch);
		addAndMakeVisible(knob_Velocity);
		addAndMakeVisible(menu_Mode);

		auto section_w{ 90 };
		auto section_h{ 120 };
		setSize(section_w, section_h);
	}

	~PushItSection() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 65, 15 };
		g.drawText("PUSH IT!", sectionLabelArea, Justification::left);
	}

	void resized() override
	{
		knob_Pitch.setBounds(0, 20, knob_Pitch.getWidth(), knob_Pitch.getHeight());
		knob_Velocity.setBounds(50, 20, knob_Velocity.getWidth(), knob_Velocity.getHeight());
		menu_Mode.setBounds(0, 81, menu_Mode.getWidth(), menu_Mode.getHeight());
	}

private:
	KnobWidget_PushItPitch	knob_Pitch;
	KnobWidget_PushItVelo	knob_Velocity;

	MenuWidget_PushItMode menu_Mode;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PushItSection)
};