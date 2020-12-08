#include "banks_TabbedComponentForFactoryProgramBanks.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



TabbedComponentForFactoryProgramBanks::TabbedComponentForFactoryProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
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

	auto tooltips{ unexposedParams->tooltipOptions_get() };
	String label_txTimeTooltip{ "" };
	if (tooltips->shouldShowDescription()) {
		label_txTimeTooltip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		label_txTimeTooltip += "of a single program between the plugin and the Mopho hardware. Increase\n";
		label_txTimeTooltip += "this value if programs are getting 'lost' during pushes or pulls.\n";
		label_txTimeTooltip += "Minimum time: 50 ms. Maximum time 5000 ms.";
	}
	label_txTime.setTooltip(label_txTimeTooltip);
	label_txTime.addListener(this);
	label_txTime.setComponentID(ID::component_EditLabel.toString());
	label_txTime.setEditable(true);
	labelTextChanged(&label_txTime);
	addAndMakeVisible(label_txTime);

	auto control_y{ 334 };
	auto control_w{ 50 };
	auto control_h{ 21 };
	label_txTime.setBounds(1030, control_y, control_w, control_h);
}

void TabbedComponentForFactoryProgramBanks::editorShown(Label* label, TextEditor& editor) {
	if (label == &label_txTime) {
		editor.setInputRestrictions(4, "0123456789");
		auto midiOptions{ unexposedParams->midiOptions_get() };
		editor.setFont(FontsMenu::fontFor_Labels);
		editor.setText((String)midiOptions->programTransmitTime());
		editor.selectAll();
	}
}

void TabbedComponentForFactoryProgramBanks::labelTextChanged(Label* label) {
	if (label == &label_txTime) {
		auto midiOptions{ unexposedParams->midiOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue > 49 && newValue < 5001)
				midiOptions->setProgramTransmitTime(newValue);
		}
		label->setText((String)midiOptions->programTransmitTime() + " ms", dontSendNotification);
	}
}

TabForFactoryProgramBank* TabbedComponentForFactoryProgramBanks::getCurrentProgramBankTab() {
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

void TabbedComponentForFactoryProgramBanks::updateTextForAllProgramSlotsInAllBanks() {
}

