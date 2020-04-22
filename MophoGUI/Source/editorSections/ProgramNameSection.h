#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/KnobWidgets.h"

// A set of controls targeting the program name characters
class ProgramNameSection : public Component
{
public:
	ProgramNameSection
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParams,
		MophoLookAndFeel* mophoLaF
	) :
		knob_NameChar01{ 1 , publicParams, privateParams, mophoLaF },
		knob_NameChar02{ 2 , publicParams, privateParams, mophoLaF },
		knob_NameChar03{ 3 , publicParams, privateParams, mophoLaF },
		knob_NameChar04{ 4 , publicParams, privateParams, mophoLaF },
		knob_NameChar05{ 5 , publicParams, privateParams, mophoLaF },
		knob_NameChar06{ 6 , publicParams, privateParams, mophoLaF },
		knob_NameChar07{ 7 , publicParams, privateParams, mophoLaF },
		knob_NameChar08{ 8 , publicParams, privateParams, mophoLaF },
		knob_NameChar09{ 9 , publicParams, privateParams, mophoLaF },
		knob_NameChar10{ 10, publicParams, privateParams, mophoLaF },
		knob_NameChar11{ 11, publicParams, privateParams, mophoLaF },
		knob_NameChar12{ 12, publicParams, privateParams, mophoLaF },
		knob_NameChar13{ 13, publicParams, privateParams, mophoLaF },
		knob_NameChar14{ 14, publicParams, privateParams, mophoLaF },
		knob_NameChar15{ 15, publicParams, privateParams, mophoLaF },
		knob_NameChar16{ 16, publicParams, privateParams, mophoLaF }
	{
		addAndMakeVisible(knob_NameChar01);
		addAndMakeVisible(knob_NameChar02);
		addAndMakeVisible(knob_NameChar03);
		addAndMakeVisible(knob_NameChar04);
		addAndMakeVisible(knob_NameChar05);
		addAndMakeVisible(knob_NameChar06);
		addAndMakeVisible(knob_NameChar07);
		addAndMakeVisible(knob_NameChar08);
		addAndMakeVisible(knob_NameChar09);
		addAndMakeVisible(knob_NameChar10);
		addAndMakeVisible(knob_NameChar11);
		addAndMakeVisible(knob_NameChar12);
		addAndMakeVisible(knob_NameChar13);
		addAndMakeVisible(knob_NameChar14);
		addAndMakeVisible(knob_NameChar15);
		addAndMakeVisible(knob_NameChar16);

		auto section_w{ 230 };
		auto section_h{ 72 };
		setSize(section_w, section_h);
	}

	~ProgramNameSection() {}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 125, 16 };
		g.drawText("PROGRAM NAME", sectionLabelArea, Justification::left);

		// draw LCD background
		g.fillRect(0, 20, 230, 52);
	}

	void resized() override
	{
		auto char_w{ knob_NameChar01.getWidth() };
		auto char_h{ knob_NameChar01.getHeight() };
		auto charGap{ 2 };
		auto char01_x{ 4 };
		auto char02_x{ char01_x + char_w + charGap };
		auto char03_x{ char02_x + char_w + charGap };
		auto char04_x{ char03_x + char_w + charGap };
		auto char05_x{ char04_x + char_w + charGap };
		auto char06_x{ char05_x + char_w + charGap };
		auto char07_x{ char06_x + char_w + charGap };
		auto char08_x{ char07_x + char_w + charGap };
		auto char09_x{ char08_x + char_w + charGap };
		auto char10_x{ char09_x + char_w + charGap };
		auto char11_x{ char10_x + char_w + charGap };
		auto char12_x{ char11_x + char_w + charGap };
		auto char13_x{ char12_x + char_w + charGap };
		auto char14_x{ char13_x + char_w + charGap };
		auto char15_x{ char14_x + char_w + charGap };
		auto char16_x{ char15_x + char_w + charGap };
		auto charRow1_y{ 28 };
		auto charRow2_y{ 48 };
		knob_NameChar01.setBounds(char01_x, charRow2_y, char_w, char_h);
		knob_NameChar02.setBounds(char02_x, charRow2_y, char_w, char_h);
		knob_NameChar03.setBounds(char03_x, charRow2_y, char_w, char_h);
		knob_NameChar04.setBounds(char04_x, charRow2_y, char_w, char_h);
		knob_NameChar05.setBounds(char05_x, charRow2_y, char_w, char_h);
		knob_NameChar06.setBounds(char06_x, charRow2_y, char_w, char_h);
		knob_NameChar07.setBounds(char07_x, charRow2_y, char_w, char_h);
		knob_NameChar08.setBounds(char08_x, charRow2_y, char_w, char_h);
		knob_NameChar09.setBounds(char09_x, charRow2_y, char_w, char_h);
		knob_NameChar10.setBounds(char10_x, charRow2_y, char_w, char_h);
		knob_NameChar11.setBounds(char11_x, charRow2_y, char_w, char_h);
		knob_NameChar12.setBounds(char12_x, charRow2_y, char_w, char_h);
		knob_NameChar13.setBounds(char13_x, charRow2_y, char_w, char_h);
		knob_NameChar14.setBounds(char14_x, charRow2_y, char_w, char_h);
		knob_NameChar15.setBounds(char15_x, charRow2_y, char_w, char_h);
		knob_NameChar16.setBounds(char16_x, charRow2_y, char_w, char_h);
	}

private:
	KnobWidget_PgmNameChar	knob_NameChar01;
	KnobWidget_PgmNameChar	knob_NameChar02;
	KnobWidget_PgmNameChar	knob_NameChar03;
	KnobWidget_PgmNameChar	knob_NameChar04;
	KnobWidget_PgmNameChar	knob_NameChar05;
	KnobWidget_PgmNameChar	knob_NameChar06;
	KnobWidget_PgmNameChar	knob_NameChar07;
	KnobWidget_PgmNameChar	knob_NameChar08;
	KnobWidget_PgmNameChar	knob_NameChar09;
	KnobWidget_PgmNameChar	knob_NameChar10;
	KnobWidget_PgmNameChar	knob_NameChar11;
	KnobWidget_PgmNameChar	knob_NameChar12;
	KnobWidget_PgmNameChar	knob_NameChar13;
	KnobWidget_PgmNameChar	knob_NameChar14;
	KnobWidget_PgmNameChar	knob_NameChar15;
	KnobWidget_PgmNameChar	knob_NameChar16;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramNameSection)
};