#include "banks_TabbedComponentForCustomProgramBanks.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



TabbedComponentForCustomProgramBanks::TabbedComponentForCustomProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	unexposedParams{ unexposedParams },
	bank1{ 0, exposedParams, unexposedParams, programCopyBuffer },
	bank2{ 1, exposedParams, unexposedParams, programCopyBuffer },
	bank3{ 2, exposedParams, unexposedParams, programCopyBuffer }
{
	setTabBarDepth(30);
	setOutline(0);
	addTab("1", Color::device, &bank1, true, 1);
	addTab("2", Color::device, &bank2, true, 2);
	addTab("3", Color::device, &bank3, true, 3);
	setColour(backgroundColourId, Color::device.darker(0.25f));
	auto tab_w{ bank1.getWidth() };
	auto tab_h{ bank1.getHeight() };
	setSize(tab_w + getTabBarDepth(), tab_h);
}

TabForCustomProgramBank* TabbedComponentForCustomProgramBanks::getCurrentProgramBankTab() {
	switch (getCurrentTabIndex())
	{
	case 0:
		return &bank1;
	case 1:
		return &bank2;
	case 2:
		return &bank3;
	default:
		return nullptr;
	}
}

void TabbedComponentForCustomProgramBanks::updateTextForAllProgramSlotsInAllBanks() {
	auto programBanks{ unexposedParams->programBanks_get() };
	for (uint8 slot = 0; slot != programBanks->programSlotOutOfRange(); ++slot) {
		bank1.updateCustomProgramSlotText(slot);
		bank2.updateCustomProgramSlotText(slot);
		bank3.updateCustomProgramSlotText(slot);
	}
}

