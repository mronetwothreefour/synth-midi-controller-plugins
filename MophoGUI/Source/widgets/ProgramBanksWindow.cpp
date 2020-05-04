#include "ProgramBanksWindow.h"

ProgramSlotsWidget::ProgramSlotsWidget
(
    int pgmBank,
    PrivateParameters* privateParameters,
    MophoLookAndFeel* mophoLaF
) :
	privateParams{ privateParameters }
{
	String bankLetter;
	switch (pgmBank)
	{
	case PrivateParameters::programBank::A: bankLetter = "A"; break;
	case PrivateParameters::programBank::B: bankLetter = "B"; break;
	case PrivateParameters::programBank::C: bankLetter = "C"; break;
	default: bankLetter = "error"; break;
	}
	for (auto i = 0; i != 128; ++i)
	{
		setComponentID("ProgramSlotsWidget");

		addAndMakeVisible(programSlotButtons[i]);
		String slotNumber;
		if (i < 10) slotNumber = "00" + (String)i;
		if (i > 9 && i < 100) slotNumber = "0" + (String)i;
		if (i > 99) slotNumber = (String)i;
		programSlotButtons[i].setName(bankLetter + slotNumber + " " + privateParameters->getStoredProgramName(pgmBank, i));
		programSlotButtons[i].setLookAndFeel(mophoLaF);
		programSlotButtons[i].setComponentID(ID::pgmSlotToggle.toString());
		programSlotButtons[i].setRadioGroupId(1);
	}

	auto programSlotsWidget_w{ 8 * buttton_w + 7 * buttonGap };
	auto programSlotsWidget_h{ 16 * buttton_h };
	setSize(programSlotsWidget_w, programSlotsWidget_h);
}

ProgramSlotsWidget::~ProgramSlotsWidget()
{
	for (auto i = 0; i != 128; ++i)
	{
		programSlotButtons[i].setLookAndFeel(nullptr);
	}
}

void ProgramSlotsWidget::resized()
{
	for (auto i = 0; i != 128; ++i)
	{
		auto col_x{(i / 16) * (buttton_w + buttonGap) };
		auto row_y{ (i % 16) * buttton_h };
		programSlotButtons[i].setBounds(col_x, row_y, buttton_w, buttton_h);
	}
}

//==============================================================================

ProgramBanksTab::ProgramBanksTab
(
	int pgmBank,
	PluginProcessor& p,
	PrivateParameters* privateParameters,
	MophoLookAndFeel* mophoLaF
) :
	bank{ pgmBank },
	privateParams{ privateParameters },
	programSlots{ bank, privateParams, mophoLaF }
{
	setComponentID("ProgramBanksTab");

	addAndMakeVisible(programSlots);

	auto programBanksTab_w{ 1015 };
	auto programBanksTab_h{ 320 };
	setSize(programBanksTab_w, programBanksTab_h);
}

ProgramBanksTab::~ProgramBanksTab()
{
}

void ProgramBanksTab::resized()
{
	programSlots.setBounds(10, 10, programSlots.getWidth(), programSlots.getHeight());
}

//==============================================================================

ProgramBanksTabbedComponent::ProgramBanksTabbedComponent
(
	PluginProcessor& p,
	PrivateParameters* privateParameters,
	MophoLookAndFeel* mophoLaF
) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	bankA{ PrivateParameters::programBank::A, p, privateParameters, mophoLaF },
	bankB{ PrivateParameters::programBank::B, p, privateParameters, mophoLaF },
	bankC{ PrivateParameters::programBank::C, p, privateParameters, mophoLaF }
{
	setTabBarDepth(30);
	setOutline(0);
	addTab("A", Color::device, &bankA, true, 1);
	addTab("B", Color::device, &bankB, true, 2);
	addTab("C", Color::device, &bankC, true, 3);

	auto tab_w{ 1015 };
	auto tab_h{ 320 };
	setSize(tab_w + getTabBarDepth(), tab_h);
}
