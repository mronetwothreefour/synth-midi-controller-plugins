#include "ProgramBanksWindow.h"

ProgramSlotsWidget::ProgramSlotsWidget
(
    int pgmBank,
    PrivateParameters* privateParameters,
    MophoLookAndFeel* mophoLaF
) :
	privateParams{ privateParameters }
{
	for (auto i = 0; i != 128; ++i)
	{
		setComponentID("ProgramSlotsWidget");

		addAndMakeVisible(programSlotButtons[i]);
		String slotNumber;
		if (i < 10) slotNumber = "00" + (String)i;
		if (i > 9 && i < 100) slotNumber = "0" + (String)i;
		if (i > 99) slotNumber = (String)i;
		programSlotButtons[i].setName(slotNumber + " " + privateParameters->getStoredProgramName(pgmBank, i));
		programSlotButtons[i].setLookAndFeel(mophoLaF);
		programSlotButtons[i].setComponentID(ID::pgmSlotToggle.toString());
		programSlotButtons[i].setRadioGroupId(1);
		programSlotButtons[i].onClick = [this, i] {selectedSlot = i; };
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
	processor{ p },
	bank{ pgmBank },
	privateParams{ privateParameters },
	programSlots{ bank, privateParams, mophoLaF }
{
	setComponentID("ProgramBanksTab");

	addAndMakeVisible(programSlots);

	String button_LoadTooltip{ "" };
	if (privateParams->shouldShowInfoTip())
	{
		button_LoadTooltip += "Applies the program settings stored in the selected slot to the\n";
		button_LoadTooltip += "plugin GUI and to the Mopho hardware's program edit buffer.";
	}
	button_Load.setTooltip(button_LoadTooltip);
	button_Load.setButtonText("LOAD");
	button_Load.setLookAndFeel(mophoLaF);
	button_Load.onClick = [this] { if (programSlots.selectedSlot != -1) processor.loadProgramFromStorage(bank, programSlots.selectedSlot); };
	addAndMakeVisible(button_Load);

	auto programBanksTab_w{ 1015 };
	auto programBanksTab_h{ 325 };
	setSize(programBanksTab_w, programBanksTab_h);
}

ProgramBanksTab::~ProgramBanksTab()
{
}

void ProgramBanksTab::resized()
{
	programSlots.setBounds(10, 10, programSlots.getWidth(), programSlots.getHeight());
	auto button_y{ 294 };
	auto button_w{ 50 };
	auto button_h{ 21 };
	button_Load.setBounds(208, button_y, button_w, button_h);
}

//==============================================================================

ProgramBanksTabbedComponent::ProgramBanksTabbedComponent
(
	PluginProcessor& p,
	PrivateParameters* privateParameters,
	MophoLookAndFeel* mophoLaF
) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	bank1{ 1, p, privateParameters, mophoLaF },
	bank2{ 2, p, privateParameters, mophoLaF },
	bank3{ 3, p, privateParameters, mophoLaF }
{
	setTabBarDepth(30);
	setOutline(0);
	addTab("1", Color::device, &bank1, true, 1);
	addTab("2", Color::device, &bank2, true, 2);
	addTab("3", Color::device, &bank3, true, 3);

	auto tab_w{ 1015 };
	auto tab_h{ 325 };
	setSize(tab_w + getTabBarDepth(), tab_h);
}
