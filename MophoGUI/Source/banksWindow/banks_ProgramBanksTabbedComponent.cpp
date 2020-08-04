#include "banks_ProgramBanksTabbedComponent.h"

#include "../helpers/helper_CustomColors.h"



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
