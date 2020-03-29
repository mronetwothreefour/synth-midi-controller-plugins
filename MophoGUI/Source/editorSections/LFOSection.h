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
// to one of the low-frequency oscillators: frequency, shape, 
// amount, type, key sync, and destination
class LFOControls : public Component
{
public:
	LFOControls
	(
		int lfoNum,
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		lfoNameString{ "LFO " + (String)lfoNum },
		knob_Amount{ publicParams, privateParams, "lfo" + (String)lfoNum + "Amount", mophoLaF },
		menu_Type{ 1, privateParams, mophoLaF },
		menu_Destination{ publicParams, privateParams, "lfo" + (String)lfoNum + "Destination", mophoLaF, 138, false }
	{
		addAndMakeVisible(knob_Amount);
		addAndMakeVisible(menu_Type);
		addAndMakeVisible(menu_Destination);

		auto lfoControls_w{ menu_Destination.getWidth() };
		auto lfoControls_h{ 142 };
		setSize(lfoControls_w, lfoControls_h);
	}

	~LFOControls() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw LFO name label
		//==============================================================================
		Font lfoLabel{ "Arial", "Black", 18.0f };
		g.setFont(lfoLabel);
		Rectangle<int> lfoLabelLabelArea{ 0, 0, 45, 10 };
		g.drawText(lfoNameString, lfoLabelLabelArea, Justification::left);

		// Draw key sync button label
		//==============================================================================
		Font keySyncLabel{ "Arial", "Black", 12.0f };
		g.setFont(keySyncLabel);
		Rectangle<int> keySyncLabelArea{ 108, 88, 20, 14 };
		g.drawText("KEY", keySyncLabelArea, Justification::centred);
	}

	void resized() override
	{
		auto knobWidget_w{ knob_Amount.getWidth() };
		auto knobWidget_h{ knob_Amount.getHeight() };
		auto knobGap{ 5 };
		auto knob1_x{ 0 };
		auto knob2_x{ knob1_x + knobWidget_w + knobGap };
		auto knob3_x{ knob2_x + knobWidget_w + knobGap };
		auto menu_h{ menu_Type.getHeight() };
		knob_Amount.setBounds(knob3_x, 0, knobWidget_w, knobWidget_h);
		menu_Type.setBounds(0, 73, menu_Type.getWidth(), menu_h);
		menu_Destination.setBounds(0, 107, menu_Destination.getWidth(), menu_h);
	}

private:
	String lfoNameString;

	KnobWidget_LFOAmt knob_Amount;

	MenuWidget_LFOtype menu_Type;
	MenuWidget_ModDestination menu_Destination;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LFOControls)
};

// Groups together the controls for the
// four low-frequency oscillators
class LFOSection : public Component
{
public:
	LFOSection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		lfo1Controls{ 1, publicParams, privateParams, mophoLaF },
		lfo2Controls{ 2, publicParams, privateParams, mophoLaF },
		lfo3Controls{ 3, publicParams, privateParams, mophoLaF },
		lfo4Controls{ 4, publicParams, privateParams, mophoLaF }
	{
		addAndMakeVisible(lfo1Controls);
		addAndMakeVisible(lfo2Controls);
		addAndMakeVisible(lfo3Controls);
		addAndMakeVisible(lfo4Controls);

		auto lfoSection_w{ 600 };
		auto lfoSection_h{ lfo1Controls.getHeight() };
		setSize(lfoSection_w, lfoSection_h);
	}

	~LFOSection() {}

	void resized() override
	{
		auto lfoControls_w{ lfo1Controls.getWidth() };
		auto lfoGap{ 15 };
		auto lfo1Controls_x{ 0 };
		auto lfo2Controls_x{ lfo1Controls_x + lfoControls_w + lfoGap };
		auto lfo3Controls_x{ lfo2Controls_x + lfoControls_w + lfoGap };
		auto lfo4Controls_x{ lfo3Controls_x + lfoControls_w + lfoGap };
		auto lfoControls_h{ lfo1Controls.getHeight() };
		lfo1Controls.setBounds(lfo1Controls_x, 0, lfoControls_w, lfoControls_h);
		lfo2Controls.setBounds(lfo2Controls_x, 0, lfoControls_w, lfoControls_h);
		lfo3Controls.setBounds(lfo3Controls_x, 0, lfoControls_w, lfoControls_h);
		lfo4Controls.setBounds(lfo4Controls_x, 0, lfoControls_w, lfoControls_h);
	}

private:
	LFOControls lfo1Controls;
	LFOControls lfo2Controls;
	LFOControls lfo3Controls;
	LFOControls lfo4Controls;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LFOSection)
};
