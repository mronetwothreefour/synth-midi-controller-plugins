#include "banks_TabbedComponentForAllProgramBanks.h"

#include "../gui/gui_Colors.h"
#include "../params/params_Identifiers.h"



TabbedComponentForAllProgramBanks::TabbedComponentForAllProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	TabbedComponent(TabbedButtonBar::TabsAtTop),
	unexposedParams{ unexposedParams },
	tabbedComponentForCustomProgramBanks{ exposedParams, unexposedParams, programCopyBuffer },
	tabbedComponentForFactoryProgramBanks{ exposedParams, unexposedParams, programCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForAllBanks.toString());
	setTabBarDepth(30);
	setOutline(0);
	addTab("FACTORY   BANKS", Color::device, &tabbedComponentForFactoryProgramBanks, true, 1);
	addTab("CUSTOM   BANKS", Color::device, &tabbedComponentForCustomProgramBanks, true, 1);
	setColour(backgroundColourId, Color::device.darker(0.25f));
	auto tab_w{ tabbedComponentForFactoryProgramBanks.getWidth() };
	auto tab_h{ tabbedComponentForFactoryProgramBanks.getHeight() };
	setSize(tab_w + getTabBarDepth(), tab_h);
}

TabForCustomProgramBank* TabbedComponentForAllProgramBanks::getCurrentCustomProgramBankTab() {
	return tabbedComponentForCustomProgramBanks.getCurrentProgramBankTab();
}

TabForFactoryProgramBank* TabbedComponentForAllProgramBanks::getCurrentFactoryProgramBankTab() {
	return tabbedComponentForFactoryProgramBanks.getCurrentProgramBankTab();
}

void TabbedComponentForAllProgramBanks::updateTextForAllProgramSlotsInAllBanks()
{
}
