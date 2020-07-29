#include "banks_ProgramBanksWindow.h"



ProgramBanksTabbedComponent::ProgramBanksTabbedComponent(PluginProcessor& processor) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	bank1{ 0, processor },
	bank2{ 1, processor },
	bank3{ 2, processor }
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


//================================================================================


ProgramBanksWindow::ProgramBanksWindow(PluginProcessor& processor) :
	DialogWindow{ "Program Banks", Color::device, true, false },
	contentComponent{ processor }
{
	contentComponent.setVisible(true);
}

ProgramBanksWindow::~ProgramBanksWindow() {
}

