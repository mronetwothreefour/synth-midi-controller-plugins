#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/KnobWidgets.h"
#include "../widgets/LCDcharacterRenderer.h"

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
		addAndMakeVisible(pgmBankAndSlotChar01);
		addAndMakeVisible(pgmBankAndSlotChar02);
		addAndMakeVisible(pgmBankAndSlotChar03);
		addAndMakeVisible(pgmBankAndSlotChar04);
		addAndMakeVisible(pgmBankAndSlotChar05);
		addAndMakeVisible(pgmBankAndSlotChar06);
		addAndMakeVisible(pgmBankAndSlotChar07);
		addAndMakeVisible(pgmBankAndSlotChar08);
		addAndMakeVisible(pgmBankAndSlotChar09);
		addAndMakeVisible(pgmBankAndSlotChar10);
		addAndMakeVisible(pgmBankAndSlotChar11);
		addAndMakeVisible(pgmBankAndSlotChar12);
		addAndMakeVisible(pgmBankAndSlotChar13);
		addAndMakeVisible(pgmBankAndSlotChar14);
		addAndMakeVisible(pgmBankAndSlotChar15);
		addAndMakeVisible(pgmBankAndSlotChar16);

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

		// "Edit Buffer"
		drawPgmBankAndSlot(69, 100, 105, 116, 32, 66, 117, 102, 102, 101, 114, 32, 32, 32, 32, 32);

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
		auto charRow1_y{ 27 };
		auto charRow2_y{ 49 };

		pgmBankAndSlotChar01.setBounds(char01_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar02.setBounds(char02_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar03.setBounds(char03_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar04.setBounds(char04_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar05.setBounds(char05_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar06.setBounds(char06_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar07.setBounds(char07_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar08.setBounds(char08_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar09.setBounds(char09_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar10.setBounds(char10_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar11.setBounds(char11_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar12.setBounds(char12_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar13.setBounds(char13_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar14.setBounds(char14_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar15.setBounds(char15_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar16.setBounds(char16_x, charRow1_y, char_w, char_h);

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

	void drawPgmBankAndSlot
	(
		int char01, int char02, int char03, int char04,
		int char05, int char06, int char07, int char08,
		int char09, int char10, int char11, int char12,
		int char13, int char14, int char15, int char16
	)
	{
		pgmBankAndSlotChar01.drawChar(char01);
		pgmBankAndSlotChar02.drawChar(char02);
		pgmBankAndSlotChar03.drawChar(char03);
		pgmBankAndSlotChar04.drawChar(char04);
		pgmBankAndSlotChar05.drawChar(char05);
		pgmBankAndSlotChar06.drawChar(char06);
		pgmBankAndSlotChar07.drawChar(char07);
		pgmBankAndSlotChar08.drawChar(char08);
		pgmBankAndSlotChar09.drawChar(char09);
		pgmBankAndSlotChar10.drawChar(char10);
		pgmBankAndSlotChar11.drawChar(char11);
		pgmBankAndSlotChar12.drawChar(char12);
		pgmBankAndSlotChar13.drawChar(char13);
		pgmBankAndSlotChar14.drawChar(char14);
		pgmBankAndSlotChar15.drawChar(char15);
		pgmBankAndSlotChar16.drawChar(char16);
	}

private:
	LCDcharacterRenderer pgmBankAndSlotChar01;
	LCDcharacterRenderer pgmBankAndSlotChar02;
	LCDcharacterRenderer pgmBankAndSlotChar03;
	LCDcharacterRenderer pgmBankAndSlotChar04;
	LCDcharacterRenderer pgmBankAndSlotChar05;
	LCDcharacterRenderer pgmBankAndSlotChar06;
	LCDcharacterRenderer pgmBankAndSlotChar07;
	LCDcharacterRenderer pgmBankAndSlotChar08;
	LCDcharacterRenderer pgmBankAndSlotChar09;
	LCDcharacterRenderer pgmBankAndSlotChar10;
	LCDcharacterRenderer pgmBankAndSlotChar11;
	LCDcharacterRenderer pgmBankAndSlotChar12;
	LCDcharacterRenderer pgmBankAndSlotChar13;
	LCDcharacterRenderer pgmBankAndSlotChar14;
	LCDcharacterRenderer pgmBankAndSlotChar15;
	LCDcharacterRenderer pgmBankAndSlotChar16;

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