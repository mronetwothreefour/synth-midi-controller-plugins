#include "banks_ProgramBanksComponent.h"



ProgramBanksTabbedComponent::ProgramBanksTabbedComponent(AudioProcessorValueTreeState* exposedParams) :
	TabbedComponent(TabbedButtonBar::TabsAtTop),
	bank1{ 0, exposedParams },
	bank2{ 1, exposedParams },
	bank3{ 2, exposedParams }
{
	setTabBarDepth(30);
	setOutline(0);
	addTab("Bank 1", Color::device, &bank1, true, 1);
	addTab("Bank 2", Color::device, &bank2, true, 2);
	addTab("Bank 3", Color::device, &bank3, true, 3);
	setColour(backgroundColourId, Color::device.darker(0.25f));
	auto tab_w{ bank1.getWidth() };
	auto tab_h{ bank1.getHeight() };
	setSize(tab_w, tab_h + getTabBarDepth());
}

void ProgramBanksTabbedComponent::labelTextChanged(Label* label) {
}

void ProgramBanksTabbedComponent::editorShown(Label* label, TextEditor& editor) {
}


//================================================================================


void ProgramBanksComponent::hideThisComponent() {
	setVisible(false);
}

ProgramBanksComponent::ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams) :
	tabbedComponent{ exposedParams },
	button_ForClosingProgramBanks{ "CLOSE" }
{
	addAndMakeVisible(tabbedComponent);
	addAndMakeVisible(button_ForClosingProgramBanks);
	button_ForClosingProgramBanks.onClick = [this] { hideThisComponent(); };
	button_ForClosingProgramBanks.setAlwaysOnTop(true);
	setSize(1273, 626);
	auto tabbedComponent_w{ 1065 };
	auto tabbedComponent_h{ 400 };
	auto tabbedComponent_x{ (getWidth() - tabbedComponent_w) / 2 };
	auto tabbedComponent_y{ (getHeight() - tabbedComponent_h) / 2 };
	tabbedComponent.setBounds(tabbedComponent_x, tabbedComponent_y, tabbedComponent_w, tabbedComponent_h);
	button_ForClosingProgramBanks.setBounds(1115, 118, 50, 21);
}

ProgramBanksComponent::~ProgramBanksComponent() {
}

void ProgramBanksComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::black);
	auto componentOutline_w{ 1069 };
	auto componentOutline_h{ 404 };
	auto componentOutline_x{ (getWidth() - componentOutline_w) / 2 };
	auto componentOutline_y{ (getHeight() - componentOutline_h) / 2 };
	Rectangle<int> componentOutline{ componentOutline_x, componentOutline_y, componentOutline_w, componentOutline_h };
	g.fillRect(componentOutline);
}
