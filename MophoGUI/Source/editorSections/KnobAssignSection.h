#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/MenuWidgets.h"

// A set of menu controls for selecting target parameters
// for the Mopho's assignable hardware knobs
class KnobAssignSection : public Component
{
public:
	KnobAssignSection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF,
		ValueConverters* vc
	) :
		menu_Assign1{ 1, publicParams, privateParams, mophoLaF, 134, vc },
		menu_Assign2{ 2, publicParams, privateParams, mophoLaF, 134, vc },
		menu_Assign3{ 3, publicParams, privateParams, mophoLaF, 134, vc },
		menu_Assign4{ 4, publicParams, privateParams, mophoLaF, 134, vc }
	{
		addAndMakeVisible(menu_Assign1);
		addAndMakeVisible(menu_Assign2);
		addAndMakeVisible(menu_Assign3);
		addAndMakeVisible(menu_Assign4);

		auto section_w{ 153 };
		auto section_h{ 128 };
		setSize(section_w, section_h);
	}

	~KnobAssignSection() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 110, 15 };
		g.drawText("KNOB ASSIGN", sectionLabelArea, Justification::left);

		// Draw knob numbers
		//==============================================================================
		Font knobLabel{ "Arial", "Black", 20.0f };
		g.setFont(knobLabel);
		Rectangle<int> knob1LabelArea{ 0, 25, 15, 16 };
		g.drawText("1", knob1LabelArea, Justification::centredLeft);
		Rectangle<int> knob2LabelArea{ 0, 53, 15, 16 };
		g.drawText("2", knob2LabelArea, Justification::centredLeft);
		Rectangle<int> knob3LabelArea{ 0, 81, 15, 16 };
		g.drawText("3", knob3LabelArea, Justification::centredLeft);
		Rectangle<int> knob4LabelArea{ 0, 109, 15, 16 };
		g.drawText("4", knob4LabelArea, Justification::centredLeft);
	}

	void resized() override
	{
		auto menu_x{ 19 };
		auto menu_w{ menu_Assign1.getWidth() };
		auto menu_h{ menu_Assign1.getHeight() };
		menu_Assign1.setBounds(menu_x, 25 , menu_w, menu_h);
		menu_Assign2.setBounds(menu_x, 53 , menu_w, menu_h);
		menu_Assign3.setBounds(menu_x, 81 , menu_w, menu_h);
		menu_Assign4.setBounds(menu_x, 109, menu_w, menu_h);
	}

private:
	MenuWidget_KnobAssign menu_Assign1;
	MenuWidget_KnobAssign menu_Assign2;
	MenuWidget_KnobAssign menu_Assign3;
	MenuWidget_KnobAssign menu_Assign4;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAssignSection)
};