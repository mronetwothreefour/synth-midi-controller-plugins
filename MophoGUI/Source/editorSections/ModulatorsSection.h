#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/KnobWidgets.h"
#include "../widgets/MenuWidgets.h"

// A set of controls for the parameters that are specific
// to one of the modulators: source, destination, and amount
class ModulatorControls : public Component
{
public:
	ModulatorControls
	(
		int modNum,
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		modNumString{ modNum },
		menu_Source{ publicParams, privateParams, "mod" + modNumString + "Source", mophoLaF, 126 },
		menu_Destination{ publicParams, privateParams, "mod" + modNumString + "Destination", mophoLaF, 126 },
		knob_Amount{ publicParams, privateParams, "mod" + modNumString + "Amount", mophoLaF }
	{
		addAndMakeVisible(menu_Source);
		addAndMakeVisible(menu_Destination);
		addAndMakeVisible(knob_Amount);

		auto modControls_w{ 195 };
		auto modControls_h{ 70 };
		setSize(modControls_w, modControls_h);
	}

	~ModulatorControls() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw modulator number label
		//==============================================================================
		Font oscNumLabel{ "Arial", "Black", 24.0f };
		g.setFont(oscNumLabel);
		Rectangle<int> oscNumLabelArea{ 0, 0, 15, 50 };
		g.drawText(modNumString, oscNumLabelArea, Justification::centredLeft);
	}

	void resized() override
	{
		menu_Source		.setBounds(19 , 0 , menu_Source.getWidth(), menu_Source.getHeight());
		menu_Destination.setBounds(19 , 34, menu_Source.getWidth(), menu_Source.getHeight());
		knob_Amount		.setBounds(151, 5 , knob_Amount.getWidth(), knob_Amount.getHeight());
	}

private:
	String modNumString;

	MenuWidget_ModSource menu_Source;
	MenuWidget_ModDestination menu_Destination;

	KnobWidget_ModAmt knob_Amount;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModulatorControls)
};

class ModulatorsSection : public Component
{
public:
	ModulatorsSection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		modControls1{ 1, publicParams, privateParams, mophoLaF },
		modControls2{ 2, publicParams, privateParams, mophoLaF },
		modControls3{ 3, publicParams, privateParams, mophoLaF },
		modControls4{ 4, publicParams, privateParams, mophoLaF }
	{
		addAndMakeVisible(modControls1);
		addAndMakeVisible(modControls2);
		addAndMakeVisible(modControls3);
		addAndMakeVisible(modControls4);

		auto modSection_w{ 195 };
		auto modSection_h{ 325 };
		setSize(modSection_w, modSection_h);
	}

	~ModulatorsSection() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 105, 10 };
		g.drawText("MODULATORS", sectionLabelArea, Justification::left);
	}

	void resized() override
	{
		modControls1.setBounds(0, 22,  modControls1.getWidth(), modControls1.getHeight());
		modControls2.setBounds(0, 100, modControls2.getWidth(), modControls2.getHeight());
		modControls3.setBounds(0, 178, modControls3.getWidth(), modControls3.getHeight());
		modControls4.setBounds(0, 256, modControls4.getWidth(), modControls4.getHeight());
	}

private:
	ModulatorControls modControls1;
	ModulatorControls modControls2;
	ModulatorControls modControls3;
	ModulatorControls modControls4;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModulatorsSection)
};