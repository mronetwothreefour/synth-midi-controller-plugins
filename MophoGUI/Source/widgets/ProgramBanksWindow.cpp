#include "ProgramBanksWindow.h"

ProgramSlotsWidget::ProgramSlotsWidget
(
    int pgmBank,
    PrivateParameters* privateParameters
) :
	privateParams{ privateParameters },
	bankNum{ pgmBank }
{
	for (auto i = 0; i != 128; ++i)
	{
		setComponentID("ProgramSlotsWidget");

		addAndMakeVisible(programSlotButtons[i]);
		setNameForProgramSlotButton(i);
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

void ProgramSlotsWidget::setNameForProgramSlotButton(int slot)
{
	String slotNumber;
	if (slot < 10) slotNumber = "00" + (String)(slot + 1);
	if (slot > 9 && slot < 100) slotNumber = "0" + (String)(slot + 1);
	if (slot > 99) slotNumber = (String)(slot + 1);
	programSlotButtons[slot].setName(slotNumber + " " + privateParams->getStoredProgramName(bankNum, slot));
}

//==============================================================================

PushBankThread::PushBankThread
(
	int bankNum,
	PluginProcessor& p,
	PrivateParameters* privateParameters
) :
	ThreadWithProgressWindow{ "Pushing program bank " + (String)(bankNum + 1) + " to Mopho hardware...", true, true, 5000, "STOP" },
	bank{ bankNum },
	processor{ p },
	privateParams{ privateParameters }
{
	setStatusMessage("Preparing to push...");
}

void PushBankThread::run()
{
	setProgress(-1.0); // spinning progress bar
	wait(1000);

	auto numberOfPrograms{ 128 };
	auto transmitTime{ privateParams->getProgramTransmitTime() };

	for (auto i = 0; i < numberOfPrograms; ++i)
	{
		if (threadShouldExit()) return; // check if user has cancelled the push

		setProgress((double)i / numberOfPrograms);
		setStatusMessage("Pushing program " + (String)i);
		processor.sendProgramDump(bank, i);

		wait(transmitTime);
	}
}

void PushBankThread::threadComplete(bool userPressedCancel)
{
	// User interrupted push
	if (userPressedCancel)
	{
		AlertWindow::showMessageBoxAsync(AlertWindow::NoIcon, "Progress window", "You stopped the push");
	}
	else // Push finished normally
	{
		AlertWindow::showMessageBoxAsync(AlertWindow::NoIcon, "Progress window", "All programs pushed");
	}

	// Clean up by deleting the thread object
	delete this;
}


//==============================================================================

ProgramBanksTab::ProgramBanksTab
(
	int pgmBank,
	PluginProcessor& p,
	PrivateParameters* privateParameters
) :
	processor{ p },
	bank{ pgmBank },
	privateParams{ privateParameters },
	programSlots{ bank, privateParams }
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
	button_Load.onClick = [this] { if (programSlots.selectedSlot != -1) processor.loadProgramFromStorage(bank, programSlots.selectedSlot); };
	addAndMakeVisible(button_Load);

	String button_SaveTooltip{ "" };
	if (privateParams->shouldShowInfoTip())
	{
		button_SaveTooltip += "Saves the plugin GUI's current settings\n";
		button_SaveTooltip += "in the selected program storage slot.";
	}
	button_Save.setTooltip(button_SaveTooltip);
	button_Save.setButtonText("SAVE");
	button_Save.onClick = [this] 
		{ 
			if (programSlots.selectedSlot != -1)
			{
				processor.saveProgramToStorage(bank, programSlots.selectedSlot);
				programSlots.setNameForProgramSlotButton(programSlots.selectedSlot);
				repaint();
			}
		};
	addAndMakeVisible(button_Save);

	String button_PushTooltip{ "" };
	if (privateParams->shouldShowInfoTip())
	{
		button_PushTooltip += "Push the data in the selected program storage slot\n";
		button_PushTooltip += "to the corresponding storage slot in the Mopho hardware.";
	}
	button_Push.setTooltip(button_PushTooltip);
	button_Push.setButtonText("PUSH");
	button_Push.onClick = [this] 
		{ 
			if (programSlots.selectedSlot != -1)
			{
				processor.pushProgramToHardwareStorage(bank, programSlots.selectedSlot);
			}
		};
	addAndMakeVisible(button_Push);

	String button_PullTooltip{ "" };
	if (privateParams->shouldShowInfoTip())
	{
		button_PullTooltip += "Pull the data from the selected program storage slot in the Mopho hardware\n";
		button_PullTooltip += "and save it in the corresponding storage slot in the plugin.";
	}
	button_Pull.setTooltip(button_PullTooltip);
	button_Pull.setButtonText("PULL");
	button_Pull.onClick = [this] 
		{ 
			if (programSlots.selectedSlot != -1)
			{
				processor.pullProgramFromHardwareStorage(bank, programSlots.selectedSlot);
				callAfterDelay(300, [this] { programSlots.setNameForProgramSlotButton(programSlots.selectedSlot); programSlots.repaint(); });
			}
		};
	addAndMakeVisible(button_Pull);

	String button_PushBankTooltip{ "" };
	if (privateParams->shouldShowInfoTip())
	{
		button_PushBankTooltip += "Push all the programs stored in this bank to the\n";
		button_PushBankTooltip += "corresponding storage bank in the Mopho hardware.";
	}
	button_PushBank.setTooltip(button_PushBankTooltip);
	button_PushBank.setButtonText("PUSH");
	button_PushBank.onClick = [this] 
		{ 
			(new PushBankThread(bank, processor, privateParams))->launchThread();
		};
	addAndMakeVisible(button_PushBank);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	auto programBanksTab_w{ 1015 };
	auto programBanksTab_h{ 325 };
	setSize(programBanksTab_w, programBanksTab_h);
}

ProgramBanksTab::~ProgramBanksTab()
{
	removeKeyListener(commandManager.getKeyMappings());
}

void ProgramBanksTab::resized()
{
	programSlots.setBounds(10, 10, programSlots.getWidth(), programSlots.getHeight());
	auto button_y{ 294 };
	auto button_w{ 50 };
	auto button_h{ 21 };
	button_Load.setBounds(178, button_y, button_w, button_h);
	button_Save.setBounds(238, button_y, button_w, button_h);
	button_Push.setBounds(298, button_y, button_w, button_h);
	button_Pull.setBounds(358, button_y, button_w, button_h);
	button_PushBank.setBounds(592, button_y, button_w, button_h);
}

void ProgramBanksTab::getAllCommands(Array<CommandID>& commands)
{
	Array<CommandID> ids{ copyProgram, pasteProgram };
	commands.addArray(ids);
}

void ProgramBanksTab::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result)
{
	switch (commandID)
	{
	case copyProgram:
		result.setInfo("Copy Program", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pasteProgram:
		result.setInfo("Paste Program", "Replace the program in the selected storage slot with the program in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool ProgramBanksTab::perform(const InvocationInfo& info)
{
	switch (info.commandID)
	{
	case copyProgram:
		if (programSlots.selectedSlot != -1)
		{
			privateParams->copySelectedProgramToBuffer(bank, programSlots.selectedSlot);
			return true;
		}
		else return false;
	case pasteProgram:
		if (programSlots.selectedSlot != -1)
		{
			privateParams->replaceSelectedProgramWithBuffer(bank, programSlots.selectedSlot);
			programSlots.setNameForProgramSlotButton(programSlots.selectedSlot);
			repaint();
			return true;
		}
		else return false;
	default:
		return false;
	}
}

//==============================================================================

ProgramBanksTabbedComponent::ProgramBanksTabbedComponent
(
	PluginProcessor& p,
	PrivateParameters* privateParameters
) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	bank1{ 0, p, privateParameters },
	bank2{ 1, p, privateParameters },
	bank3{ 2, p, privateParameters }
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
