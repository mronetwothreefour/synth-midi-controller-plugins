#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/KnobWidgets.h"
#include "../widgets/MenuWidgets.h"

// A set of controls for the parameters that are specific
// to one of the MIDI controllers: destination and amount
class MidiControllerControls : public Component
{
public:
	MidiControllerControls
	(
		String controllerName,
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		Identifier destinationParamID,
		Identifier amountParamID,
		int amountParamIndex,
		ValueConverters* vc
	) :
		menu_Destination{ controllerName, publicParams, privateParams, destinationParamID, 136, vc },
		knob_Amount{ "AMT", publicParams, privateParams, amountParamID, amountParamIndex, MophoParameterType::modAmount, MophoKnobSensitivity::modAmount }
	{
		addAndMakeVisible(menu_Destination);
		addAndMakeVisible(knob_Amount);

		auto modControls_w{ 185 };
		auto modControls_h{ 50 };
		setSize(modControls_w, modControls_h);
	}

	~MidiControllerControls() {}

	void resized() override
	{
		menu_Destination.setBounds(0, 12, menu_Destination.getWidth(), menu_Destination.getHeight());
		knob_Amount.setBounds(144, 0, knob_Amount.getWidth(), knob_Amount.getHeight());
	}

private:
	MenuWidget_MidiDestination menu_Destination;

	KnobWidget knob_Amount;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiControllerControls)
};

class MidiControllersSection : public Component
{
public:
	MidiControllersSection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		ValueConverters* vc
	) :
		modWheelControls{ "MOD WHEEL", publicParams, privateParams, ID::modWheelDest, ID::modWheelAmount, MophoParameterIndex::modWheelAmount, vc },
		aftertouchControls{ "AFTERTOUCH", publicParams, privateParams, ID::aftertouchDest, ID::aftertouchAmount, MophoParameterIndex::aftertouchAmount, vc },
		breathControls{ "BREATH", publicParams, privateParams, ID::breathDest, ID::breathAmount, MophoParameterIndex::breathAmount, vc },
		velocityControls{ "VELOCITY", publicParams, privateParams, ID::velocityDest, ID::velocityAmount, MophoParameterIndex::velocityAmount, vc },
		footControls{ "FOOT PEDAL", publicParams, privateParams, ID::footPedalDest, ID::footPedalAmount, MophoParameterIndex::footPedalAmount, vc }
	{
		addAndMakeVisible(modWheelControls);
		addAndMakeVisible(aftertouchControls);
		addAndMakeVisible(breathControls);
		addAndMakeVisible(velocityControls);
		addAndMakeVisible(footControls);

		auto modSection_w{ modWheelControls.getWidth() };
		auto modSection_h{ 325 };
		setSize(modSection_w, modSection_h);
	}

	~MidiControllersSection() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 150, 10 };
		g.drawText("MIDI CONTROLLERS", sectionLabelArea, Justification::left);
	}

	void resized() override
	{
		auto controls_w{ modWheelControls.getWidth() };
		auto controls_h{ modWheelControls.getHeight() };
		modWheelControls	.setBounds(0, 17 , controls_w, controls_h);
		aftertouchControls	.setBounds(0, 79 , controls_w, controls_h);
		breathControls		.setBounds(0, 141, controls_w, controls_h);
		velocityControls	.setBounds(0, 203, controls_w, controls_h);
		footControls		.setBounds(0, 265, controls_w, controls_h);
	}

private:
	MidiControllerControls modWheelControls;
	MidiControllerControls aftertouchControls;
	MidiControllerControls breathControls;
	MidiControllerControls velocityControls;
	MidiControllerControls footControls;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiControllersSection)
};